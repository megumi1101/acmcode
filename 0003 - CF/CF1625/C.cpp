#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    constexpr int inf = 1e18;
    void sol() {
        int n, l, k;
        cin >> n >> l >> k;
        vector<int> d(n + 5), a(n + 5);
        vector<vector<vector<int>>> f(2, vector<vector<int>> (n + 5, vector<int>(n + 5, inf)));
        vector<vector<int>> g(2, vector<int>(n + 5, inf));
        for (int i = 0; i < n; i++) cin >> d[i];
        d[n] = l;
        for (int i = 0; i < n; i++) cin >> a[i];
        f[0][0][0] = 0;
        g[0][0] = 0;
        int op = 0;
        for (int i = 1; i < n; i++) {
            op ^= 1;
            fill(g[op].begin(), g[op].end(), inf);
            for (int j = 0; j <= k; j++) {
                fill(f[op][j].begin(), f[op][j].end(), inf);
                for (int t = 0; t <= i; t++) {
                    if (t == i) {
                        f[op][j][t] = g[op ^ 1][j];
                    }
                    else {
                        if (j >= 1) f[op][j][t] = f[op ^ 1][j - 1][t] + (d[i + 1] - d[i]) * (a[t] - a[i]);
                    }
                    g[op][j] = min(g[op][j], f[op][j][t]);
                }
            }
        }
        int ans = inf;
        for (int j = 0; j <= k; j++) {
            ans = min (ans, g[op][j]);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += (d[i + 1] - d[i]) * (a[i]);
        }
        cout << res + ans << "\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
    #undef int
}
 
int main() {
    return Xbbbz ::main(), 0;
}
