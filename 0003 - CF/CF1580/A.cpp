#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    const int inf = 1e18;
    int sum[405][405];
    string s[405];
    int dp[405][405];
    int s1(int i, int j, int x, int y) {
        return sum[x][y] - sum[i - 1][y] - sum[x][j - 1] + sum[i - 1][j - 1];
    }
    int s0(int i, int j, int x, int y) {
        return (x - i + 1) * (y - j + 1) - s1(i, j, x, y);
    }
    void sol() {
        int n, m;
        cin >> n >> m;
        
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                sum[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; i++) {
            cin >> s[i]; s[i] = ' ' + s[i];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (s[i][j] == '1');
            }
        }
        
        
            for (int j = 0; j <= n; j++) {
                for (int k = 0; k <= m; k++) {
                    dp[j][k] = inf;
                }
            }
        
        int ans = inf;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 4; j <= n; j++) {
                for (int k = 4; k <= m; k++) {
                    dp[j][k] = s0(i + 1, k - 3, j - 1, k - 3) + s0(i, k - 2, i, k - 1) + s0(j, k - 2, j, k - 1) + s1(i + 1, k - 2, j - 1, k - 1);
                    dp[j][k] = min (dp[j][k], dp[j][k - 1] + (s[i][k - 1] == '0') + (s[j][k - 1] == '0') + s1(i + 1, k - 1, j - 1, k - 1));
                    ans = min (ans, dp[j][k] + s0(i + 1, k, j - 1, k));
                }
            }
        }
        cout << ans << "\n";
    }
 
    void main() {
        int T;
        cin>>T;
        while(T--) sol();
    }
    #undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
