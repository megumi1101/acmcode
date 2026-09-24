#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    void sol() {
        int n;
        cin >> n;
        vector<vector<int>> ed(n + 1);
        vector<int> dep(n + 1), g(n + 1), son(n + 1), f(n + 1);
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            ed[u].push_back(v);
            ed[v].push_back(u);
        }
 
        auto dfs = [&](auto &&dfs, int u, int fat) -> void {
            g[u] = dep[u];
            for (auto v: ed[u]) if (v != fat) {
                dep[v] = dep[u] + 1;
                dfs(dfs, v, u);
                f[min(g[u], g[v])] = max(f[min(g[u], g[v])], g[u] + g[v] - 2 * dep[u] + 1);
                g[u] = max(g[u], g[v]);
            }
        };
 
        dfs(dfs, 1, 0);
        
        for (int i = n - 1; i >= 0; i--) {
            f[i] = max(f[i], f[i + 1]);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            while (ans < g[1] && f[ans + 1] / 2 + i > ans) ans++;
            cout << ans << " ";
        }
        cout << "\n";
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
}
 
int main() {
    return Xbbbz :: main(), 0;
}
