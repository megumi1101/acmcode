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
    int res = 1;
    for (int i = 0; i < m; i++) {
        res = (__int128)1 * res * (n - i) % mod;
    }
    res = res * ifac[m] % mod;
    return res;
}

signed main() {
    init(1e5);
    int n, s;
    cin >> n >> s;
    vector<int> f(n);
    for (int i = 0; i < n; i++) cin >> f[i];

    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        int op = 1;
        int up = s + n - 1;
        int dn = n - 1;
        if (popcount((unsigned long long)i) & 1) op = -1;
        for (int bit = 0; bit < n; bit++) {
            if ((i >> bit) & 1) {
                up -= f[bit] + 1;
            }
        }
        ans += op * C(up, dn);
        ans %= mod;
        if (ans < 0) ans += mod;
    }
    cout << ans << "\n";
}

/*
2 4
2 2
*/