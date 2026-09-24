#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 998244353;
signed main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> inv(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    }

    for (int i = 1; i <= n; i++) cin >> a[i];


    vector<int> sufi(n + 2, 0), prei(n + 2, 0), pre(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        prei[i] = prei[i - 1] + i * inv[i] % mod;
        pre[i] = pre[i - 1] + inv[i] % mod;
        prei[i] %= mod;
        pre[i] %= mod;
    }

    for (int i = n; i >= 1; i--) {
        sufi[i] = sufi[i + 1] + (n - i + 1) * inv[i] % mod;
        sufi[i] %= mod;
    }
    

    int res = 0, ans = 0;
    for (int i = 1; i * 2 <= n; i++) {
        res = prei[i] + sufi[n - i + 1] + i * (pre[n - i] - pre[i]);
        res %= mod;
        if (res < 0) res += mod;
        int t = a[i];
        t += a[n - i + 1];
        ans += t * res % mod;
        ans %= mod;
    }
    if (n & 1) {
        ans += a[n / 2 + 1] * (prei[n / 2 + 1] + sufi[n / 2 + 2]) % mod;
        ans %= mod;
    }
    cout << ans << "\n";
    
}