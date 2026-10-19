"""将分篇模板同步到合集章节，保留目录锚点并调整相对链接。"""
from pathlib import Path
import re
B=Path(__file__).resolve().parents[1]
mapping={
 '图论板子.md':dict(zip([
 'dijkstra','spfa-negative-cycle','johnson','difference-constraints','cycle-detection','tarjan','two-sat','euler','bipartite-matching','dinic','min-cost-flow','bounded-flow','weighted-bipartite-matching','general-matching','weighted-general-matching','virtual-tree','tree-divide','centroid-decomposition','dynamic-centroid-decomposition','tree-hash','prufer','prefix-graph','segment-tree-graph','steiner-tree'],[
 '图论/'+x+'.md' for x in ['dij','spfa判负环','Johnson全源最短路径','差分约束','找环','tarjan','2-SAT','欧拉回路欧拉路径','二分图最大匹配','dinic','费用流','上下界网络流','二分图最大权匹配','一般图最大匹配','一般图最大权匹配','虚树','树分治','点分治','动态树分治','树哈希','prefur序列','前缀优化建图','线段树优化建图','斯坦纳树']])),
 '数据结构板子.md':{'segment-tree':'数据结构/线段树.md','persistent-segment-tree':'数据结构/可持久化线段树.md','segment-tree-merge-split':'数据结构/线段树合并与分裂.md','mo':'数据结构/莫队.md','li-chao-tree':'数据结构/李超线段树.md','segment-tree-beats':'数据结构/区间最值操作与历史最值.md','cat-tree':'数据结构/猫树.md'},
 '数学板子.md':{'polynomial':'数学/多项式板子.md','binary':'数学/二进制常用小技巧.md'},
}
def content(path):
 s=(B/path).read_text().strip()
 top=re.match(r'^(#{1,2}) [^\n]+\n',s)
 shift=1 if path == "数学/二进制常用小技巧.md" else 0
 if top:
  shift=2-len(top[1]);s=s[top.end():].lstrip()
 # Standalone H1 notes need their subsections shifted by one for a chapter's H2 section.
 lines=[];fence=False
 for line in s.splitlines():
  if line.startswith('```'):fence=not fence
  if not fence and re.match(r'^#{1,6} ',line):line='#'*shift+line
  # Resolve relative images and relative reference links against the original directory.
  if not fence:
   def link(m):
    target=m[1]
    if re.match(r'[a-z]+:|#',target):return m[0]
    from os.path import normpath
    return ']('+normpath(str(Path(path).parent/target))+')'
   line=re.sub(r'\]\(([^)]+)\)',link,line)
  lines.append(line)
 assert not fence, f'{path}: 代码围栏未闭合'
 return '\n'.join(lines)
for name,sections in mapping.items():
 p=B/name;s=p.read_text()
 pat=r'(<a id="([^"]+)"></a>\s*\n+## [^\n]+\n)(.*?)(?=\n<a id="[^"]+"></a>\s*\n+## |\Z)'
 def section(m):
  if m[2] not in sections:return m[0]
  return m[1]+'\n'+content(sections[m[2]])+'\n\n'
 s=re.sub(pat,section,s,flags=re.S)
 p.write_text(s)
