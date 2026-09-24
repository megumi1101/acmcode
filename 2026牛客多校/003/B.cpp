#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 998244353, inf = 1e9;
vector<int> fac, ifac, inv;

int fap(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

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
    int n, m, c, A, B;
    cin >> n >> m >> c >> A >> B;

    int tc = A * fap(B, mod - 2) % mod;
    int t0 = (1 - tc + mod) % mod;
    int ans = 0;
    if ((m - n) % c == 0 && m >= n) {
        int t = (m - n) / c;
        ans = C(m, t) * fap(tc, t) % mod * fap(t0, m - t) % mod * n % mod * inv[m]  % mod;
    }
    cout << ans << "\n";
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init(2e6);
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
}

/*
4
1 1 2 1 2
1 3 2 1 2
2 2 3 1 3
1 2 2 1 2
*/