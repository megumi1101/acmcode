#include<bits/stdc++.h>
 
using namespace std;
 
const int inf = 1e9;
 
void sol() {
    int n, k, V;
    cin >> n >> k >> V;
    
    vector<vector<int>> ed(n + 1);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ed[x].push_back(y);
        ed[y].push_back(x);
    }
 
 
    
    auto dfs = [&](auto &&self, int u, int fat) -> int {
        if (ed[u].size() == 1) {
            return 0;
        }
 
        int mn = inf;
        for (auto v : ed[u]) if (v != fat) {
            int d = self(self, v, u) + 1;
            if (mn + d <= k + 1) {
                return 0;
            }
            mn = min(d, mn);
        }
        return mn;
    };
 
    if (dfs(dfs, V, 0) == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
