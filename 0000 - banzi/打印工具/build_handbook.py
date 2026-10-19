"""合并六份板子，使用 Pandoc、Typst 和 PyMuPDF 生成打印版。

依赖：pypandoc_binary、typst、pymupdf。字体目录可由 HANDBOOK_FONTS 指定。
"""

from pathlib import Path
import copy
import hashlib
import json
import os
import re
import subprocess
from urllib.parse import unquote

import pypandoc
import pymupdf
import typst


BASE = Path(__file__).resolve().parents[1]
BUILD = Path(os.environ.get("HANDBOOK_BUILD", "/tmp/acm-handbook"))
BUILD.mkdir(parents=True, exist_ok=True)
FONTS = Path(os.environ.get("HANDBOOK_FONTS", "/mnt/c/Windows/Fonts"))
SOURCES = [
    ("竞赛基础板子_打印版.md", "竞赛基础"),
    ("数据结构板子.md", "数据结构"),
    ("图论板子.md", "图论"),
    ("字符串板子.md", "字符串"),
    ("数学板子.md", "数学"),
    ("杂项板子.md", "杂项"),
]
CHAPTER_ORDER = (5, 4, 2, 3, 6, 1)
PDF = BASE / "竞赛板子合集_打印版.pdf"
MERGED = BASE / "竞赛板子合集.md"
PANDOC = pypandoc.get_pandoc_path()
READER = "markdown-smart+tex_math_single_backslash"


def pandoc(text, fmt, to):
    p = subprocess.run(
        [PANDOC, "-f", fmt, "-t", to, "--wrap=none"],
        input=text, text=True, capture_output=True, check=True,
    )
    if p.stderr:
        print(p.stderr)
        if "[WARNING]" in p.stderr:
            raise RuntimeError("Pandoc conversion warning; inspect before printing")
    return p.stdout


def nodes(obj):
    if isinstance(obj, dict):
        if "t" in obj:
            yield obj
        for value in obj.values():
            yield from nodes(value)
    elif isinstance(obj, list):
        for value in obj:
            yield from nodes(value)


def plain(obj):
    out = []
    for n in nodes(obj):
        if n["t"] in ("Str", "Code", "Math"):
            out.append(n["c"] if n["t"] == "Str" else n["c"][-1])
        elif n["t"] in ("Space", "SoftBreak"):
            out.append(" ")
    return "".join(out)


hashes = {}
hashes["积分表.pdf"] = hashlib.sha256((BASE / "积分表.pdf").read_bytes()).hexdigest()
aliases = {}
parts = []
headings = []
source_code = []
source_images = {}
for part, (filename, title) in enumerate(SOURCES, 1):
    src = BASE / filename
    data = src.read_bytes()
    hashes[filename] = hashlib.sha256(data).hexdigest()
    text = data.decode()
    output = [f"# {title} {{#part-{part}}}", ""]
    pending = []
    skipped_toc = False
    fence = False
    count = 0
    for line in text.splitlines():
        if line.startswith("```"):
            fence = not fence
            if not skipped_toc:
                output.append(line)
            continue
        if not fence:
            anchor = re.fullmatch(r'<a id="([^"]+)"></a>\s*', line)
            if anchor:
                pending.append(anchor[1])
                continue
            h = re.match(r"^(#{1,6}) (.*)$", line)
            if h:
                level, label = len(h[1]), h[2]
                if level == 1:
                    continue
                if level == 2 and label == "目录":
                    skipped_toc = True
                    continue
                skipped_toc = False
                count += 1
                ident = f"p{part}-{pending[0]}" if pending else f"p{part}-h{count}"
                for alias in pending:
                    aliases[(part, alias)] = ident
                pending = []
                label = re.sub(r"^\d+(?:\.\d+)*(?:[.、]|\s)\s*", "", label)
                if label == "二维计算几何my":
                    label = "二维计算几何"
                if label in ("数论板子", "组合数学板子", "多项式板子"):
                    label = label.removesuffix("板子")
                headings.append({"part": part, "level": level, "title": label, "id": ident})
                output.append(f"{h[1]} {label} {{#{ident}}}")
                continue
        if not skipped_toc:
            output.append(line)
    clean = "\n".join(output) + "\n"
    # Empty lines are required before Markdown tables in several original notes.
    clean = re.sub(r"([^\n|])\n(?=\|[^\n]*\|\n\|[ :|-]+\|)", r"\1\n\n", clean)
    doc = json.loads(pandoc(clean, READER, "json"))
    original_without_anchors = re.sub(r'^<a id="[^"]+"></a>\s*\n', '', text, flags=re.M)
    original_doc = json.loads(pandoc(original_without_anchors, READER, "json"))
    original_headers = [n for n in nodes(original_doc) if n["t"] == "Header" and n["c"][0] > 1 and plain(n["c"][2]) != "目录"]
    new_headers = [n for n in nodes(doc) if n["t"] == "Header" and n["c"][0] > 1]
    assert len(original_headers) == len(new_headers), filename
    for old, new in zip(original_headers, new_headers):
        aliases[(part, old["c"][1][0])] = new["c"][1][0]
    # Preserve multi-line displayed TeX equations as aligned math.
    for n in nodes(doc):
        if n["t"] == "Math" and n["c"][0]["t"] == "DisplayMath":
            math = n["c"][1]
            if "\\\\" in math and not re.search(r"\\begin\{", math):
                n["c"][1] = "\\begin{aligned}" + math + "\\end{aligned}"
        if n["t"] == "CodeBlock":
            if "mermaid" in n["c"][0][1]:
                raise RuntimeError(f"{filename}: Mermaid 图示尚未生成本地图片")
            source_code.append(n["c"][1])
        if n["t"] == "Image":
            target = n["c"][-1][0]
            image_path = BASE / unquote(target)
            if not image_path.is_file():
                raise FileNotFoundError(f"{filename}: 图片缺失 {target}")
            with pymupdf.open(image_path) as picture:
                assert picture[0].rect.width > 0 and picture[0].rect.height > 0
            source_images[target] = hashlib.sha256(image_path.read_bytes()).hexdigest()
    parts.append(doc)


