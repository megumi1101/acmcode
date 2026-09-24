#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
const int inf = 2e18;
    void sol() {
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        vector<vector<pair<int, int>>> ed(n);
        vector<int> dis(n, inf);
        for (int i = 0; i < m; i++) {
            int u, v, x, y;
            cin >> u >> v >> x >> y;
            ed[u].emplace_back(v, x << 30 | y);
        }

        auto dij = [&](int s) {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
            dis[s] = 0;
            q.emplace(dis[s], s);
            while (!q.empty()) {
                auto[cost, u] = q.top();
                q.pop();
                if (cost == dis[u]) {
                    for (auto[v, w] : ed[u]) {
                        if (dis[u] + w < dis[v]) {
                            dis[v] = dis[u] + w;
                            q.emplace(dis[v], v);
                        }
                    }
                }
            }
        };
        
        dij(s);

        int x = dis[t] >> 30;
        int y = dis[t] - (x << 30);
        cout << x << " " << y << "\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
#undef int
}

int main() {
    return Xbbbz::main(),0;
}