#include <bits/stdc++.h>
using namespace std;

struct InEdge { int u, v; };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<InEdge> E(m);
    vector<vector<int>> G(n + 1), GR(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        E[i] = {u, v};
        G[u].push_back(v);
        GR[v].push_back(u);
    }

    // 1) 1->n 可达性
    auto bfs = [&](const vector<vector<int>>& H, int s) {
        vector<int> vis(n + 1);
        queue<int> q; q.push(s); vis[s] = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : H[u]) if (!vis[v]) vis[v] = 1, q.push(v);
        }
        return vis;
    };
    vector<int> reach1 = bfs(G, 1);
    vector<int> reachn = bfs(GR, n);

    if (!reach1[n]) { cout << -1 << '\n'; return 0; }

    // 2) 只在好点/好边上建差分约束图
    struct CEdge { int to, w; };
    vector<vector<CEdge>> H(n + 1);
    vector<int> good(n + 1, 0);
    for (int i = 1; i <= n; ++i) if (reach1[i] && reachn[i]) good[i] = 1;

    vector<char> goodEdge(m, 0);
    for (int i = 0; i < m; ++i) {
        int u = E[i].u, v = E[i].v;
        if (good[u] && good[v]) {
            goodEdge[i] = 1;
            H[u].push_back({v, 9});   // x_v <= x_u + 9
            H[v].push_back({u, -1});  // x_u <= x_v - 1
        }
    }

    // 3) SPFA 仅在“好点”子图上跑；检测负环
    const long long INF = (1LL<<60);
    vector<long long> d(n + 1, 0);
    vector<int> inq(n + 1, 0), cnt(n + 1, 0);
    queue<int> q;
    for (int i = 1; i <= n; ++i) if (good[i]) { q.push(i); inq[i] = 1; }

    bool ok = true;
    while (!q.empty() && ok) {
        int u = q.front(); q.pop(); inq[u] = 0;
        for (auto e : H[u]) {
            int v = e.to; int w = e.w;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                if (!inq[v]) {
                    q.push(v); inq[v] = 1;
                    if (++cnt[v] > n) { ok = false; break; } // 负环
                }
            }
        }
    }
    if (!ok) { cout << -1 << '\n'; return 0; }

    // 4) 输出
    cout << n << ' ' << m << '\n';
    for (int i = 0; i < m; ++i) {
        int u = E[i].u, v = E[i].v;
        int w;
        if (goodEdge[i]) {
            w = int(d[v] - d[u]);         // 一定在 [1,9]
            if (w < 1 || w > 9) { cout << -1 << '\n'; return 0; } // 保险
        } else {
            w = 1; // 子图外随意给一个 1..9
        }
        cout << u << ' ' << v << ' ' << w << '\n';
    }
    return 0;
}
