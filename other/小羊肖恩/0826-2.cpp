#include <bits/stdc++.h>

using namespace std;

#define int long long
const int inf = 1e9;

signed main() {
    int n, m;
    cin >> n >> m;
    vector<int> c(n + 1);
    vector<vector<int>> ed(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        ed[x].push_back(y);
        ed[y].push_back(x);
    }

    int ans = 0;
    vector<int> fa(n + 1, -1), opp(n + 1);
    auto get = [&](int u) -> void {
        bool fg = 0;
        array<int, 2> mn{inf, inf};
        array<int, 2> cnt{};
        auto dfs = [&](auto self, int u, int fat, int op) -> void {
            cnt[op]++;
            opp[u] = op;
            mn[op] = min(c[u], mn[op]);
            fa[u] = fat;
            for (auto v : ed[u]) {
                if (v == fat) continue;
                if (fa[v] != -1) {
                    if (opp[u] == opp[v]) fg = 1;
                    continue;
                }
                self(self, v, u, op ^ 1);
            }
        };
        dfs(dfs, u, 0, 0);
        
        if (fg) {
            cnt[0] = cnt[0] + cnt[1];
            cnt[1] = 0;
        }
        
        ans += (cnt[0]) * (cnt[0] - 1) / 2;
        ans += (cnt[1]) * (cnt[1] - 1) / 2;
    };
   
    for (int i = 1; i <= n; i++) {
        if (fa[i] == -1) get(i);
    }

    cout << ans << "\n";
}