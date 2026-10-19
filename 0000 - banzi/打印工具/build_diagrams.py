"""从本地绘图描述生成打印图（PNG）及可编辑的 SVG，依赖 Pillow。"""
from pathlib import Path
from html import escape
import math
from PIL import Image, ImageDraw, ImageFont

BASE = Path(__file__).resolve().parents[1]
FONT = next((p for p in [Path('/mnt/c/Windows/Fonts/simsun.ttc'), Path('/usr/share/fonts/truetype/droid/DroidSansFallbackFull.ttf')] if p.exists()), None)
if FONT is None:
    raise RuntimeError('需要中文字体：SimSun 或 Droid Sans Fallback')


def diagram(path, width, height, nodes, edges, directed=True, circles=False):
    scale = 3
    image = Image.new('RGB', (width * scale, height * scale), 'white')
    draw = ImageDraw.Draw(image)
    font = ImageFont.truetype(str(FONT), 21 * scale)
    svg = [f'<svg xmlns="http://www.w3.org/2000/svg" width="{width}" height="{height}" viewBox="0 0 {width} {height}">', '<rect width="100%" height="100%" fill="white"/>']
    for source, target in edges:
        x, y, *_ = nodes[source]; u, v, *_ = nodes[target]
        dx, dy = u - x, v - y
        factor = (32 if circles else 26) / max(abs(dy), 1) if abs(dy) >= abs(dx) else (32 if circles else 80) / max(abs(dx), 1)
        factor = min(factor, .3)
        x, y, u, v = x + dx * factor, y + dy * factor, u - dx * factor, v - dy * factor
        draw.line((x*scale,y*scale,u*scale,v*scale),fill='#333333',width=2*scale)
        svg.append(f'<line x1="{x}" y1="{y}" x2="{u}" y2="{v}" stroke="#333" stroke-width="2"/>')
        if directed:
            ang=math.atan2(v-y,u-x)
            points=[(u,v),(u-12*math.cos(ang-.4),v-12*math.sin(ang-.4)),(u-12*math.cos(ang+.4),v-12*math.sin(ang+.4))]
            draw.polygon([(a*scale,b*scale) for a,b in points],fill='#333333')
            svg.append('<polygon points="'+' '.join(f'{a},{b}' for a,b in points)+'" fill="#333"/>')
    for x,y,label,*kind in nodes.values():
        fill='#eeeeee' if kind else '#ffffff'
        if circles:
            draw.ellipse(((x-29)*scale,(y-29)*scale,(x+29)*scale,(y+29)*scale),fill=fill,outline='#222222',width=2*scale)
            svg.append(f'<circle cx="{x}" cy="{y}" r="29" fill="{fill}" stroke="#222" stroke-width="2"/>')
        else:
            draw.rounded_rectangle(((x-82)*scale,(y-25)*scale,(x+82)*scale,(y+25)*scale),radius=5*scale,fill=fill,outline='#222222',width=2*scale)
            svg.append(f'<rect x="{x-82}" y="{y-25}" width="164" height="50" rx="5" fill="{fill}" stroke="#222" stroke-width="2"/>')
        bbox=draw.textbbox((0,0),label,font=font)
        draw.text((x*scale-(bbox[2]-bbox[0])/2,y*scale-(bbox[3]-bbox[1])/2-bbox[1]),label,font=font,fill='#111111')
        svg.append(f'<text x="{x}" y="{y}" text-anchor="middle" dominant-baseline="central" font-family="SimSun, Droid Sans Fallback, sans-serif" font-size="21">{escape(label)}</text>')
    svg.append('</svg>')
    target=BASE/path;target.parent.mkdir(parents=True,exist_ok=True)
    target.with_suffix('.svg').write_text('\n'.join(svg)+'\n')
    image.save(target.with_suffix('.png'))
    print(target.with_suffix('.png').relative_to(BASE))


def main():
    diagram('数据结构/assets/segment-tree', 900, 300, {
        'a':(450,40,'[0,3]'),'b':(240,140,'[0,1]'),'c':(660,140,'[2,3]'),
        'd':(120,250,'[0]'),'e':(340,250,'[1]'),'f':(560,250,'[2]'),'g':(780,250,'[3]'),
    }, [('a','b'),('a','c'),('b','d'),('b','e'),('c','f'),('c','g')])
    diagram('数据结构/assets/persistent-segment-tree', 1050, 440, {
        'a':(180,40,'旧根 0..7'),'d':(800,40,'新根 0..7','new'),
        'b':(180,150,'旧 0..3'),'e':(800,150,'新 0..3','new'),'c':(490,150,'共享 4..7'),
        'f':(490,260,'共享 0..1'),'g':(180,260,'旧 2..3'),'h':(800,260,'新 2..3','new'),
        'i':(180,390,'旧 2'),'j':(490,390,'共享 3'),'k':(800,390,'新 2','new'),
    }, [('a','b'),('a','c'),('d','e'),('d','c'),('b','f'),('b','g'),('e','f'),('e','h'),('g','i'),('g','j'),('h','k'),('h','j')])
    diagram('数据结构/assets/segment-tree-merge', 870, 240, {
        'a':(115,65,'A：同一值域'),'b':(115,185,'B：同一值域'),
        'c':(435,65,'递归合并左儿子'),'d':(435,185,'递归合并右儿子'),'e':(755,125,'pull 合并信息'),
    }, [('a','c'),('b','c'),('a','d'),('b','d'),('c','e'),('d','e')])
    diagram('图论/assets/tarjan-bcc', 800, 220, {
        'a':(60,60,'1'),'b':(60,160,'2'),'c':(245,110,'3','cut'),
        'd':(430,60,'4'),'e':(430,160,'5','cut'),'f':(615,160,'6'),'z':(745,60,'7'),
    }, [('a','b'),('b','c'),('c','a'),('c','d'),('d','e'),('e','c'),('e','f')],directed=False,circles=True)


if __name__ == '__main__':
    main()
