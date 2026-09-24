#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i > 1) {
            if (gcd(a[i], a[i - 1]) == max(a[i], a[i - 1]) - min(a[i], a[i - 1])) ans++;
        }
    }
    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
