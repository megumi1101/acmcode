#include <bits/stdc++.h>
using namespace std;

namespace Xbbbz {
#define int long long
const int inf = 1e18;
    void sol() {
        int n, m;
        cin >> n >> m;
        vector<vector<pair<int, int>>> ed(n + 1);
        vector<int> dis(n + 1, inf), cnt(n + 1, 0);
        vector<bool> inq(n + 1, 0), vis(n + 1, 0);
        for (int i = 1; i <= m; i++) {
            int y, x, z;
            cin >> y >> x >> z;
            ed[x].push_back({y, z});
        }
        auto cycle = [&](int s) -> bool {
            queue<int> q;
            q.push(s), dis[s] = 0; inq[s] = 1;
            while (!q.empty()) {
                int u = q.front(); q.pop(); inq[u] = 0;
                vis[u] = 1;
                for (auto [v, w] : ed[u]) {
                    if (dis[v] > dis[u] + w && dis[u] != inf) {
                        dis[v] = dis[u] + w;
                        if (++cnt[v] >= n) return 1;
                        if (!inq[v]) { q.push(v); inq[v] = 1; }
                    }
                }
            }
            return 0;
        };

        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            if (cycle(i)) {
                cout << "NO\n";
                return;
            }
        }

        for (int i = 1; i <= n; i++) cout << dis[i] << " ";
        cout << "\n";
    }

    void main() {
        ios::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
#undef int
}

int main() {
    return Xbbbz::main(), 0;
}
