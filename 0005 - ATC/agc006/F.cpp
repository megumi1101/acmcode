#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> ed(n + 1);
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        ed[x].push_back({y, 1});
        ed[y].push_back({x, 2});
    }

    int ans = 0;
    
    vector<int> vis(n + 1), cols(n + 1);
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;

        bool fg = 0;
        int cnt = 0;
        vector<int> v;
        array<int, 3> c{};
        [&](this auto &&dfs, int u, int col) {
            if (vis[u]) {    
                if (cols[u] != col) fg = 1;
                return;
            }
            cols[u] = col;
            c[cols[u]]++;
            vis[u] = 1;
            cnt++;
            v.push_back(u);
            for (auto [v, dif] : ed[u]) {
                dfs(v, (col + dif) % 3);
            }
        } (i, 0);

        int cnte = 0;
        for (auto u : v) cnte += (int)ed[u].size();
        cnte >>= 1;
        
        if (fg) {
            ans += cnt * cnt;
        } else {
            if (c[0] && c[1] && c[2]) {
                ans += c[0] * c[1] + c[1] * c[2] + c[2] * c[0];
            } else {
                ans += cnte;
            }
        }
    }

    cout << ans << "\n";
}