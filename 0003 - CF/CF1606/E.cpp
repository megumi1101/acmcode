#include <bits/stdc++.h>

using namespace std;

#define int long long
const int mod = 998244353, inf = 1e9;
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

int fap(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    init(n);

    vector f(n + 1, vector<int>(x + 1, -1));
    auto dfs = [&](auto &&self, int n, int x) -> int {
        if (n == 1 && x >= 1) return x;
        if (n <= 0 || x <= 0) return 0;
        if (f[n][x] != -1) return f[n][x];

        int res = 0;
        for (int d = 0; d <= n; d++) {
            res += self(self, n - d, x - n + 1) * C(n, d) % mod * fap(n - 1, d) % mod;
            res %= mod;
        }
        return f[n][x] = res;
    };
    int ans = fap(x, n) - dfs(dfs, n, x);
    ans %= mod;
    if (ans < 0) ans += mod;
    cout << ans << "\n";
}