# Turn standalone subsection labels into headings for direct lookup.
promote_parents = {
    "p1-algorithm", "p1-iterator", "p1-math", "p1-floating-point",
    "p3-cycle-detection", "p3-tarjan",
}
promoted = []
for part, doc in enumerate(parts, 1):
    parent = ""
    counts = {}
    dsu_code_count = 0
    rewritten = []
    for block in doc["blocks"]:
        if block["t"] == "Header" and block["c"][0] <= 2:
            parent = block["c"][1][0]
        if (parent in promote_parents and block["t"] == "Para"
                and len(block["c"]) == 1 and block["c"][0]["t"] == "Strong"):
            label = plain(block["c"][0]["c"])
            if parent != "p3-tarjan" or label != "DFS 序与 low":
                counts[parent] = counts.get(parent, 0) + 1
                ident = f"{parent}-sub-{counts[parent]}"
                block = {"t": "Header", "c": [3, [ident, [], []], block["c"][0]["c"]]}
                promoted.append(ident)
        if parent == "p2-dsu" and block["t"] == "CodeBlock":
            dsu_code_count += 1
            label, ident = (
                ("普通并查集", "p2-dsu-normal") if dsu_code_count == 1
                else ("可撤销并查集", "p2-dsu-rollback")
            )
            rewritten.append({"t": "Header", "c": [3, [ident, [], []], [{"t": "Str", "c": label}]]})
        rewritten.append(block)
    doc["blocks"] = rewritten

# Include independent templates in the printed contents, omitting tutorial steps.
detail_ids = set(promoted)
detail_ids.update({
    "p2-dsu-normal", "p2-dsu-rollback",
    "p2-h11", "p2-h14", "p2-h15", "p2-h16", "p2-h17", "p2-h18",
    "p2-h38", "p2-h41", "p2-h58", "p2-h62", "p2-h79", "p2-h85",
    "p2-h106", "p2-h114", "p2-h115", "p2-h116", "p2-h120", "p2-h126", "p2-h131", "p2-h134",
    "p2-h142", "p2-h145",
    "p3-h18", "p3-h19", "p3-h28", "p3-h29",
    "p3-h32", "p3-h33", "p3-h34", "p3-h39", "p3-h41", "p3-h42",
    "p3-h67", "p3-h68", "p3-h72", "p3-h73", "p3-h78", "p3-h81", "p3-h92", "p3-h93",
    "p4-h4", "p4-h9",
    "p5-h2", "p5-h3", "p5-h4", "p5-h5", "p5-h6", "p5-h7", "p5-h8", "p5-h9", "p5-h10", "p5-h11", "p5-h12", "p5-h13",
    "p5-h17", "p5-h29", "p5-h31", "p5-h32", "p5-h33", "p5-h34", "p5-h39", "p5-h41",
    "p5-h43", "p5-h44", "p5-h45", "p5-h46", "p5-h47", "p5-h52", "p5-h53", "p5-h54", "p5-h55",
    "p6-h3", "p6-h9", "p6-h18", "p6-h21", "p6-h30", "p6-h32",
})
detail_ids.update(
    n["c"][1][0] for n in nodes(parts[0])
    if n["t"] == "Header" and n["c"][0] == 3 and n["c"][1][0].startswith("p1-")
)
detail_ids.add("p5-fwt")
all_header_ids = {n["c"][1][0] for doc in parts for n in nodes(doc) if n["t"] == "Header"}
assert detail_ids <= all_header_ids, detail_ids - all_header_ids
(BUILD / "toc-details.json").write_text(json.dumps(sorted(detail_ids)))

