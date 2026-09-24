#include <bits/stdc++.h>
 
using namespace std;
#define int long long
const int mod = 998244353;
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        int d = a[i] - a[i - 1];
        if (a[n] != n || d > 2 || d < 0) {
            cout << "0\n";
            return;
        }
        int t = (i - a[i - 1]) - 1;
        if (d == 1) {
            ans *= (t * 2 + 1);
            ans %= mod;
        } else if (d == 2) {
            ans *= t * t % mod;
            ans %= mod;
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
