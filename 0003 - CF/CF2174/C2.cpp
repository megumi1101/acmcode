#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int fap (int a, int b, int mod) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod; b >>= 1;
    }
    return res;
}
 
void sol() {
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> a(n + 1);
    a[0] = 1;
    a[1] = fap(m, p - 2, p);
    for (int i = 2; i <= n; i++) a[i] = a[i - 1] * a[1] % p;
    
    int ans = 0;
    vector<int> pre(n + 1), prep(n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = (n - i + 1) * a[i / 2] % p;
        pre[i] = (pre[i - 1] + pre[i]) % p;
        prep[i] = a[i / 2];
        if (i >= 2) prep[i] = (prep[i - 2] + prep[i]) % p;
    }
 
    for (int i = 1; i <= n; i++) {
        ans += (n - i + 1)  * a[i / 2] % p * pre[i - 1] % p;
        int k = (i - 1) / 2;
        if (i > 2) {
            ans -= (n - i + 1) * a[i / 2] % p * prep[i - 2] % p;
            ans += (n - i + 1) * a[i / 2] % p * k % p;
        }
        ans %= p; ans += p; ans %= p;
    }
    ans *= 2;
    for (int i = 1; i <= n; i++) {
        ans += (n - i + 1) * (n - i + 1) % p * a[i / 2] % p * a[i / 2] % p;
        ans -= (n - i + 1) * a[i / 2] % p * a[i / 2] % p;
        ans += (n - i + 1) * a[i / 2] % p;
        ans %= p; ans += p; ans %= p;
    }
    cout << ans << "\n";
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         int t = max(i, j);
    //         ans += (n - i + 1) * (n - j + 1) % p * a[i / 2] % p * a[j / 2] % p;
    //         ans %= p;
    //         if ((i & 1) == (j & 1)) {
    //             ans -= (n - t + 1) * a[i / 2] % p * a[j / 2] % p;
    //             ans %= p; ans += p; ans %= p;
    //             ans += (n - t + 1) * a[t / 2] % p;
    //             ans %= p;
    //         } 
    //     }
    // }
}
 
signed main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) sol();
}
