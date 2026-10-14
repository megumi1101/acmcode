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
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}

signed main() {
    init(2e5 + 100);
    int n, k;
    cin >> n >> k;
    int t = n - k;
    if (t <= 0) cout << "0\n";
    else if (t == n) {
        cout << fac[n] << "\n";
    }
    else {
        int res = 0;
        for (int i = 0; i < t; i++) {
            int op = 1;
            if (i & 1) op = -1;
            res = res + op * fap(t - i, n) * C(t, i) % mod;
            res %= mod;
            if (res < 0) res += mod;
        }

        int ans = C(n, t) * res % mod;
        ans = ans * 2 % mod;
        cout << ans << "\n";
    }
}