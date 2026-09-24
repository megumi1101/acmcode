#include <bits/stdc++.h>
 
using namespace std;
#define int long long
void sol() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n + 1), b(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i] / x;
        sum += b[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, a[i] + (sum - b[i]) * y);
    }
    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
