#include<bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 998244353;

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

int Comb(int n, int m) {
    if (n < 0 || m < 0 || n < m) return 0;
    return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

signed main() {
    init(4e6);
    int A, B, C;
    cin >> A >> B >> C;
    int ans = 0;
    for (int i = 1; i <= B; i++) {
        int res = Comb(B + 1, i);
        res = res * Comb(C - 1, i - 1) % mod;
        int k = B + 1 - i;
        res = res * Comb(A + k - 1, k - 1) % mod;
        ans = (ans + res) % mod;
    }
    cout << ans << "\n";
}