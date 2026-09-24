#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x << " = " << x << '\n'

void sol() {
    int n, m;
    cin >> n;
    vector<vector<int>> ed(n + 1);
    vector<int> p(n + 1);
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
        ed[p[i]].push_back(i);
    }

    cin >> m;
    vector<int> a(m), vis(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        vis[a[i]] = 1;
    }

    vector<int> siz(n + 1);
    vector<int> ans;
    auto dfs = [&](this auto &&dfs, int u) -> void {
        bool fg = 1;
        if (vis[u]) siz[u]++, fg = 0;
        for (auto v : ed[u]) {
            dfs(v);
            siz[u] += siz[v];
            if (siz[v] >= 1) {
                if (fg) {
                    fg = 0;
                    continue;
                }
                ans.push_back(v);
            }
        }
    };
    dfs(1);

    cout << ans.size() << " ";
    for (auto x : ans) cout << x << " ";
    cout << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        sol();
    }
}