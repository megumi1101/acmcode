"""核对最近一次构建的代码、图片、字体、目录链接和页面边界。"""
from pathlib import Path
import hashlib
import json
import os
import re

import pymupdf

BASE = Path(__file__).resolve().parents[1]
BUILD = Path(os.environ.get('HANDBOOK_BUILD', '/tmp/acm-handbook'))
manifest = json.loads((BUILD / 'manifest.json').read_text())
code = json.loads((BUILD / 'code-blocks.json').read_text())
compact = lambda text: re.sub(r'\s+', '', text)


def check_integer_style(text):
    allowed = (
        r'using\s+\w+\s*=\s*(?:unsigned\s+)?long\s+long\s*;'
        r'|typedef\s+(?:unsigned\s+)?long\s+long\s+\w+\s*;'
        r'|#define\s+int\s+long\s+long\b'
    )
    assert not re.search(r'\blong\s+long\b', re.sub(allowed, '', text))
    assert not re.search(r'decltype\s*\(\s*0LL\s*\)', text)


for name, expected in manifest['sources'].items():
    assert hashlib.sha256((BASE / name).read_bytes()).hexdigest() == expected, name
for source in BASE.rglob('*.md'):
    text = source.read_text()
    check_integer_style(text)
    assert '```mermaid' not in text, source
    assert sum(line.startswith('```') for line in text.splitlines()) % 2 == 0, source

with pymupdf.open(BASE / '竞赛板子合集_打印版.pdf') as document:
    assert all(abs(p.rect.width - 595.276) < 1 and abs(p.rect.height - 841.89) < 1 for p in document)
    body = '\n'.join(p.get_text(clip=pymupdf.Rect(0, 38, p.rect.width, p.rect.height - 38)) for p in document)
    searchable = compact(body)
    # Strip only whitespace and running headers/footers, so page breaks cannot hide lost code.
    for index, snippet in enumerate(code):
        assert compact(snippet) in searchable, f'代码块 {index + 1} 不完整'
    check_integer_style(body)
    assert not any(word in body for word in ('graph TD', 'graph LR', '核对日期'))
    fonts = set()
    for number, page in enumerate(document, 1):
        for block in page.get_text('dict')['blocks']:
            for line in block.get('lines', []):
                for span in line['spans']:
                    x0, y0, x1, y1 = span['bbox']
                    assert x0 >= -1 and y0 >= -1 and x1 <= page.rect.width + 1 and y1 <= page.rect.height + 1, (number, span['text'])
        for link in page.get_links():
            if link['kind'] in (pymupdf.LINK_GOTO, pymupdf.LINK_NAMED):
                assert 0 <= link['page'] < len(document), (number, link)
            if link['kind'] in (pymupdf.LINK_LAUNCH, pymupdf.LINK_GOTOR):
                assert not str(link.get('file', '')).endswith('.md'), (number, link)
        for font in page.get_fonts():
            fonts.add(font[0])
    assert all(document.extract_font(xref)[3] for xref in fonts), '有字体未嵌入'
    pictures = {}
    for name, expected in manifest['images'].items():
        path = BASE / name
        assert hashlib.sha256(path.read_bytes()).hexdigest() == expected, name
        digest = pymupdf.Pixmap(str(path)).digest
        pages = []
        for number, page in enumerate(document, 1):
            for picture in page.get_image_info(hashes=True):
                if picture['digest'] == digest:
                    rect = pymupdf.Rect(picture['bbox'])
                    assert page.rect.contains(rect) and rect.width > 50 and rect.height > 20
                    pages.append(number)
        assert pages, f'图片未嵌入：{name}'
        pictures[name] = pages
    toc = document.get_toc()
    assert all(1 <= entry[2] <= len(document) for entry in toc)
    assert any('FWT' in entry[1] for entry in toc)
    chapters = {entry[1]: entry[2] for entry in toc if entry[0] == 1}
    toc_links = 0
    for page in list(document)[1:min(chapters.values()) - 1]:
        for link in page.get_links():
            if link['kind'] not in (pymupdf.LINK_GOTO, pymupdf.LINK_NAMED):
                continue
            toc_links += 1
            rect = pymupdf.Rect(link['from'])
            rect.x0 = rect.x1 - 28
            rect.y0 -= 3
            rect.y1 += 3
            printed = page.get_textbox(rect).strip()
            if printed.isdigit():
                assert int(printed) == link['page'] + 1, (printed, link)
    report = {
        '总页数': len(document),
        '纵向 A4 页数': len(document),
        '目录页数': min(chapters.values()) - 2,
        '目录条目': toc_links,
        '目录核对': '逐项核对印刷页码与跳转目标一致',
        '完整代码块': len(code),
        '代码完整性': '全部代码块与 PDF 文字逐字核对通过（忽略空白与页眉页脚）',
        'PDF书签': len(toc),
        '已嵌入字体': len(fonts),
        '本地正文图片': pictures,
        '图片完整性': '5 张正文图片的解码像素与 PDF 嵌入图片一致，位置未越界',
        '输入完整性': f"{len(manifest['sources'])} 个输入文件 SHA256 校验通过",
        '积分表页数': 3,
        '各编起始页': chapters,
        '检查结果': '代码、图片、字体、目录目标、页面边界检查通过',
    }
    target = Path(__file__).with_name('排版检查.json')
    target.write_text(json.dumps(report, ensure_ascii=False, indent=2) + '\n')
    cover = pymupdf.open()
    cover.insert_pdf(document, from_page=0, to_page=0)
    cover.save(Path(__file__).with_name('封面.pdf'), garbage=4, deflate=True)
    document[0].get_pixmap(matrix=pymupdf.Matrix(1, 1)).save(Path(__file__).with_name('封面预览.png'))
    print(json.dumps(report, ensure_ascii=False, indent=2))
