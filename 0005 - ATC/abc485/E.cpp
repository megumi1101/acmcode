#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> ed(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        ed[u].push_back({v, c});
    }

    vector<map<int, int>> dis(n + 1);
    vector<int> cnt(n + 1);
    auto bfs = [&] (int s) -> void {
        dis[s][-1] = 0;
        queue<array<int, 3>> q;
        q.push({dis[s][-1], s, -1});
        map<pair<int, int>, int> vis;
        while (!q.empty()) {
            auto[cost, u, lst] = q.front();
            q.pop();
            if (cnt[u] >= 2) continue;
            if (vis[{u, lst}]) continue;
            cnt[u]++;
            vis[{u, lst}] = 1;
            for (auto[v, c] : ed[u]) {
                if (c == lst) continue;
                if (dis[v].find(c) == dis[v].end()) {
                    dis[v][c] = cost + 1;
                    q.push({cost + 1, v, c});
                }
            }
        }
    };
    bfs(1);

    int ans = inf;
    for (auto [x, y] : dis[n]) ans = min(ans, y);
    if (ans == inf) ans = -1;
    cout << ans << "\n";
}

/*
6 10
1 2 1
2 4 2
2 5 2
3 6 5
4 3 3
5 2 3
5 3 2
5 6 2
6 1 3
6 5 3

*/