# Internal links use unique identifiers across all six original documents.
files_to_ids = {filename: f"part-{i}" for i, (filename, _) in enumerate(SOURCES, 1)}
for h in headings:
    if h["level"] == 2:
        files_to_ids.setdefault(h["title"] + ".md", h["id"])
for filename, identifier in {
    "线段树.md": "p2-segment-tree",
    "可持久化线段树.md": "p2-persistent-segment-tree",
    "线段树合并与分裂.md": "p2-segment-tree-merge-split",
    "树链剖分 .md": "p2-hld",
    "Kruskal 重构树+树上倍增 .md": "p2-kruskal-tree",
    "dsu_on_tree.md": "p2-dsu-on-tree",
    "区间最值操作与历史最值.md": "p2-segment-tree-beats",
    "ST表 .md": "p2-sparse-table",
    "kmp.md": "p4-kmp",
    "hash.md": "p4-hash",
    "z函数.md": "p4-z-function",
    "AC自动机.md": "p4-aho-corasick",
    "dinic.md": "p3-dinic",
    "tarjan.md": "p3-tarjan",
    "找环.md": "p3-cycle-detection",
    "dij.md": "p3-dijkstra",
    "spfa判负环.md": "p3-spfa-negative-cycle",
    "prefur序列.md": "p3-prufer",
    "欧拉回路欧拉路径.md": "p3-euler",
    "数论板子.md": "p5-number-theory",
    "组合数学板子.md": "p5-combinatorics",
    "多项式板子.md": "p5-polynomial",
    "FWT.md": "p5-fwt",
    "二维计算几何my.md": "p5-geometry",
}.items():
    files_to_ids[filename] = identifier

all_ids = {n["c"][1][0] for doc in parts for n in nodes(doc) if n["t"] == "Header"}
for part, doc in enumerate(parts, 1):
    for n in nodes(doc):
        if n["t"] == "Link":
            target = n["c"][-1][0]
            if target.startswith("#"):
                alias = target[1:]
                identifier = aliases.get((part, alias))
                if identifier is None:
                    candidates = [value for (p, key), value in aliases.items() if key == alias]
                    if len(candidates) == 1:
                        identifier = candidates[0]
                if identifier:
                    n["c"][-1][0] = "#" + identifier
            elif not re.match(r"[a-z]+:", target):
                filename = Path(unquote(target).split("#")[0]).name
                identifier = files_to_ids.get(filename)
                if identifier and identifier in all_ids:
                    n["c"][-1][0] = "#" + identifier

ordered_parts = [parts[index - 1] for index in CHAPTER_ORDER]
merged = copy.deepcopy(ordered_parts[0])
merged["blocks"] = [block for doc in ordered_parts for block in doc["blocks"]]
MERGED.write_text(
    '---\ntitle: "XCPC 竞赛板子合集"\nlang: zh-CN\n---\n\n'
    + '**总目录**\n\n'
    + '\n'.join(f'{number}. [{SOURCES[part - 1][1]}](#part-{part})' for number, part in enumerate(CHAPTER_ORDER, 1))
    + '\n7. [附录 积分表](#integral-table)\n\n'
    + pandoc(json.dumps(merged), "json", "markdown-smart")
    + '\n# 附录 积分表 {#integral-table}\n\n[导数与积分速查表](积分表.pdf)\n',
)

