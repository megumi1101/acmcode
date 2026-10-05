#include <bits/stdc++.h>

using namespace std;

#define int long long
int mod;
vector<int> fac, p2;
vector<vector<int>> s;

void init(int n) {
    fac.assign(n + 1, 1);
    p2.assign(n + 1, 1);
    p2[1] = 2;
    for (int i = 2; i <= n; i++) {
        fac[i] = fac[i - 1] * i % mod;
        p2[i] = p2[i - 1] * 2 % mod;
    }
    s.assign(n + 1, vector<int>(n + 1));
    s[0][0] = 1;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= i; j++)
        s[i][j] = (s[i - 1][j - 1] + j * s[i - 1][j]) % mod;
}

signed main() {
    int n;
    cin >> n >> mod;
    init(1000);

    int ans = 0;
    for (int k = 1; n - 2 * k + 1 >= 0; k++) {
        ans += fac[k] * s[n - k + 1][k] % mod * p2[n - 2 * k + 1] % mod;
        ans %= mod;
    }
    cout << ans << "\n";
}