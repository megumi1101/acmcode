Dinic 求有向图的最大流：反复 **BFS 分层 → DFS 沿分层图增广**，直到源点无法到达汇点。

下面是 C++17 模板，保留最大流的核心接口，使用连续的边编号管理反向边。点编号可用 `1..n`，也可用 `0..n-1`；要求 `s != t`，容量非负，容量和最大流均不超过 `ll` 的范围。

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Dinic {
    using ll = ll;
    struct Edge {
        int to;
        ll cap;                       // 剩余容量，不是原始容量
    };

    int s, t;
    vector<Edge> e;
    vector<vector<int>> g;             // g[u] 存从 u 出发的边编号
    vector<int> dep, cur;              // 层数、当前弧下标

    Dinic(int n, int s, int t)
        : s(s), t(t), g(n + 1), dep(n + 1), cur(n + 1) {}

    void add_edge(int u, int v, ll cap) {
        int id = (int)e.size();
        g[u].push_back(id);
        e.push_back({v, cap});
        g[v].push_back(id ^ 1);
        e.push_back({u, 0});            // 正反边成对加入，编号互为 id ^ 1
    }

    bool bfs() {
        fill(dep.begin(), dep.end(), -1);
        queue<int> q;
        dep[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int id : g[u]) {
                auto [v, cap] = e[id];
                if (cap > 0 && dep[v] == -1) {
                    dep[v] = dep[u] + 1;
                    q.push(v);
                }
            }
        }
        return dep[t] != -1;
    }

    ll dfs(int u, ll limit) {          // 本次最多送 limit，返回实际送出的流量
        if (u == t) return limit;
        for (int &i = cur[u]; i < (int)g[u].size(); ++i) {
            int id = g[u][i], v = e[id].to;
            if (e[id].cap == 0 || dep[v] != dep[u] + 1) continue;
            ll f = dfs(v, min(limit, e[id].cap));
            if (f == 0) continue;
            e[id].cap -= f;
            e[id ^ 1].cap += f;        // 反向边允许后续撤回、改道
            return f;                 // 成功时保留当前弧，下次可能还能走
        }
        return 0;
    }

    ll maxflow() {
        ll flow = 0;
        while (bfs()) {
            fill(cur.begin(), cur.end(), 0); // 每次重新分层后重置当前弧
            while (ll f = dfs(s, LLONG_MAX)) flow += f;
        }
        return flow;
    }

    // 求完最大流后调用：返回最小割源点侧的标记，1 表示属于 S
    vector<char> mincut_side() const {
        vector<char> vis(g.size(), 0);
        queue<int> q;
        vis[s] = 1;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int id : g[u]) {
                auto [v, cap] = e[id];
                if (cap > 0 && !vis[v]) { // 只走残量网络中仍能通过的边
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        return vis;
    }
};
```

**使用示例**：以下代码接在结构体后即可运行，输出 `5`。

```cpp
int main() {
    Dinic mf(4, 1, 4);                 // 4 个点，源点 1，汇点 4
    mf.add_edge(1, 2, 3);
    mf.add_edge(1, 3, 2);
    mf.add_edge(2, 3, 1);
    mf.add_edge(2, 4, 2);
    mf.add_edge(3, 4, 3);
    cout << mf.maxflow() << '\n';
    auto side = mf.mincut_side();      // 本例 S = {1}，T = {2, 3, 4}
}
```

继续阅读：[费用流](费用流.md) 用最短路选择增广路；[上下界网络流](上下界网络流.md) 复用本模板处理边的流量下界、可行流和流量最值。
