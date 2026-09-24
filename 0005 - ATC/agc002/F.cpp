// AtCoder user: lnxbb
// Contest: agc002
// Problem: agc002_f
// Submission: https://atcoder.jp/contests/agc002/submissions/75244942
// Language: C++23 (GCC 15.2.0)

#include<bits/stdc++.h>

using namespace std;

#define int long long
const int mod = 1e9 + 7, inf = 1e9;
vector<int> fac, facn, inv;
void init(int n) {
    fac.assign(n + 1, 0);
    facn.assign(n + 1, 0);
    inv.assign(n + 1, 0);
    fac[0] = fac[1] = facn[0] = facn[1] = inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
        facn[i] = facn[i - 1] * inv[i] % mod;
    }
}

int C (int i, int j) {
    return fac[i] * facn[j] % mod * facn[i - j] % mod;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    init(n * k + 10);

    if (k == 1) {
        cout << "1\n";
        return 0;
    }
    vector f(n + 1, vector(n + 1, 0));
    f[n][n] = 1;
    for (int i = n; i >= 0; i--) {
        for (int j = n; j >= i; j--) {
            int x = i - 1;
            int y = j;
            if (y >= x && x >= 0 && y >= 0) {
                f[x][y] += f[i][j];
                f[x][y] %= mod;
            }

            x = i;
            y = j - 1;
            if (y >= x && x >= 0 && y >= 0) {
                f[x][y] += f[i][j] * C(i + (k - 1) * j - 1, k - 2) % mod;
                f[x][y] %= mod;
            }
        }
    }
    int ans = f[0][0] * fac[n] % mod;
    cout << ans << "\n";
}
