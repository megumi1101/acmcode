#include <bits/stdc++.h>
using namespace std;
 
#define int long long
const int inf = 1e18;
 
void sol() {
    int n, L, K;
    cin >> n >> L >> K;
    string s;
    cin >> s;
 
    vector dp(n + 1, vector<pair<int, int>>(2, {-inf, -inf}));
 
    dp[0][0] = dp[0][1] = {0, 0};
 
    for (int i = 0; i < n; i++) {
        int req = (s[i] == 'A' ? 0 : (s[i] == 'B' ? 1 : 2));
        for (int c = 0; c < 2; c++) {
            auto [cost, rem] = dp[i][c];
            if (cost <= -inf / 2) continue;
            if (rem == 0) {
                if (req == 0 || req == 2) {
                    dp[i + 1][0] = max(dp[i + 1][0], {cost - 1, L - 1});
                }
                if (req == 1 || req == 2) {
                    dp[i + 1][1] = max(dp[i + 1][1], {cost - 1, L - 1});
                }
            } else {
                if (req == c || req == 2) {
                    dp[i + 1][c] = max(dp[i + 1][c], {cost, rem - 1});
                }
                int nxt = min(n, i + rem);
                dp[nxt][1 - c] = max(dp[nxt][1 - c], {cost - 1, L - (nxt - i)});
            }
        }
    }
 
    int ans = max(dp[n][0].first, dp[n][1].first);
    cout << (-ans) * K << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) sol();
}
