#include <bits/stdc++.h>
 
using namespace std;

#define int long long
const int mod = 1e9 + 7, inf = 1e9;
vector<int> fac, ifac, inv;

void init(int n) {
    fac.assign(n + 1, 1);
    ifac.assign(n + 1, 1);
    inv.assign(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
        ifac[i] = ifac[i - 1] * inv[i] % mod;
    }
}

int C(int n, int m) {
    if (n < 0 || m < 0 || n < m) return 0;
    return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int ans = 1;
    auto dfs = [&](this auto &&dfs, int l, int r) -> bool {
        if (l > r) return 1;
        int tl = l, tr = r;
        bool fg = 0;
        while (tl <= tr) {
            if (a[tl] == (tl - l + 1) * (r - tl + 1)) {
                fg |= (dfs(l, tl - 1) && dfs(tl + 1, r));
                ans *= C(r - l, tl - l);
                ans %= mod;
                break;
            }
            if (a[tr] == (tr - l + 1) * (r - tr + 1)) {
                fg |= (dfs(l, tr - 1) && dfs(tr + 1, r));
                ans *= C(r - l, tr - l);
                ans %= mod;
                break;
            }
            tl++;
            tr--;
        }
        return fg;
    };

    if (!dfs(1, n)) ans = 0;

    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init(1e6);
    int t;
    cin >> t;
    while (t--) sol();
}
/*
4
3
1 4 1
4
1 2 3 4
4
1 6 1 2
3
3 3 3
*/