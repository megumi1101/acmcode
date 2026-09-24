#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
const int mod = 998244353;
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
    
    vector<int> mx(n + 1), bel(n + 1), f(n + 1), pref(n + 1), out(n + 1);
    int mxleaf = 0;
    [&](this auto&& dfs, int u, int fat) -> void {
        if (ed[u].size() == 1) mxleaf = max(mxleaf, u);
        for (auto v : ed[u]) if (v != fat) {
            bel[v] = (u == n ? v : bel[u]);
            dfs(v, u);
            mx[u] = max({v, mx[u], mx[v]});
        }
 
        if (u == n) {
            set<int> s;
            for (auto v : ed[u]) if (v != fat) {
                s.insert(max(v, mx[v]));
            }
            for (auto v : ed[u]) if (v != fat) {
                s.erase(max(v, mx[v]));
                out[v] = s.empty() ? 0 : *s.rbegin();
                s.insert(max(v, mx[v]));
            }
        }
    }(n, 0);
 
    if (mxleaf == n) {
        cout << "1\n";
        return;
    }
    
    int ans = 0;
    for (int i = mxleaf; i < n; i++) {
        if (i == mxleaf) f[i] = 1;
        else if (i > mx[i]) f[i] = pref[i - 1] - pref[mx[i]];
        f[i] = (f[i] % mod + mod) % mod;
        pref[i] = (pref[i - 1] + f[i]) % mod;
        if (out[bel[i]] < i) ans = (ans + f[i]) % mod;
    }
    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
