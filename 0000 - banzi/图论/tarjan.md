三个 Tarjan 模板分别处理有向图的强连通分量、无向图的边双连通分量、无向图的点双连通分量。它们都用 DFS 序和 `low`，但判定条件和栈的含义不同。

点编号 `1..n`，无向边编号从 `0` 开始。函数接收邻接表，每次调用重新计算。

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
```

| 要求的结果 | 图的类型 | 核心判断 | 分量之间的关系 |
| --- | --- | --- | --- |
| 强连通分量 SCC | 有向图 | `low[u] == dfn[u]` 时弹栈 | 每个点只属于一个 SCC，缩点后为 DAG |
| 桥、边双 E-BCC | 无向图 | 树边 `u-v` 是桥当且仅当 `low[v] > dfn[u]` | 删除所有桥后的连通块，缩点后为森林 |
| 割点、点双 V-BCC | 无向图 | 非根 `u` 有孩子 `v` 满足 `low[v] >= dfn[u]` | 割点可以属于多个点双，构成块点森林 |

**DFS 序与 `low`**

`dfn[u]` 是第一次访问 `u` 的时间，访问后不再变化；`low[u]` 在搜索过程中更新。

无向图中，`low[u]` 表示：从 `u` 的 DFS 子树出发，经过若干条树边向下，再至多经过一条非树边，能到达的最小 DFS 序。必须排除进入 `u` 的那条树边，否则每个孩子都会通过父边“回到父亲”，导致桥判断失效。

有向图 SCC 中还要限制：已被分配到某个 SCC 的点不参与更新。下面用“已经访问，但 `bel[v] == 0`”表示仍在 SCC 栈中，省去单独的 `in_stack` 数组。

两者的递推形式很相似：

- `v` 尚未访问：先递归，再用 `low[v]` 更新 `low[u]`。
- `v` 已访问且符合当前算法的条件：用 `dfn[v]` 更新 `low[u]`。

不要把 `low[u]` 理解成“沿任意路径能到达的最小编号”，也不要把三个模板中的栈混为一谈。

**强连通分量：把相互可达的点缩成一个点**

同一个 SCC 中任意两个点都能相互到达。有向边只表示一个方向可达，所以普通连通块的 DFS 不能直接解决它。

SCC 栈保存“已经访问，但尚未归属某个 SCC”的点。它与递归栈不同：一个点的递归已经返回，也可能仍留在 SCC 栈中。遇到已经弹出的点时，不能再借它降低 `low`。

当 `low[u] == dfn[u]`，以 `u` 为根的这一段尚未归属的点已经无法连向更早的未归属点。于是从栈顶弹到 `u`，得到一个完整 SCC。

```cpp
vector<int> scc(const vector<vector<int>> &ed) {
    int n = (int)ed.size() - 1, tim = 0, cnt = 0;
    vector<int> dfn(n + 1), low(n + 1), bel(n + 1), st;
    auto dfs = [&](auto&& self, int u) -> void {
        dfn[u] = low[u] = ++tim;
        st.push_back(u);
        for (int v : ed[u]) {
            if (!dfn[v]) {
                self(self, v);
                low[u] = min(low[u], low[v]);
            } else if (!bel[v]) {          // 已访问，但还没出栈
                low[u] = min(low[u], dfn[v]);
            }
        }
        if (low[u] != dfn[u]) return;
        ++cnt;
        while (true) {
            int v = st.back(); st.pop_back();
            bel[v] = cnt;
            if (v == u) break;
        }
    };
    for (int u = 1; u <= n; ++u) if (!dfn[u]) dfs(dfs, u);
    return bel;
}
```

调用例子：

```cpp
int n = 5;
auto ed = vector(n + 1, vector<int>{});
ed[1] = {2};
ed[2] = {1, 3};
ed[3] = {4};
ed[4] = {3, 5};
auto bel = scc(ed);
int cnt = *max_element(bel.begin(), bel.end());
auto grp = vector(cnt + 1, vector<int>{});
for (int u = 1; u <= n; ++u) grp[bel[u]].push_back(u);
// 三个 SCC：{1,2}、{3,4}、{5}
```

`bel[u]` 是点 `u` 的分量编号，范围 `1..cnt`。本实现按照弹栈顺序编号，因此对于跨分量的原边 `u → v`，一定有 `bel[u] > bel[v]`：编号越小，越靠近缩点 DAG 的终点。这一点会用于 [2-SAT](2-SAT.md) 的方案恢复，不能直接套用其他 SCC 实现的比较方向。

缩点只需保留跨分量边：

```cpp
auto dag = vector(cnt + 1, vector<int>{});
for (int u = 1; u <= n; ++u) {
    for (int v : ed[u]) {
        if (bel[u] != bel[v]) dag[bel[u]].push_back(bel[v]);
    }
}
```

这里允许重边。若只做可达性或常见的 DAG 最值 DP，可以保留；若要统计不同边、不同路径等，需根据题意决定是否去重。

**桥与边双：删除一条边会不会断开**

对 DFS 树边 `u-v`，如果 `low[v] > dfn[u]`，说明 `v` 的子树无法绕过这条树边回到 `u` 或其祖先，故它是桥。等号表示还能通过另一条边回到 `u`，所以桥的条件必须严格大于。

无向图存在重边时，不能写 `if (v == parent) continue`：与父亲相连的另一条边恰好可以绕过树边。模板用边编号跳过唯一的进入边，支持重边和自环。桥的判定与重边处理可参看 [CP-Algorithms 的桥算法说明](https://cp-algorithms.com/graph/bridge-searching.html)。

求出桥后，沿非桥边再遍历一次即可得到边双，无须并查集或哈希映射。孤立点也单独构成一个边双分量。

```cpp
pair<vector<int>, vector<int>> ebcc(
    const vector<vector<pair<int, int>>> &ed, int m) {
    int n = (int)ed.size() - 1, tim = 0, cnt = 0;
    vector<int> dfn(n + 1), low(n + 1), bel(n + 1), bri(m);
    auto dfs = [&](auto&& self, int u, int pe) -> void {
        dfn[u] = low[u] = ++tim;
        for (auto [v, id] : ed[u]) {
            if (id == pe) continue;        // 只跳过进入 u 的那条边
            if (!dfn[v]) {
                self(self, v, id);
                low[u] = min(low[u], low[v]);
                if (low[v] > dfn[u]) bri[id] = 1;
            } else low[u] = min(low[u], dfn[v]);
        }
    };
    auto paint = [&](auto&& self, int u) -> void {
        bel[u] = cnt;
        for (auto [v, id] : ed[u]) {
            if (!bri[id] && !bel[v]) self(self, v);
        }
    };
    for (int u = 1; u <= n; ++u) if (!dfn[u]) dfs(dfs, u, -1);
    for (int u = 1; u <= n; ++u) {
        if (!bel[u]) ++cnt, paint(paint, u);
    }
    return {bel, bri};
}
```

调用 `auto [bel, bri] = ebcc(ed, m)`：`bel[u]` 为边双编号，`bri[id]` 标记桥。邻接表存 `(邻点, 边编号)`，同一条无向边的两个方向使用相同编号。与 SCC 不同，这里的分量编号不保证拓扑顺序。

**割点与点双：删除一个点会不会断开**

如果非根节点 `u` 有孩子 `v` 满足 `low[v] >= dfn[u]`，那么 `v` 的子树最多只能绕回 `u`，无法绕过 `u` 到达它的祖先。删除 `u` 后，这一部分就与上方断开，因此 `u` 是割点。

等号在这里也能成立：虽然可以回到 `u`，但 `u` 本身会被删除。这正是割点用 `>=`、桥用 `>` 的原因。

DFS 根节点没有“上方”，要单独判断：它至少有两个 DFS 树孩子时才是割点。这里数的是新递归出去的孩子，不是度数。割点判定可参看 [CP-Algorithms 的说明](https://cp-algorithms.com/graph/cutpoints.html)。

下面用顶点栈保存尚未划分完的部分。每当 `low[v] >= dfn[u]`，从栈顶弹到孩子 `v`，再加上 `u`，就得到一个点双；`u` 本身暂不弹出，因为它还可能属于其他点双。这样不必维护边栈、排序和去重。

约定：一条桥的两个端点形成一个二点块，孤立点形成一个单点块；自环不影响割点和这里的顶点分块，DFS 时跳过。模板支持重边。

```cpp
pair<vector<vector<int>>, vector<int>> vbcc(
    const vector<vector<pair<int, int>>> &ed) {
    int n = (int)ed.size() - 1, tim = 0;
    vector<int> dfn(n + 1), low(n + 1), cut(n + 1), st;
    auto bcc = vector(1, vector<int>{});
    auto dfs = [&](auto&& self, int u, int pe) -> void {
        dfn[u] = low[u] = ++tim;
        st.push_back(u);
        int ch = 0;
        for (auto [v, id] : ed[u]) {
            if (id == pe || v == u) continue;
            if (!dfn[v]) {
                ++ch;
                self(self, v, id);
                low[u] = min(low[u], low[v]);
                if (low[v] >= dfn[u]) {
                    if (pe != -1 || ch > 1) cut[u] = 1;
                    bcc.push_back({u});
                    while (true) {
                        int x = st.back(); st.pop_back();
                        bcc.back().push_back(x);
                        if (x == v) break;
                    }
                }
            } else low[u] = min(low[u], dfn[v]);
        }
        if (pe == -1 && ch == 0) bcc.push_back({u});
    };
    for (int u = 1; u <= n; ++u) {
        if (!dfn[u]) dfs(dfs, u, -1), st.pop_back(); // 最后弹出 DFS 根
    }
    return {bcc, cut};
}
```

调用 `auto [bcc, cut] = vbcc(ed)`：`cut[u]` 标记割点，`bcc[id]` 存一个点双的所有顶点，块编号从 `1` 开始。块点树（也常称圆方树）保留所有原点，并为每个点双新建一个块点，原点与包含它的块点连边；原图不连通时得到森林。

下面这个例子能区分边双和点双：

![边双与点双示例，灰色节点为割点](assets/tarjan-bcc.png)

两个三角形共用点 `3`，点 `5` 再连一条边到 `6`，点 `7` 孤立。

| 结果 | 内容 |
| --- | --- |
| 桥 | `5-6` |
| 割点 | `3、5` |
| 边双 | `{1,2,3,4,5}`、`{6}`、`{7}` |
| 点双 | `{1,2,3}`、`{3,4,5}`、`{5,6}`、`{7}` |

```cpp
int n = 7;
vector<pair<int, int>> e = {
    {1, 2}, {2, 3}, {3, 1}, {3, 4}, {4, 5}, {5, 3}, {5, 6}
};
int m = e.size();
auto ed = vector(n + 1, vector<pair<int, int>>{});
for (int i = 0; i < m; ++i) {
    auto [u, v] = e[i];
    ed[u].push_back({v, i});
    ed[v].push_back({u, i});
}
auto [bel, bri] = ebcc(ed, m);
auto [bcc, cut] = vbcc(ed);
```


按需缩成桥森林：

```cpp
int cnt = *max_element(bel.begin(), bel.end());
auto tr = vector(cnt + 1, vector<int>{});
for (int i = 0; i < m; ++i) {
    if (!bri[i]) continue;
    auto [u, v] = e[i];
    tr[bel[u]].push_back(bel[v]);
    tr[bel[v]].push_back(bel[u]);
}
```

或建立块点森林，同时记录每个原点属于哪些点双：

```cpp
int k = (int)bcc.size() - 1;
auto tr = vector(n + k + 1, vector<int>{});
auto pos = vector(n + 1, vector<int>{});
for (int i = 1; i <= k; ++i) {
    for (int u : bcc[i]) {
        tr[u].push_back(n + i);
        tr[n + i].push_back(u);
        pos[u].push_back(i);
    }
}
```

这两个建树片段按需选用；若同时使用，给两个 `tr` 分别命名。

三个算法本体的时间和空间复杂度均为 `O(n + m)`；点双顶点表虽然会重复记录割点，总规模仍是 `O(n + m)`。DFS 递归深度最坏为 `O(n)`，长链规模很大时需要考虑运行环境的栈容量。
