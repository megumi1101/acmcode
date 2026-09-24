#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
void sol() {
    int a, n;
    cin >> a >> n;
    vector<int> d(n);
    vector<int> vis(10);
    for (int i = 0; i < n; i++) cin >> d[i], vis[d[i]] = 1;
 
    vector<int> v;
    int t = a;
    while (t) {
        v.push_back(t % 10);
        t /= 10;
    }
    int siz = v.size();
 
    if (a == 0) {
        cout << d[0] << "\n";
        return;
    }
 
    vector<int> p10(20);
    p10[0] = 1;
    for (int i = 1; i <= 18; i++) {
        p10[i] = p10[i - 1] * 10;
    }
 
    int now = 0;
    int ans = 1e18;
    v.push_back(0);
    // for (auto x : v) cout << x << " ";
    for (int i = siz; i >= 0; i--) {
        // less
        int xl = -1;
        for (int y : d) if (y < v[i]) xl = max(xl, y);
        if (xl > -1 || (xl == -1 && now == 0 && i > 0)) {
            xl = max(0ll, xl);
            int res = now + xl * p10[i];
            for (int j = i - 1; j >= 0; j--) {
                res += d[n - 1] * p10[j];
            }
            ans = min(ans, abs(res - a));
 
        }
        
        int xr = 10;
        for (int y : d) if (y > v[i]) xr = min(xr, y);
        if (xr < 10 && i < 18) {
            int res = now + xr * p10[i];
            for (int j = i - 1; j >= 0; j--) {
                res += d[0] * p10[j];
            }
            ans = min(ans, abs(res - a));
        }
        
        if (i != siz && !vis[v[i]]) break;
        now += v[i] * p10[i];
        if (i == 0) ans = min(ans, abs(now - a));
    }
    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
