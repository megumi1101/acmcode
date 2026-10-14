#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

int fap(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;

    init(2e5 + 10);
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int op = 1;
        if (i & 1) op = -1;
        int res = fap(k, n - i) * fap(k - 1, i) % mod - fap(k - 1, n);
        res %= mod;
        if (res < 0) res += mod;
        res = fap(res, n);
        res *= C(n, i);
        res %= mod;
        if (res < 0) res += mod;
        
        ans += op * res;
        ans %= mod;
        if (ans < 0) ans += mod;
    }
    cout << ans << "\n";
}