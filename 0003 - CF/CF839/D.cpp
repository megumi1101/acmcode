#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

vector<int> pr, minp, phi, mu, p2;
void init(int n) {
    pr.clear();
    minp.assign(n + 1, 0), phi.assign(n + 1, 0), mu.assign(n + 1, 0);
    phi[1] = mu[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!minp[i]) pr.push_back(i), minp[i] = i, phi[i] = i - 1, mu[i] = -1;
        for (int p : pr) {
            if (p > n / i) break;
            int m = i * p; minp[m] = p;
            if (i % p == 0) { phi[m] = phi[i] * p, mu[m] = 0; break; }
            phi[m] = phi[i] * (p - 1), mu[m] = -mu[i];
        }
    }

    p2.assign(n + 1, 1);
    for (int i = 1; i <= n; i++) p2[i] = p2[i - 1] * 2 % mod;
}


vector <int> get_g (vector<int> &f) {
    vector<int> g = f;
    int n = (int)f.size() - 1;
    for (auto p : pr) {
        if (p > n) break;
        for (int i = 1; i * p <= n; i++) {
            g[i] = (g[i] - g[i * p] + mod) % mod;
        }
    }
    return g;
} 

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    init(1e6 + 10);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> f(1e6 + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 1; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                f[j]++;
                if (j * j != a[i]) {
                    f[a[i] / j]++;
                }
            }
        }
    }

    for (int i = 1; i <= f.size(); i++) {
        if (f[i]) {
            f[i] = f[i] * p2[f[i] - 1] % mod;
        }
    }

    auto g = get_g(f);
    int ans = 0;
    for (int i = 2; i < f.size(); i++) {
        ans += g[i] * i % mod;
        ans %= mod;
    }
    cout << ans << "\n";
}