# The PDF copy gets balanced table widths and absolute image paths.
pdf_doc = copy.deepcopy(merged)
for n in nodes(pdf_doc):
    if n["t"] == "Math":
        n["c"][1] = n["c"][1].replace(r"\mathbin{\text{apply}}", r"\mathbin{\mathrm{apply}}")
    if n["t"] == "Image":
        n["c"][-1][0] = str(BASE / unquote(n["c"][-1][0]))
    if n["t"] == "Table":
        specs = n["c"][2]
        if len(specs) == 3:
            label = plain(n["c"][3])
            if "时间" in label:
                weights = [0.42, 0.42, 0.16]
            elif "查询" in label or "需求" in label:
                weights = [0.28, 0.48, 0.24]
            else:
                weights = [0.27, 0.34, 0.39]
        elif len(specs) == 2:
            weights = [0.43, 0.57]
        else:
            weights = [1 / len(specs)] * len(specs)
        for spec, weight in zip(specs, weights):
            spec[1] = {"t": "ColWidth", "c": weight}

body = pandoc(json.dumps(pdf_doc), "json", "typst")
body = body.replace("#horizontalrule", "#line(length: 100%, stroke: 0.25pt + luma(65%))")
(BUILD / "body.typ").write_text(body)
(BUILD / "document.json").write_text(json.dumps(pdf_doc, ensure_ascii=False))
layout = Path(__file__).with_name("layout.typ").read_text()
(BUILD / "layout.typ").write_text(layout)
(BUILD / "assets").mkdir(exist_ok=True)
(BUILD / "assets" / "cover-rin.png").write_bytes(
    Path(__file__).with_name("assets").joinpath("cover-rin.png").read_bytes()
)
compiled, warnings = typst.compile_with_warnings(
    str(BUILD / "layout.typ"), root="/", font_paths=[str(FONTS)],
)
if warnings:
    print("Typst warnings:", warnings)
(BUILD / "body.pdf").write_bytes(compiled)

doc = pymupdf.open(BUILD / "body.pdf")
table = pymupdf.open(BASE / "积分表.pdf")
assert len(table) == 1
# Remove the source sheet's old page numbers and chapter title on a temporary copy.
page = table[0]
for rect in [(0, 0, 842, 31), (0, 569, 842, 596), (34, 36, 150, 73)]:
    page.add_redact_annot(pymupdf.Rect(rect), fill=(1, 1, 1))
page.apply_redactions(images=0, graphics=0)
columns = [
    pymupdf.Rect(36, 75, 299.5, 558),
    pymupdf.Rect(299.5, 32, 562.5, 558),
    pymupdf.Rect(562.5, 32, 818, 558),
]
for index, clip in enumerate(columns):
    appendix = doc[len(doc) - 3 + index]
    assert appendix.rect.width < appendix.rect.height
    appendix.show_pdf_page(
        pymupdf.Rect(43, 85, appendix.rect.width - 43, appendix.rect.height - 48),
        table, 0, clip=clip, keep_proportion=True,
    )
doc.set_metadata({
    "title": "XCPC 竞赛板子合集 打印版",
    "subject": "数学、字符串、数据结构、图论、杂项、竞赛基础与积分表",
    "creator": "Pandoc / Typst / PyMuPDF",
})
temporary_pdf = BUILD / "complete.pdf"
doc.save(temporary_pdf, garbage=4, deflate=True)
doc.close()
staged_pdf = PDF.with_suffix(".pending.pdf")
staged_pdf.write_bytes(temporary_pdf.read_bytes())
staged_pdf.replace(PDF)
for filename, sha in hashes.items():
    assert hashlib.sha256((BASE / filename).read_bytes()).hexdigest() == sha
report = {
    "sources": hashes,
    "appendix": "积分表.pdf",
    "excluded": ["动态规划目录及 DP 优化教程 PDF"],
    "code_blocks": len(source_code),
    "images": source_images,
    "chapter_order": [SOURCES[i - 1][1] for i in CHAPTER_ORDER],
    "printed_detail_ids": sorted(detail_ids),
    "headings": headings,
    "pdf": str(PDF),
}
(BUILD / "manifest.json").write_text(json.dumps(report, ensure_ascii=False, indent=2))
(BUILD / "code-blocks.json").write_text(json.dumps(source_code, ensure_ascii=False))
with pymupdf.open(PDF) as final:
    print(f"Built {PDF} ({len(final)} pages, {len(source_code)} code blocks)")
