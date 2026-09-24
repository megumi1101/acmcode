#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
// #define int long long
    constexpr int N = 1e6 + 10;
    int ans = 0;
    
    void sol() {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> ed(n + 5);
        vector<int> a(n + 5), f(n + 5), g(n + 5);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i < n; i++) {
            int x, y;
            cin >> x >> y;
            ed[x].push_back(y);
            ed[y].push_back(x);
        }
        f[1] = g[1] = a[1];
        int ans = 0;
        function<void(int, int)> dfs = [&](int u, int fat) {
            for (int v : ed[u]) {
                if (v == fat) continue;
                if (a[v]) g[v] = g[u] + 1;
                f[v] = max(f[u], g[v]);
                dfs(v, u);
            }
            if (ed[u].size() == 1 && u != 1) {
                if (f[u] <= m) ans++;
            }
        };
        dfs(1, 0);
        cout << ans << "\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
#undef int
}

int main() {
    return Xbbbz ::main(), 0;
}
