#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
const int mod = 998244353;
 
vector<int> fac, facn, inv;
void init() {
    int n = 1e6;
    fac.assign(n + 5, (int)0);
    facn.assign(n + 5, (int)0);
    inv.assign(n + 5, (int)0);
    fac[0] = fac[1] = facn[0] = facn[1] = inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = inv[mod % i] * (mod - mod / i) % mod;
        facn[i] = facn[i - 1] * inv[i] % mod;
    }
}
 
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
 
    vector<int> siz(n + 1);
    vector<int> a;
    int mi = 0;
    int r = n;
    int mul = 1;
    auto dfs = [&](auto &&dfs, int u, int fat) -> void {
        siz[u] = 1;
        for (auto v : ed[u]) if (v != fat) {
            dfs(dfs, v, u);
            if (siz[v] & 1) siz[u] += siz[v];
        }
        if (! (siz[u] & 1) && u != 1) {
            a.push_back(siz[u]);
            r -= siz[u];
            mul *= siz[u]; mul %= mod;
            mul *= siz[u]; mul %= mod;
        }
    };
    
    dfs(dfs, 1, 0);
    if (a.empty()) {
        cout << 1 << "\n";
        return;
    }
    int ans = 0;
    for (auto x : a) {
        ans += mul * inv[x] % mod;
        ans %= mod;
    }
    ans *= fac[a.size() - 1] * r % mod;
    ans %= mod;
    cout << ans << "\n";
    
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int T;
    cin >> T;
    
    while (T--) {
        sol();
    }
    return 0;
}
