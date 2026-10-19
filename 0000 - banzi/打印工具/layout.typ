#set document(title: "XCPC 竞赛板子合集 打印版")
#set text(font: ("Cambria", "SimSun"), size: 10pt, lang: "zh", region: "CN", fill: luma(6%))
#set page(
  paper: "a4",
  margin: (inside: 17mm, outside: 13mm, top: 15mm, bottom: 15mm),
  header: context {
    if counter(page).get().first() > 1 {
      set text(font: ("Microsoft YaHei", "Cambria"), size: 7.5pt, fill: luma(35%))
      let current = query(heading.where(level: 1)).filter(h => h.location().page() <= here().page())
      grid(columns: (1fr, auto),
        [XCPC 竞赛板子合集],
        if current.len() > 0 { current.last().body } else { [目录] },
      )
      v(2pt)
      line(length: 100%, stroke: 0.25pt + luma(65%))
    }
  },
  footer: context {
    if counter(page).get().first() > 1 {
      set text(font: "Cambria", size: 8pt, fill: luma(30%))
      align(center)[#counter(page).display("1") / #counter(page).final().first()]
    }
  },
)
#set par(leading: 0.4em, spacing: 0.5em, justify: true)
#set heading(numbering: "1.1")
#show heading.where(level: 1): it => {
  pagebreak(weak: true)
  set text(font: ("Microsoft YaHei", "Cambria"), size: 18pt, weight: "bold")
  block(above: 0pt, below: 12pt, it)
}
#show heading.where(level: 2): set text(font: ("Microsoft YaHei", "Cambria"), size: 12pt, weight: "bold")
#show heading.where(level: 2): set block(above: 10pt, below: 5pt)
#show heading.where(level: 3): set text(font: ("Microsoft YaHei", "Cambria"), size: 10.6pt, weight: "bold")
#show heading.where(level: 3): set block(above: 8pt, below: 4pt)
#show heading.where(level: 4): set text(font: ("Microsoft YaHei", "Cambria"), size: 10pt, weight: "bold")
#show heading.where(level: 3): set heading(numbering: none)
#show heading.where(level: 4): set heading(numbering: none)
#show heading.where(level: 5): set heading(numbering: none)
#show strong: set text(font: ("Cambria", "Microsoft YaHei"), weight: "bold")
#show link: set text(fill: luma(8%))
#set list(indent: 0.7em, body-indent: 0.55em, spacing: 0.25em)
#set enum(indent: 0.7em, body-indent: 0.55em, spacing: 0.25em)
#set raw(theme: none, tab-size: 4)
#show raw: set text(font: ("Consolas", "Microsoft YaHei"))
#show raw.where(block: false): set text(size: 8.5pt)
#show raw.where(block: true): set text(size: 9pt)
#show raw.where(block: true): set par(leading: 0.4em, spacing: 0pt, justify: false)
#show raw.where(block: true): it => block(
  width: 100%, inset: (x: 6pt, y: 5pt), fill: luma(98%),
  stroke: 0.25pt + luma(78%), radius: 1.5pt,
  breakable: it.text.split("\n").len() > 10,
  above: 4pt, below: 4pt, it,
)
#set table(inset: (x: 4pt, y: 2.5pt), stroke: 0.25pt + luma(60%))
#show table: set text(size: 9pt)
#show table: set par(leading: 0.25em, justify: false)
#show figure.where(kind: table): set block(breakable: true, above: 5pt, below: 5pt)
#show table.cell.where(y: 0): set text(font: ("Cambria", "Microsoft YaHei"), weight: "bold")
#show table.cell.where(y: 0): set table.cell(fill: luma(94%))
#show figure.where(kind: image): set block(breakable: false)
#show figure.where(kind: image): set image(width: 100%)

