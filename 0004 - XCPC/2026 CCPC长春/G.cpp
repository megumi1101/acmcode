#include <bits/stdc++.h>

using namespace std;

void sol() {
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    vector<int> c(n), d(n + 1);
    for (int i = 0; i < n; i++) {
        c[i] = (a[i] - '0') ^ (b[i] - '0');
        if (i) d[i] = c[i] ^ c[i - 1];
        else d[i] = c[i];
    }
    d[n] = c[n - 1];

    vector<vector<pair<int, int>>> ed(n + 1);
    for (int id = 1; id <= m; id++) {
        int l, r;
        cin >> l >> r;
        ed[l - 1].push_back({r, id});
        ed[r].push_back({l - 1, id});
    }

     {
        string ans(m, '1');
        int tim = 0;
        vector<int> dfn(n + 1), low(n + 1), bel(n + 1), xo(n + 1);
        auto dfs = [&](auto&& self, int u, int pe) -> void {
            dfn[u] = low[u] = ++tim;
            xo[u] = d[u];
            for (auto [v, id] : ed[u]) {
                if (id == pe) continue;
                if (!dfn[v]) {
                    self(self, v, id);
                    xo[u] ^= xo[v];
                    low[u] = min(low[u], low[v]);
                    if (low[v] > dfn[u]) {
                        if (xo[v]) ans[id - 1] = '0';
                    }
                } else low[u] = min(low[u], dfn[v]);
            }
        };

        bool fg = 1;
        for (int i = 0; i <= n; i++) {
            if (!dfn[i]) {
                dfs(dfs, i, -1);
                if (xo[i]) fg = 0;
            }
        }

        if (!fg) ans.assign(m, '0');
        cout << ans << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) sol();
    
}