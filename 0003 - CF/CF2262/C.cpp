#include <bits/stdc++.h>

using namespace std;

#define int long long
const int mod = 1e9 + 7, inf = 1e9;
vector<int> fac, ifac, inv;

void init(int n) {
    fac.assign(n + 1, 1);
    ifac.assign(n + 1, 1);
    inv.assign(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
        ifac[i] = ifac[i - 1] * inv[i] % mod;
    }
}

int C(int n, int m) {
    if (n < 0 || m < 0 || n < m) return 0;
    return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

void sol() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 0;

    for (int t = 1; t <= 2; t++) {
        set<int> s;
        for (int i = 0; i < n; i++) s.insert(a[i]);
        int X = a[n - 1], Y = a[n - 1 - t];
        s.erase(X);
        s.erase(Y);
        s.erase(0);
        int now = Y;
        int op = 1;
        int lf = 1;
        int rt = 0;
        while (!s.empty()) {
            if (op) {
                now = X - now;
                if (s.find(now) != s.end()) s.erase(now);
                else break;
                lf++;
            } else {
                now = Y - now;
                if (s.find(now) != s.end()) s.erase(now);
                else break;
                rt++;
            }
            op ^= 1;
        }
        if (s.empty()) {
            ans += fac[lf] * fac[rt] % mod;
            ans %= mod;
        }
    }
    cout << ans << "\n";
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init(2e5);
    

    int t;
    cin >> t;
    while (t--) sol();
}