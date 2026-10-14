#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 998244353;
const int inv2 = (mod + 1) / 2;

int fap(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

vector<int> pr, minp, phi, mu, w;
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

    w.assign(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        int x = i;
        while (x != 1) {
            int t = minp[x];
            while (x % t == 0) {
                x /= t;
            }
            w[i]++;
        }
    }
}

vector <int> get_g (vector<int> &f) {
    vector<int> g = f;
    int n = (int)f.size() - 1;
    for (auto p : pr) {
        if (p > n) break;
        for (int i = n / p; i >= 1; i--) {
            g[i * p] = (g[i * p] - g[i] + mod) % mod;
        }
    }
    return g;
} 

void sol() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), c(n + 1), pk(13);

    for (int i = 1; i <= 12; i++) pk[i] = fap(i, k);
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        c[a[i]]++;
    }

    vector cw(7, vector<int>(n + 1, 0));
    vector dw(7, vector<int>(n + 1, 0));
    for (int t = 0; t < 7; t++) {
        for (int i = 1; i <= n; i++) {
            cw[t][i] = c[i] * (w[i] == t);
            dw[t][i] = (w[i] == t);
        }
    } 

    vector sw(7, vector<int>(n + 1, 0));
    for (int t = 0; t < 7; t++) {
        for (int d = 1; d <= n; d++) {
            for (int i = d; i <= n; i += d) {
                sw[t][d] += cw[t][i];
            }
        }
    }

    int ans = 0;
    // cout << dw[0][1] << " " << dw[0][2] << " " << dw[0][3] << " " << dw[0][4] << "\n"; 
    for (int t = 0; t <= 6; t++) {
        auto f = get_g(dw[t]);
        for (int p = 1; p <= 12; p++) {
            for (int r = max(0LL, t + p - 6); r <= 6 && r <= t + p; r++) {
                auto &g = sw[r];
                auto &h = sw[t + p - r];
                int sum = 0;
                for (int d = 1; d <= n; d++) {
                    if (f[d] == 0) continue;
                    sum += f[d] * g[d] % mod * h[d] % mod;
                    sum %= mod;
                }
                ans = (ans + sum * pk[p] % mod) % mod;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        ans += mod - pk[w[a[i]]];
        ans %= mod;
    }
    ans = ans * inv2 % mod;
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init(2e5 + 10);
    
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
}

/*
3
4 1
3 3 3 3
4 1
1 1 1 1
4 2
1 2 3 4

6
0
12
*/
