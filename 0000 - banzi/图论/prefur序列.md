# Prüfer 序列


C++17，树的点编号为 `1..n`，序列使用普通 `vector` 的 `0..n-3` 下标。以下默认 `n >= 2`；单点树没有通常意义下长度为 `n-2` 的编码，需单独处理。

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
```

## 1. 树变序列

每次删除编号最小的叶子，把它唯一的邻居加入序列，重复 `n-2` 次。比如边为 `1-2、2-3、2-4、4-5`：依次删去 `1、3、2`，记录 `2、2、4`。

先用 `set` 维护叶子，便于理解。每个点的邻接表只在删除它时扫描一次，总扫描量为 `O(n)`，集合操作使总时间为 `O(n log n)`。

```cpp
vector<int> encode_set(const vector<vector<int>> &ed) {
    int n = (int)ed.size() - 1;
    vector<int> deg(n + 1), p;
    set<int> leaf;
    for (int i = 1; i <= n; i++) {
        deg[i] = ed[i].size();
        if (deg[i] == 1) leaf.insert(i);
    }
    for (int i = 0; i < n - 2; i++) {
        int u = *leaf.begin();
        leaf.erase(leaf.begin());
        deg[u] = 0;
        for (int v : ed[u]) {
            if (!deg[v]) continue;
            p.push_back(v);
            if (--deg[v] == 1) leaf.insert(v);
            break;
        }
    }
    return p;
}
```

## 2. 线性编码

删一个叶子最多产生一个新叶子。维护只向右走的扫描指针 `pos`，以及本轮真正要删的叶子 `u`：

- 如果新叶子 `v < pos`，它就是下一轮最小叶子，直接令 `u=v`，**不回退 `pos`**。
- 否则把 `pos` 向右移到下一个度数为 `1` 的点，令 `u=pos`。

`pos` 总共只扫一遍，另外每轮只处理一个点，故总时间 `O(n)`。

为了直接知道 `u` 剩余的邻居，把原树以最大编号 `n` 为根，预处理 `fa`。`n` 一定留到最后：剩余点不少于三个时，若 `n` 是叶子，必然还有编号更小的叶子；所以删点过程不会先删掉还带孩子的父亲，删除 `u` 时唯一邻居就是 `fa[u]`。

```cpp
vector<int> encode(const vector<vector<int>> &ed) {
    int n = (int)ed.size() - 1;
    vector<int> fa(n + 1), deg(n + 1), p;
    auto dfs = [&](auto &&self, int u, int f) -> void {
        fa[u] = f;
        deg[u] = ed[u].size();
        for (int v : ed[u]) if (v != f) self(self, v, u);
    };
    dfs(dfs, n, 0);
    int pos = 1;
    while (deg[pos] != 1) pos++;
    int u = pos;
    for (int i = 0; i < n - 2; i++) {
        int v = fa[u];
        p.push_back(v);
        deg[u] = 0;
        if (--deg[v] == 1 && v < pos) {
            u = v;
        } else {
            do { pos++; } while (deg[pos] != 1);
            u = pos;
        }
    }
    return p;
}
```

## 3. 性质与解码

一个点每失去一个相邻叶子，就在序列里出现一次；它自己被删除或成为最后两个点时，还剩一条边。因此：

$$
\deg(u)=1+\text{序列中 }u\text{ 的出现次数}.
$$

从没出现在序列里的点恰好是原树的叶子。根据这个式子恢复初始度数，再依次取最小叶子 `u`，与当前序列元素 `v` 连边，同时减度数。最后两个点连边，其中一个必然是 `n`。

下面仍用单调扫描指针，时间与额外空间都是 `O(n)`。若想写集合版，和 `encode_set` 一样维护度数为 `1` 的点即可。

```cpp
vector<pair<int, int>> decode(const vector<int> &p) {
    int n = (int)p.size() + 2;
    vector<int> deg(n + 1, 1);
    for (int x : p) deg[x]++;
    int pos = 1;
    while (deg[pos] != 1) pos++;
    int u = pos;
    vector<pair<int, int>> e;
    for (int v : p) {
        e.emplace_back(u, v);
        deg[u] = 0;
        if (--deg[v] == 1 && v < pos) {
            u = v;
        } else {
            do { pos++; } while (deg[pos] != 1);
            u = pos;
        }
    }
    e.emplace_back(u, n);
    return e;
}
```

合法输入要求序列的每个值都在 `1..p.size()+2`。`n=2` 时序列为空，编码直接返回空数组，解码返回边 `(1,2)`。

调用示例（放在 `signed main()` 中）：

```cpp
int n = 5;
auto ed = vector(n + 1, vector<int>{});
vector<pair<int, int>> e = {{1, 2}, {2, 3}, {2, 4}, {4, 5}};
for (auto [u, v] : e) {
    ed[u].push_back(v);
    ed[v].push_back(u);
}
auto p = encode(ed); // {2, 2, 4}
auto edges = decode(p);
for (auto [u, v] : edges) cout << u << ' ' << v << '\n';
```

序列唯一确定一棵带标号无根树，编码和解码互为逆过程。输出边的顺序、每条边两个端点的顺序不影响是否为同一棵树。

## 4. Cayley 公式与度数计数

`n >= 2` 时，每个长度为 `n-2`、值域为 `1..n` 的序列都能解出一棵树，所以 `n` 个带标号点的无根树有：

$$
n^{n-2}.
$$

若另选一个根，乘 `n` 得 `n^{n-1}`；指定根则不额外乘。`n=1` 的树数单独记为 `1`。

指定每个点的度数 `d[i]` 时，先检查所有 `d[i] >= 1` 且 `sum(d)=2n-2`，否则无解。每个点在序列中必须出现 `d[i]-1` 次，因此方案数为多重集排列数：

$$
\frac{(n-2)!}{\prod_{i=1}^{n}(d_i-1)!}.
$$

例如 `n=5`，度数为 `1,3,1,2,1`，序列必须含两个 `2` 和一个 `4`，共有 `3` 棵树。取模计算可以接 [组合数学板子](../数学/组合数学板子.md) 的阶乘、逆阶乘；用逆阶乘时须满足相应模数和阶乘可逆条件。

## 5. 加最少的边使图连通

原无向图有 `k` 个连通块，大小为 `s[1..k]`，总点数为 `n`。恰好加 `k-1` 条边使图连通，缩点后新增边必须是一棵树。

固定缩点树的度数 `d[i]` 后，第 `i` 块每条关联边都可以独立选择块内端点，有 `s[i]^d[i]` 种。把其中一个 `s[i]` 提到外面，剩下的指数 `d[i]-1` 正好是 Prüfer 序列出现次数。序列每一位都可以贡献任意一块的大小，所以：

$$
\sum_{\text{缩点树}}\prod_i s_i^{d_i}
=\left(\prod_i s_i\right)\left(\sum_i s_i\right)^{k-2}
=n^{k-2}\prod_i s_i,\qquad k\ge 2.
$$

`k=1` 时已经连通，不加边只有 `1` 种方案，不能直接代入负指数。这里只计新增边集合，若题目区分加边的先后顺序，再乘 `(k-1)!`。

练习：[Luogu P6086 Prüfer 序列](https://www.luogu.com.cn/problem/P6086)。该题规模很大，输入已经给出以 `n` 为根的父亲时，可直接复用 `fa` 并统计度数，省去邻接表与遍历；千万级数据还应把编号、父亲、度数改用 32 位存储，只把异或答案中的乘法提升到 64 位，不能照搬本篇所有数组都为 64 位的写法。

参考：[OI Wiki Prüfer 序列及其贡献者](https://oi-wiki.org/graph/prufer/)（[CC BY-SA 4.0](https://creativecommons.org/licenses/by-sa/4.0/) / [SATA](https://github.com/zTrix/sata-license)）。
