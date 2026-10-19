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
    init(1e5 + 10);
    int n, k;
    cin >> n >>  k;
    if (n <= 1e5) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += C(n, i) * fap(i, k) % mod;
            ans %= mod;
        }
        cout << ans << "\n";
    } else {
        // i n * 2 ^ {n - 1};
        vector<int> f(k + 1);
        f[1] = n * fap(2, n - 1) % mod;

        vector<int> g(k + 1);
        g[1] = 1;
        for (int i = 2; i <= k; i++) {
            auto h = g;
            for (int j = k; j >= 1; j--) {
                h[j] = h[j - 1];
            }
            for (int j = 1; j <= k; j++) {
                h[j] -= g[j] * (i - 1) % mod;
                h[j] %= mod;
                if (h[j] < 0) h[j] += mod;
            } 
            
            int res = 1;
            for (int t = 0; t < i; t++) {
                res = res * (n - t);
                res %= mod;
            }
            f[i] = res * fap(2, n - i) % mod;
            
            for (int j = 1; j < i; j++) {
                f[i] -= f[j] * h[j] % mod;
                f[i] %= mod;
                if (f[i] < 0) f[i] += mod;
            }

            g = move(h);
        }
        cout << f[k] << "\n";
    }
}