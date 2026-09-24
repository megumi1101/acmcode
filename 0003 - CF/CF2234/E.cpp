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
        int x = l;
        while (1) {
            int sizl = x - l;
            if (a[x] % (sizl + 1)) {
                return 0;
            }
            int sizr = a[x] / (sizl + 1) - 1;
            if (x + sizr > r) {
                return 0;
            }
            ans *= C(sizl + sizr, sizl);
            ans %= mod;
            if (!dfs(x + 1, x + sizr)) {
                return 0;
            }
            if (x + sizr == r) break;
            x = x + sizr + 1;
        }
        return 1;
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
