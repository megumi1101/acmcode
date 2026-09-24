#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
    #define int long long
    #define db double
    const int N = 1e5 + 10;
    const int mod = 1e9 + 7;
    int n, k, f[510][510][6];
    string s;
    bool pd(int a, int b) {
        return (s[a] == '(' || s[a] == '?') && (s[b] == ')' ||s[b] == '?');
    }
    void sol() {
        cin >> n >> k;
        
        cin >> s;
        s = " " + s;
        for (int i = 1; i <= n; i++) {
            f[i][i - 1][0] = 1;
        }
        for (int i = 1; i <= n; i++)
            for (int j = i; j <= n; j++) {
                if (j - i + 1 <= k) {
                    f[i][j][0] = f[i][j - 1][0] && (s[j] == '*' || s[j] == '?');
                }
            }
        for (int len = 2; len <= n; len++) {
            for (int i = 1; i <= n - len + 1; i++) {
                int j = i + len - 1;
                if (pd(i, j)) {
                    f[i][j][1] = (f[i + 1][j - 1][0] + f[i + 1][j - 1][2] + f[i + 1][j - 1][3] + f[i + 1][j - 1][4]) % mod;
                }
                for (int k = i; k <= j - 1; k++) {
                    (f[i][j][2] += f[i][k][3] * f[k + 1][j][0]) %= mod;
                    (f[i][j][3] += (f[i][k][2] + f[i][k][3]) * f[k + 1][j][1]) %= mod;
                    (f[i][j][4] += f[i][k][0] * f[k + 1][j][3]) %= mod;
                }
                (f[i][j][3] += f[i][j][1]) %= mod;
            }
        }
        cout << f[1][n][3] << "\n";
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
