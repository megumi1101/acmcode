#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;
int fap(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

signed main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 2);
    a[0] = a[n + 1] = 1;

    int ct = 0;
    bool fg = 0;
    int ct2 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == -1) {
            ct++; ct2++;
        } else if (a[i] > 1 && a[i] < n) {
            fg = 1;
        }
        if (a[i] == 1) ct2++;
    }

    if (fg) {
        cout << fap(m, ct) << "\n";
        return 0;
    }

    if (m <= n - 1) {
        int ans = fap(m, ct);
        if (n & 1 && ct2 == n) {
            ans--;
        }
        if (ans < 0) ans += mod;
        cout << ans << "\n";
    } else {
        // int t = m - n + 2;
        int all = fap(m, ct);
        
        
        vector<array<int, 2>> f(n + 2, {0, 0});
        f[0][1] = 1;
        for (int i = 1; i <= n + 1; i++) {
            if (a[i] == 1) {
                f[i][1] = f[i - 1][0];
            } else if (a[i] >= n) {
                f[i][0] = (f[i - 1][0] + f[i - 1][1]) % mod;
            } else if (a[i] == -1) {
                f[i][1] = f[i - 1][0];
                f[i][0] = (f[i - 1][0] + f[i - 1][1]) * (m - n + 1) % mod; 
            }
        }

        // cout << all << "\n";
        int ans = all - f[n + 1][1];
        if (ans < 0) ans += mod;
        // cout << f[n + 1][1] << "\n";
        if (n & 1 && ct2 == n) {
            ans--;
        }
        if (ans < 0) ans += mod;
        ans %= mod;
        cout << ans << "\n";
    }
}

/*
6 10
-1 -1 -1 -1 1 7
*/