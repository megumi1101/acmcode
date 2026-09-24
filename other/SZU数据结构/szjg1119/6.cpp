#include <bits/stdc++.h>
using namespace std;

#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int INF = (1LL << 60);

    int N, M;
    while (cin >> N >> M) {
        vector<vector<pair<int, int>>> g(N + 1);

        for (int i = 0; i < M; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            g[u].push_back({v, w});
            g[v].push_back({u, w});   
        }

        vector<int> dist(N + 1, INF);
        vector<int> vis(N + 1, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        dist[1] = 0;
        pq.push({0, 1});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (vis[u]) continue;
            vis[u] = 1;
            if (u == N) break;    
            for (auto [v, w] : g[u]) {
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        if (dist[N] == INF) {
            cout << -1 << '\n';
        } else {
            cout << dist[N] << '\n';
        }
    }

    return 0;
}
