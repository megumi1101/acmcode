#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 998244353;
signed main() {
    int n;
    cin >> n;

    vector<int> a(n + 1), p2(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        p2[i] = p2[i - 1] * 2 % mod;
        string op;
        cin >> op;
        if (op == "+") {
            cin >> a[i];
        } else {
            a[i] = -1;
        }
    }

    int ans = 0;
    for (int k = 1; k <= n; k++) {
        if (a[k] == -1) continue;
        int x = a[k];
        vector<int> f(n + 1);
        f[0] = 1;
        for (int i = 1; i <= k; i++) {
            auto nf = f;
            if (i == k) fill(nf.begin(), nf.end(), 0);
            if (a[i] == -1) {
                for (int j = 0; j <= n; j++) {
                    (nf[max(j - 1, 0LL)] += f[j]) %= mod;
                }
            } else if (a[i] <= x) {
                for (int j = 0; j <= n; j++) {
                    (nf[j + 1] += f[j]) %= mod;
                }
            } else {
                for (int j = 0; j <= n; j++) {
                    (nf[j] += f[j]) %= mod;
                }
            }
            f = move(nf);
        }

        int sum = p2[n - 1];
        for (int i = k + 1; i <= n; i++) {
            auto nf = f;
            if (a[i] == -1) {
                for (int j = 0; j <= n; j++) {
                    (nf[max(j - 1, 0LL)] += f[j]) %= mod;
                }
            } else if (a[i] < x) {
                for (int j = 0; j <= n; j++) {
                    (nf[j + 1] += f[j]) %= mod;
                }
            } else {
                for (int j = 0; j <= n; j++) {
                    (nf[j] += f[j]) %= mod;
                }
            }
            f = move(nf);
            sum += mod - f[0] * p2[n - i] % mod;
            sum %= mod;
            f[0] = 0;
        }

        ans += sum * x % mod;
        ans %= mod;
    }
    cout << ans << "\n";
}

/*
4
-
+ 1
+ 2
-
*/