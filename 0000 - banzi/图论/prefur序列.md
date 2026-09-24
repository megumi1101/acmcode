**Prufer 序列**是图论里的一种经典编码方法，用来唯一表示一棵带标号的树。下面我给你分几个部分解释：

---

## 1. 定义

给定一棵 **n 个节点的带标号树（顶点编号为 1…n）**，其 **Prufer 序列** 是一个长度为 `n-2` 的序列，元素来自节点编号集合。

---

## 2. 构造方法（树 → Prufer 序列）

循环 `n-2` 次，每次操作：

1. 找到当前树中 **度数为 1 的最小编号节点 u**。
2. 记录与 `u` 相连的那个节点 `v`，把 `v` 加入 Prufer 序列。
3. 从树中删除节点 `u`。

最终得到的长度 `n-2` 序列就是该树的 **Prufer 编码**。

---

### 示例

树边集合：

```
1—2, 2—3, 2—4, 4—5
```

步骤：

* 度数为 1 的最小点是 1，删去它，记录邻居 2 → \[2]
* 度数为 1 的最小点是 3，删去它，记录邻居 2 → \[2,2]
* 度数为 1 的最小点是 2，删去它，记录邻居 4 → \[2,2,4]

所以 Prufer 序列是 **\[2,2,4]**。

---

## 3. 逆过程（Prufer 序列 → 树）

已知一条长度为 `n-2` 的序列 `P`：

1. 初始化一个多重集 `S`，包含所有顶点 `1…n`。
2. 对于序列 `P`，统计每个顶点出现的次数（记为 `cnt`）。
3. 循环序列：

   * 取 `S` 中 **最小编号且 cnt=0** 的顶点 `u`。
   * 取当前序列中的元素 `v`，连边 `(u,v)`。
   * 删除 `u`，并让 `cnt[v]--`。
4. 最后剩下两个点，连边即可。

---

### 示例

序列 \[2,2,4]，n=5：

* cnt(2)=2，cnt(4)=1，其他=0，S={1,2,3,4,5}
* 取最小无 cnt 的点 1，连 (1,2)，cnt(2)=1
* 取最小无 cnt 的点 3，连 (3,2)，cnt(2)=0
* 取最小无 cnt 的点 2，连 (2,4)，cnt(4)=0
* 最后剩下 {4,5}，连 (4,5)

还原出的树边正好是 {1-2,2-3,2-4,4-5}。

---

## 4. 性质

* **一一对应**：n 个点的带标号树 ↔ 长度 n-2 的 Prufer 序列。
* **数量验证**：序列有 `n^(n-2)` 种，正好是 Cayley 定理的结果：n 个点的树有 `n^(n-2)` 棵。
* **度数关系**：在 Prufer 序列中，某个点出现的次数 = 该点度数 - 1。

---

## 5. 代码实现 (C++)

```cpp
#include <bits/stdc++.h>
using namespace std;

// 树转 Prufer 序列
vector<int> tree_to_prufer(int n, vector<pair<int,int>> edges) {
    vector<int> deg(n+1, 0);
    vector<vector<int>> g(n+1);
    for (auto [u,v]: edges) {
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++; deg[v]++;
    }
    set<int> leaves;
    for (int i=1;i<=n;i++) if (deg[i]==1) leaves.insert(i);

    vector<int> prufer;
    for (int i=0;i<n-2;i++) {
        int leaf = *leaves.begin(); // 度数为1的最小点
        leaves.erase(leaves.begin());
        int neighbor;
        for (int v: g[leaf]) if (deg[v]>0) neighbor=v;
        prufer.push_back(neighbor);
        deg[leaf]--; deg[neighbor]--;
        if (deg[neighbor]==1) leaves.insert(neighbor);
    }
    return prufer;
}

// Prufer 序列转树
vector<pair<int,int>> prufer_to_tree(int n, vector<int> prufer) {
    vector<int> deg(n+1,1);
    for (int x: prufer) deg[x]++;
    set<int> leaves;
    for (int i=1;i<=n;i++) if (deg[i]==1) leaves.insert(i);

    vector<pair<int,int>> edges;
    for (int x: prufer) {
        int leaf = *leaves.begin();
        leaves.erase(leaves.begin());
        edges.push_back({leaf,x});
        if (--deg[x]==1) leaves.insert(x);
    }
    int u=*leaves.begin(); leaves.erase(leaves.begin());
    int v=*leaves.begin(); leaves.erase(leaves.begin());
    edges.push_back({u,v});
    return edges;
}
```


