#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> g(n);
    vector<int> indeg(n, 0);
    for (int i = 0; i < m; ++i) {
        int u, v; int w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        ++indeg[v];
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) if (indeg[i] == 0) q.push(i);
    vector<int> topo;
    topo.reserve(n);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (auto [v, w] : g[u]) {
            if (--indeg[v] == 0) q.push(v);
        }
    }

    vector<int> ve(n, 0);
    for (int u : topo) {
        for (auto [v, w] : g[u]) {
            ve[v] = max(ve[v], ve[u] + w);
        }
    }

    int T = 0;
    for (int i = 0; i < n; ++i) T = max(T, ve[i]);
    vector<int> vl(n, T);
    for (int i = (int)topo.size() - 1; i >= 0; --i) {
        int u = topo[i];
        for (auto [v, w] : g[u]) {
            vl[u] = min(vl[u], vl[v] - w);
        }
    }

    for (int i = 0; i < n; ++i) cout << ve[i] << ' ';
    cout << '\n';
    for (int i = 0; i < n; ++i) cout << vl[i] << ' ';
    cout << '\n';
    return 0;
}
