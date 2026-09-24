#include <bits/stdc++.h>
 
using namespace std;
#define int long long
 
const int mod = 1e9 + 7;
void sol() {
    int n;
    string s;
    cin >> n >> s;
    vector dp(2 * n + 1, array<int, 3>{0, 0, 0});
    dp[n][0] = 1;
    for (auto c : s) {
        auto ndp = dp;
        if (c == 'P') {
            for (int i = 0; i < 2 * n; i++) {
                (ndp[i + 1][0] += dp[i][0]) %= mod;
            }
        } else if (c == 'I') {
            for (int i = 1; i <= 2 * n; i++) {
                (ndp[i - 1][1] += dp[i][1]) %= mod;
            }
            for (int i = n + 1; i <= 2 * n; i++) {
                (ndp[i - 1][1] += dp[i][0]) %= mod;
            }
        } else {
            for (int i = 0; i < 2 * n; i++) {
                (ndp[i + 1][2] += dp[i][2]) %= mod;
            }
            for (int i = 0; i < 2 * n; i++) {
                (ndp[i + 1][2] += dp[i][1]) %= mod;
            }
        }
        dp = move(ndp);
    }
 
    int ans = 0;
    for (int i = 0; i <= n + 1; i++) ans = (ans + dp[i][2]) % mod;
    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
 
/*
2
4
PIIG
7
PPIIIGG
*/
