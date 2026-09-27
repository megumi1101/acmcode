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

signed main() {
    init(2e5);
    int h, w, n;
    cin >> h >> w >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    a.push_back({h, w});
    sort(a.begin(), a.end());
    vector<int> f(n + 1);

    for (int i = 0; i <= n; i++) {
        auto [x, y] = a[i];
        f[i] = C(x + y - 2, x - 1);
        for (int j = 0; j < i; j++) {
            auto[lx, ly] = a[j];
            if (lx <= x && ly <= y) {
                f[i] -= C(x + y - lx - ly, x - lx) * f[j] % mod;
                f[i] %= mod;
                if (f[i] < 0) f[i] += mod;
            }
        }
    }
    cout << f[n] << "\n";
}