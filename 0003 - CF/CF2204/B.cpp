#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
void sol() {
    int n;
    int mx = 0;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x >= mx) mx = x, ans++;
    }
    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) sol();
}
