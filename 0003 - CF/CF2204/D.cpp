#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
void sol() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ed(n + 1);
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        ed[x].push_back(y);
        ed[y].push_back(x);
    }
 
 
    int ans = 0;
    vector<int> col(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        if (col[i] != -1) continue;
        array<int, 2> cnt {};
        bool fg = 1;
        auto dfs = [&](auto &&dfs, int u, int c) -> void {
            col[u] = c;
            cnt[c]++;
            for (auto v : ed[u]) {
                if (col[v] == -1) {
                    dfs(dfs, v, c ^ 1);
                } else if (col[v] == c) {
                    fg = 0;
                }
            }
        };
        dfs(dfs, i, 0);
        ans += (int)fg * max(cnt[0], cnt[1]);
    }
    cout << ans << "\n";
    
}
 
signed main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) sol();
}