#place(top + left, dx: 8mm, dy: 14mm)[
  #line(length: 13mm, stroke: 0.8pt + luma(10%))
]
#place(top + left, dx: 8mm, dy: 45mm)[
  #block(width: 155mm)[
    #set par(justify: false, leading: 0.4em)
    #text(font: "Cambria", size: 56pt, weight: "bold", tracking: 0.03em)[XCPC]
    #v(4mm)
    #text(font: "Microsoft YaHei", size: 25pt, weight: "bold")[竞赛板子合集]
    #v(10mm)
    #text(font: "Cambria", size: 13pt, tracking: 0.3em, fill: luma(30%))[XBB]
  ]
]
#place(bottom + left, dx: 8mm, dy: -8mm)[
  #image("assets/cover-rin.png", height: 45mm)
]
#place(bottom + left, dx: 8mm, dy: -4mm)[
  #line(length: 155mm, stroke: 0.3pt + luma(75%))
]
#pagebreak()
#context {
  let details = json("toc-details.json").map(id => label(id))
  let entries = query(heading).filter(h => h.outlined and (h.level <= 2 or h.label in details))

  let chapter-entry(h, continued: false) = {
    let numbers = counter(heading).at(h.location())
    let chapter = if h.numbering == none { [附] } else { [#("0" + str(numbers.first()))] }
    block(width: 100%, height: 24pt, above: 6pt, below: 4pt, breakable: false,
      fill: luma(96%), inset: (x: 9pt, y: 4pt),
      stroke: (bottom: 0.35pt + luma(78%)),
      link(h.location(), grid(
        columns: (29pt, 1fr, auto), column-gutter: 7pt, align: horizon,
        text(font: "Cambria", size: 14pt, weight: "bold", fill: luma(36%))[#chapter],
        text(font: "Microsoft YaHei", size: 12pt, weight: "bold")[#h.body],
        if continued {
          text(font: "Microsoft YaHei", size: 9pt, fill: luma(38%))[续]
        } else {
          text(font: "Cambria", size: 11pt, weight: "bold")[#h.location().page()]
        },
      )),
    )
  }

  let section-entry(h, continued: false) = {
    let numbers = counter(heading).at(h.location())
    let detail = h.level > 2
    let prefix = if detail { [·] } else { numbering(h.numbering, ..numbers) }
    let display-title = if continued { [#h.body（续）] } else { h.body }
    let size = if detail { 9.2pt } else { 10.3pt }
    block(width: 100%, height: if detail { 11.8pt } else { 14.2pt }, above: 0pt, below: 0pt, breakable: false,
      inset: (left: if detail { 43pt } else { 10pt }, right: 9pt),
      link(h.location(), grid(
        columns: (if detail { 7pt } else { 30pt }, auto, 1fr, 24pt), column-gutter: 6pt, align: horizon,
        text(font: "Cambria", size: 9.3pt, fill: luma(42%))[#prefix],
        text(font: ("Cambria", "SimSun"), size: size, fill: if detail { luma(24%) } else { luma(6%) })[#display-title],
        box(width: 100%, text(size: 8pt, fill: luma(65%))[#repeat[. ]]),
        align(right, text(font: "Cambria", size: size)[#h.location().page()]),
      )),
    )
  }

  let groups = ()
  let items = ()
  let chapter = none
  let section = none
  let carry-chapter = none
  let carry-section = none
  let used = 0pt
  let entry-height(h) = if h.level == 1 { 34pt } else if h.level == 2 { 14.2pt } else { 11.8pt }
  for (index, h) in entries.enumerate() {
    if h.level == 1 { chapter = h; section = none }
    if h.level == 2 { section = h }
    let reserve = if h.level <= 2 and index + 1 < entries.len() {
      entry-height(entries.at(index + 1))
    } else { 0pt }
    if items.len() > 0 and used + entry-height(h) + reserve > 690pt {
      groups.push((items: items, chapter: carry-chapter, section: carry-section))
      items = ()
      carry-chapter = if h.level > 1 { chapter } else { none }
      carry-section = if h.level > 2 { section } else { none }
      used = (if carry-chapter != none { 34pt } else { 0pt }) + (if carry-section != none { 14.2pt } else { 0pt })
    }
    items.push(h)
    used += entry-height(h)
  }
  if items.len() > 0 { groups.push((items: items, chapter: carry-chapter, section: carry-section)) }

  for (index, group) in groups.enumerate() {
    if index > 0 { pagebreak() }
    let names = group.items.filter(h => h.level == 1).map(h => h.body)
    if group.chapter != none { names = (group.chapter.body,) + names }
    let section-names = names.join([　/　])
    block(above: 0pt, below: 8pt)[
      #grid(columns: (1fr, auto), align: horizon,
        text(font: "Microsoft YaHei", size: 22pt, weight: "bold")[目录],
        text(font: "Cambria", size: 10pt, fill: luma(40%))[#(index + 1) / #groups.len()],
      )
      #v(4pt)
      #text(font: "Microsoft YaHei", size: 8.7pt, fill: luma(40%))[#section-names]
      #v(5pt)
      #line(length: 100%, stroke: 0.5pt + luma(40%))
    ]
    if group.chapter != none { chapter-entry(group.chapter, continued: true) }
    if group.section != none { section-entry(group.section, continued: true) }
    for h in group.items {
      if h.level == 1 { chapter-entry(h) } else { section-entry(h) }
    }
  }
}
#pagebreak()
#include "body.typ"
#pagebreak()
#heading(level: 1, numbering: none)[附录 积分表] <integral-table>
#text(size: 9pt, fill: luma(40%))[1 / 3]
#pagebreak()
#text(font: "Microsoft YaHei", size: 18pt, weight: "bold")[积分表 2 / 3]
#pagebreak()
#text(font: "Microsoft YaHei", size: 18pt, weight: "bold")[积分表 3 / 3]
