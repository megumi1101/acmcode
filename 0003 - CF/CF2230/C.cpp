#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    int sum = 0;
    int cnt = 0;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= 2) {
            sum += a[i];
            res += a[i] / 2 - 1;
            cnt++;
        }
    }
 
    int mx = n - cnt;
    int ans = 0;
    if (cnt == 1) {
        int t = min(mx, res + 1);
        ans = sum + t;
    } else if (cnt > 1) {
        int t = min(mx, res);
        ans = sum + t;
    }
    if (ans < 3) ans = 0;
    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
