// AtCoder user: lnxbb
// Contest: arc058
// Problem: arc058_b
// Submission: https://atcoder.jp/contests/arc058/submissions/62671587
// Language: C++ 20 (gcc 12.2)

#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
    #define int long long

    const int N = 2e5 + 10;
    const int mod = 1e9 + 7;

    int fac[N], inv[N], faci[N];

    void init() {
        int n = 2e5;
        fac[0] = faci[0] = inv[1] = fac[1] = faci[1] = 1;
        for (int i = 2; i <= n; i++) {
            fac[i] = fac[i - 1] * i % mod;
            inv[i] = inv[mod % i] * (mod - mod / i) % mod;
            faci[i] = faci[i - 1] * inv[i] % mod;
        }
    }

    int C(int i, int j) {
        return fac[i] * faci[j] % mod * faci[i - j] % mod;
    }

    void sol() {
        int n, m, a, b; 
        cin >> n >> m >> a >> b;
        int ans = 0;
        for (int i = 1; i <= b; i++) {
            ans += C(n - a + i - 2, i - 1) * C(a + m - i - 1,a - 1) % mod ;
            ans %= mod;
        }
        ans = C(n + m - 2, n - 1) - ans;
        ans = (ans % mod + mod) % mod;
        cout << ans; 
    }

    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        init();
        int T = 1;
        // cin >> T;
        while (T--) {
            sol();
        }
    }

    #undef int 
}

int main() {
    return Xbbbz::main(), 0;
}