#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
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
 
    int s = 0;
    for (int i = 1; i <= n; i++) {
        if (ed[i].size() > 1) s = i;
    }
 
    vector<int> siz(n + 1), f(n + 1);
 
    [&](this auto &&dfs, int u, int fat) -> void {
        if (ed[u].size() == 1) {
            siz[u] = 1;
        }
        for (auto v : ed[u]) if (v != fat) {
            dfs(v, u);
            siz[u] ^= siz[v];
            f[u] += f[v];
            if (siz[v]) f[u]++;
        }
    } (s, 0);
 
    if (siz[s] == 0) {
        cout << f[s] << "\n";
        return;
    }
 
    auto change = [&](int u, int v) -> void {
        int sizu = siz[u];
        int sizv = siz[v];
        int fu = f[u];
        int fv = f[v];
        siz[u] = sizu ^ sizv;
        siz[v] = sizu;
        f[u] = fu - fv - sizv;
        f[v] = fv + siz[u] + f[u];
    };
 
    int ans = f[s];
    [&](this auto &&dfs, int u, int fat) -> void {
        for (auto v : ed[u]) if (v != fat) {
            change(u, v);
            ans = min(ans, f[v]);
            dfs(v, u);
            change(v, u);
        }
    } (s, 0);
 
    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
 
/*
1
5
1 2
1 3
3 4
3 5
 
*/
