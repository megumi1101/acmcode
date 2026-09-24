#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
void sol() {
    int n;
    cin >> n;
 
    int res = 0;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        if (a[i] > b[i]) swap(a[i], b[i]);
        res += b[i];
    }
 
    int mx = -1;
    for (int i = 1; i <= n; i++) {
        mx = max(a[i], mx);
    }
    int ans = res + mx;
 
    for (int i = 1; i <= n; i++) {
        if (b[i] > mx) {
            ans = max(ans, res - b[i] + a[i] + b[i]);
        }
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
