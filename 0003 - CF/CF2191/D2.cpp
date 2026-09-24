#include <bits/stdc++.h>
 
using namespace std;
const int mod = 998244353;
 
void add(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}
 
void sol() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    vector<vector<vector<vector<int>>>> f(n + 1);
    vector<vector<vector<vector<int>>>> nf(n + 1);
    
    for (int len = 0; len <= n; len++) {
        f[len].resize(len + 1);
        nf[len].resize(len + 1);
        for (int mxpre = 0; mxpre <= len; mxpre++) {
            f[len][mxpre].resize(len + 1, vector<int>(2, 0));
            nf[len][mxpre].resize(len + 1, vector<int>(2, 0));
        }
    }
 
    f[0][0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        int x;
        if (s[i] == '(') x = 1;
        else x = -1;
        nf = f;
        for (int len = 0; len <= i; len++) {
            for (int mxpre = 0; mxpre <= len; mxpre++) {
                for (int pre = 0; pre <= len; pre++) {
                    for (int op = 0; op < 2; op++) {
                        if (!nf[len][mxpre][pre][op]) continue;
                        if (len + 1 <= n) {
                            if (pre + x < 0 || pre + x > n) continue;
                            if (!op) {
                                if (x == 1 && pre + x > mxpre) {
                                    add(f[len + 1][pre + x][pre + x][op], nf[len][mxpre][pre][op]);
                                }
                                else if (x == -1) {
                                    add(f[len + 1][mxpre][pre + x][1], nf[len][mxpre][pre][op]);
                                } 
                            }
                            else {
                                add(f[len + 1][mxpre][pre + x][1], nf[len][mxpre][pre][1]);
                            }
                        }
                    }
                }
            }
        }
    }
    
 
    int ans = 0;
    for (int i = 6; i <= n; i += 2) {
        for (int j = 1; j < i / 2 - 1; j++) {
            add(ans, ((long long)f[i][j][0][1]  * (i - 2) % mod));
        }
    }
    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
 
    int T;
    cin >> T;
    while (T--) sol();
}
