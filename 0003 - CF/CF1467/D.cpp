#include <bits/stdc++.h>
 
using namespace std;
#define int long long
const int mod = 1e9 + 7;
void sol() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
 
    vector f(n + 1, vector(k + 1, (int)0));
    for (int i = 1; i <= n; i++) f[i][0] = 1;
 
    for (int tim = 1; tim <= k; tim++) {
        for (int i = 1; i <= n; i++) {
            if (i - 1 >= 1) f[i][tim] += f[i - 1][tim - 1];
            if (i + 1 <= n) f[i][tim] += f[i + 1][tim - 1];
            f[i][tim] %= mod;
        }
    }
 
    vector<int> g(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int t = 0; t <= k; t++) {
            g[i] += f[i][t] * f[i][k - t] % mod;
            g[i] %= mod;
        }
    }
 
    int ans = 0;
    for (int i = 1; i <= n; i++) ans += g[i] * a[i] % mod, ans %= mod;
 
    while (q--) {
        int i, x;
        cin >> i >> x;
        ans -= g[i] * a[i] % mod;
        a[i] = x;
        ans += g[i] * a[i] % mod;
        ans %= mod;
        ans += mod;
        ans %= mod;
        cout << ans << "\n";
    }
}
 
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int T = 1;
    // cin >> T;
 
    while (T--) sol();
}
