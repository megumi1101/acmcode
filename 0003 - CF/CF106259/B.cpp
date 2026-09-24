#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 998244353;

int fap(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int inv(int a) {
    return fap(a, mod - 2);
}

void sol() {
    int n, k;
    cin >> n >> k;
    
    vector<int> cnt(n + 1);
    int c1 = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 1) c1++;
        else cnt[x]++;
    }


    vector<pair<int, int>> a;
    for (int i = 1; i <= n; i++) {
        if (cnt[i]) a.push_back({i, cnt[i]});
    }

    int up = 1, dn = 1, ini = fap(c1, k);
    int ans = ini;

    // cout << ans << "\n";
    if (a.empty()) {
        cout << ans << "\n";
        return;
    }

    int Mx = a.back().first;
    vector<int> f(Mx + 1), pref(Mx + 1);
    for (auto [x, y] : a) {
        f[x] = y;
    }
    int Mn = a[0].first;
    for (int i = 1; i <= Mx; i++) {
        pref[i] = (pref[i - 1] + f[i]) % mod;
    }

    
    for (int i = 1; i <= k; i++) {
        if (i != 1) {
            if (Mx / Mn == 0) {
                break;
            }
            f.resize(Mx / Mn + 1);
            fill(f.begin(), f.end(), 0);
            for (auto [x, y] : a) {
                if (x > Mx) break;
                for (int j = 1; j * x <= Mx; j++) {
                    f[j] += (pref[min((j + 1) * x - 1, Mx)] - pref[j * x - 1]) * y % mod;
                    f[j] %= mod;
                    if (f[j] < 0) f[j] += mod;
                }
            }

            Mx /= Mn;
            pref.resize(Mx + 1);
            fill(pref.begin(), pref.end(), 0);
            for (int j = 1; j <= Mx; j++) {
                pref[j] = (pref[j - 1] + f[j]) % mod;
            }
        }

        int t = 0;
        if (c1) {
            up = up * (k - i + 1) % mod;
            dn = dn * i % mod;
            ini = ini * inv(c1) % mod;
            t = up * inv(dn) % mod * ini % mod;
            t = t * inv(k) % mod * i % mod;
        }

        
        
        if (i == k) t = 1;
        // cout << t << "\n";
        for (int j = 1; j <= Mx; j++) {
            ans += j * f[j] % mod * t % mod;
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

/*
1
2 2
1 2

1
3 1
3 1 3

1
3 4
1 2 3

*/