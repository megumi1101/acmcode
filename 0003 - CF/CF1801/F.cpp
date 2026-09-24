#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
// #define int long long
#define db double
    void sol() {
        int n, k;
        cin >> n >> k;
        vector<int> a(n + 5), id(k + 5), v(1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        if (k == 1) {
            cout << 1;
            return;
        }
        k--;
        int m = 0;
        for (int l = 1, r; l <= k; l = r + 1) {
            r = k / (k / l);
            id[k / l] = ++m;
            v.push_back(k / l);
        }
        id[0] = ++m;
        v.push_back(0); 
        vector<vector<double>> f(n + 5, vector<double>(m + 5));
        f[0][1] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (f[i - 1][j]) {
                    for (int l = 1, r; l <= v[j]; l = r + 1) {
                        r = v[j] / (v[j] / l);
                        f[i][id[v[j] / l]] = max(f[i][id[v[j] / l]], a[i] / l / (db)a[i] * f[i - 1][j]);
                    }
                    f[i][m] = max(f[i][m], a[i] / (v[j] + 1) / (db)a[i] * f[i - 1][j]);
                }
                
            }
        }
        cout << fixed << setprecision(20) << f[n][m] * (db)(k + 1) << "\n";
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
