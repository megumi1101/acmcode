#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int inf = 1e18;
 
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1), d(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) {cin >> a[i]; sum += a[i];}
    sum /= 2;
 
    int mx1 = 0, mn1 = 0;
    int mx0 = -inf, mn0 = inf;
    for (int i = 2; i <= n; i++) {
        if (i == 2) d[i] = a[i];
        else {
            d[i] = a[i] - d[i - 1]; 
        }
 
        if (i & 1) mx1 = max(mx1, d[i]), mn1 = min(mn1, d[i]);
        else {
            mx0 = max(mx0, d[i]);
            mn0 = min(mn0, d[i]);
        }
    }
 
 
    if (n & 1) {
        int x1 = (a[1] - d[n]) / 2;
        int mx = max(x1 + mx1, mx0 - x1);
        mx = max(mx, (sum - 1) / (n - 1) + 1);
        cout << mx << "\n";
        return;
    }
    int l_x1 = max((int)0, -mn1);
    int r_x1 = mn0;
 
    int l = 0, r = 1e10;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        int l2 = mx0 - mid;
        int r2 = mid - mx1;
        if (l2 <= r_x1 && r2 >= l_x1 && l2 <= r2 && (n - 1) * mid >= sum) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << "\n";
    // cerr << l_x1 << r_x1 << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
