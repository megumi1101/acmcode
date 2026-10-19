# Johnson 全源最短路径

先用超级源点求势能，再重赋权，最后枚举源点跑 Dijkstra。适合稀疏有向图，允许负边；有负环时返回无解。

## 为什么不能给每条边加同一个数

两条路径的边数可能不同，统一加 `c` 后，它们增加的代价分别是 `边数 * c`，大小关系可能改变。需要让同一起终点的所有路径增加同一个量。

加一个超级源点 `0`，向所有点连权值为 `0` 的边，用 Bellman–Ford 求 `h[u] = dist(0,u)`。对原边改成：

$$
w'(u,v)=w(u,v)+h[u]-h[v].
$$

由最短路不等式 `h[v] <= h[u] + w`，得到 `w' >= 0`。一条 `s → t` 路径上的中间势能全部抵消，总长度变为 `原长度 + h[s] - h[t]`，所以最短路径不变。Dijkstra 求得 `dis[t]` 后，原距离为：

$$
dist(s,t)=dis[t]-h[s]+h[t].
$$

## 板子

直接在主函数里读图，`init()` 求势能并判负环，`dij(s)` 把从 `s` 出发的原图距离写入 `dis`。先调用一次 `init()`，成功后再枚举源点；不必保存 `n*n` 的矩阵。

下面是 [Luogu P5905 全源最短路](https://www.luogu.com.cn/problem/P5905) 的完整写法，不可达按题意记作 `1e9`。主函数主体也可以直接放进自己的 `solve()`。

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> e;
    auto ed = vector(n + 1, vector<pair<int, int>>{});
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e.emplace_back(u, v, w);
        ed[u].emplace_back(v, w);
    }
    const int inf = 1LL << 62;
    vector<int> h(n + 1), dis(n + 1);
    auto init = [&]() -> bool {
        // 等价于先松弛超级源点的 n 条零边，不必实际建 0 号点。
        fill(h.begin(), h.end(), 0);
        for (int i = 1; i <= n; i++) {
            bool ok = false;
            for (auto [u, v, w] : e) {
                if (h[v] <= h[u] + w) continue;
                h[v] = h[u] + w;
                ok = true;
            }
            if (!ok) return true;
            if (i == n) return false;
        }
        return true;
    };

    auto dij = [&](int s) -> void {
        fill(dis.begin(), dis.end(), inf);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        dis[s] = 0;
        q.emplace(0, s);
        while (!q.empty()) {
            auto [cost, u] = q.top(); q.pop();
            if (cost != dis[u]) continue;
            for (auto [v, w] : ed[u]) {
                w += h[u] - h[v];
                if (dis[v] <= cost + w) continue;
                dis[v] = cost + w;
                q.emplace(dis[v], v);
            }
        }
        for (int i = 1; i <= n; i++) {
            if (dis[i] != inf) dis[i] += h[i] - h[s];
        }
    };

    if (!init()) {
        cout << -1 << '\n';
        return 0;
    }
    for (int s = 1; s <= n; s++) {
        dij(s); // 原图距离保存在 dis 中，不可达为 inf
        int ans = 0;
        for (int v = 1; v <= n; v++) {
            ans += v * (dis[v] == inf ? 1000000000LL : dis[v]);
        }
        cout << ans << '\n';
    }
}
```

`h` 全零相当于所有原点都能从超级源到达，因此不连通部分里的负环也能发现。Bellman–Ford 的第 `n` 轮还发生松弛，就存在负环。这里保留原边权，`dij` 内临时重赋权；每次调用会先重置 `dis`。

初始化最坏 `O(nm)`，本实现全源总时间 `O(nm + n(n+m) log(n+m))`，逐行处理的空间 `O(n+m)`；保存所有结果另需 `O(n²)`。稠密图可以考虑 Floyd。

先加完边再 `init()`；之后修改图必须重新初始化。要求势能、重赋权、距离加法和最终加权和都在 `ll` 范围内，有限距离小于 `inf`；判负环前的 Bellman–Ford 松弛过程也不能溢出。无向图若存在负边，双向建边后便有负环，不能直接使用。

参考：[OI Wiki 最短路及其贡献者](https://oi-wiki.org/graph/shortest-path/)（[CC BY-SA 4.0](https://creativecommons.org/licenses/by-sa/4.0/) / [SATA](https://github.com/zTrix/sata-license)）。
