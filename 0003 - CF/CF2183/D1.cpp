#include <bits/stdc++.h>
 
using namespace std;
 
void sol() {
    int n;
    cin >> n;
    
    vector<vector<int>> ed(n + 1);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ed[x].push_back(y);
        ed[y].push_back(x);
    }
    
    vector dep(n + 1, 0);
    vector siz (n + 1, 0);
    int ans = 0;
    auto dfs = [&] (auto &&dfs, int u, int fat) -> void {
        dep[u] = dep[fat] + 1;
        ans = max(ans, (int)ed[u].size() + (u == 1));
        for (auto v : ed[u]) if (v != fat) {
            dfs(dfs, v, u);
        }
        siz[dep[u]]++;
    };
    dfs(dfs, 1, 0);
    for (int i = 1; i <= n; i++) ans = max(ans, siz[i]);
    cout << ans << "\n";
}
 
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
 
    int T;
    cin >> T;
    while (T--) sol();
}
