#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
    #define int long long
    #define db double
    const int N = 105;
    db f[N], dp[N][N], g[N][N];
    void sol() {
        int q, n;
        cin >> q >> n;
        dp[1][0] = 1.0;
        dp[2][1] = 1.0;
        for (int i = 0; i <= n; i++) g[1][i] = 1.0;
        for (int i = 1; i <= n; i++) g[2][i] = 1.0;
        if (q == 1) {
            f[1] = 0;
            for (int i = 2; i <= n; i++) {
                f[i] = (f[i  - 1] * (db)i + 2.0) / (db)i;
            }
            cout << fixed << setprecision(6) << f[n];
        }
        else {
            for (int i = 3; i <= n; i++) {
                for (int j = 1; j < i; j++) {
                    for (int k = 1; k <= i - 1; k++) {
                        dp[i][j] += (dp[k][j - 1] * g[i - k][j - 1] + dp[i - k][j - 1] * g[k][j - 1] - dp[k][j - 1] * dp[i - k][j - 1]) / (db)(i - 1);
                    }
                    g[i][j] = g[i][j - 1] + dp[i][j];
                }
                for (int j = i; j <= n; j++) {
                    g[i][j] = g[i][i - 1];
                }
            }
            db ans = 0;
            for (int i = 0; i <= n; i++) {
                ans += dp[n][i] * (db)i;
            }
            cout << fixed << setprecision(6) << ans;
        }
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }   
    
    #undef int
}
int main() {
    return Xbbbz::main(), 0;
}
/*
1 3
5 4 3
*/