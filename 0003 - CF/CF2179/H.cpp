#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
void sol() {
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> qry(q);
    for (auto &[x, y] : qry) cin >> x >> y;
    vector<int> ans(n + 1);
    for (int p2 = 1; p2 <= n; p2 <<= 1) {
        vector d(p2, vector(n / p2 + 5, (int)0));
        int mul = max(p2 / 2, (int)1);
        // 1 1 2 4 8
        // p2,  2 * p2 ... k * p2, 0            , 0
        // p2,  p2,    ... p2    , -k * p2      , 0
        // p2,  0,     ... 0     , -(k + 1) * p2, k * p2
        for (auto &[l, r] : qry) {
            int st = l + p2 - 1;
            int en = (r - l + 1) / p2 * p2 + l - 1;
            int rem = st % p2;
            int tl = (st - rem) / p2 + 1;
            int tr = (en - rem) / p2 + 1;
            int k = tr - tl + 1;
            d[rem][tl] += mul * p2;
            d[rem][tr + 1] -= mul * (k + 1) * p2;
            d[rem][tr + 2] += mul * k * p2;
        }
 
        for (int rem = 0; rem < p2; rem++) {
            for (int i = 1; i < d[rem].size(); i++) {
                d[rem][i] += d[rem][i - 1];
            }
        }
        for (int rem = 0; rem < p2; rem++) {
            for (int i = 1; i < d[rem].size(); i++) {
                d[rem][i] += d[rem][i - 1];
                int pos = (i - 1) * p2 + rem;
                if (pos <= n) ans[pos] += d[rem][i];
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) sol();
}
