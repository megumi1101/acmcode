#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x << " == " << x << "\n";

#define int long long
const int mod = 998244353, inf = 1e9;
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

namespace NTT {

    const int P = 998244353, G = 3;

    int power(int a, int b) {
        int res = 1;
        while (b) {
            if (b & 1) res = res * a % P;
            a = a * a % P, b >>= 1;
        }
        return res;
    }

    void ntt(vector<int> &a, bool inv) {
        int n = a.size();
        for (int i = 1, j = 0; i < n; i++) {
            int bit = n >> 1;
            while (j & bit) j ^= bit, bit >>= 1;
            j ^= bit;
            if (i < j) swap(a[i], a[j]);
        }
        for (int len = 2; len <= n; len <<= 1) {
            int wn = power(G, (P - 1) / len);
            if (inv) wn = power(wn, P - 2);
            for (int i = 0; i < n; i += len) {
                int w = 1;
                for (int j = 0; j < len / 2; j++) {
                    int x = a[i + j];
                    int y = a[i + j + len / 2] * w % P;
                    a[i + j] = (x + y) % P;
                    a[i + j + len / 2] = (x - y + P) % P;
                    w = w * wn % P;
                }
            }
        }
        if (inv) {
            int in = power(n, P - 2);
            for (int &x : a) x = x * in % P;
        }
    }

    vector<int> mul(vector<int> a, vector<int> b) {
        if (a.empty() || b.empty()) return {};
        int need = a.size() + b.size() - 1, n = 1;
        while (n < need) n <<= 1;
        for (int &x : a) x = (x % P + P) % P;
        for (int &x : b) x = (x % P + P) % P;
        a.resize(n), b.resize(n);
        ntt(a, 0), ntt(b, 0);
        for (int i = 0; i < n; i++) a[i] = a[i] * b[i] % P;
        ntt(a, 1);
        a.resize(need);
        return a;
    }
} // namespace NTT

void sol() {
    int n, m;
    cin >> n >> m;
    init(n * m);
    vector<int> a(n * m);
    for (auto &i : a) cin >> i;

    int k = 0;
    vector<int> f((n + 2) * (m + 2)), s((n + 2) * (m + 2));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 && j == 0) continue;
            ++k;

            s[k] = (i * m) + (j * n) - i * j;
            f[k] = C(n, i) * C(m, j) % mod * fac[n * m - s[k]] % mod;
            if ((i + j) % 2 == 0) f[k] = mod - f[k];
            // debug(k);
            // debug(i);
            // debug(j);
            // debug(f[k]);
            // debug(s[k]);

            // cerr << "\n\n";
            // cerr << k << " " << i << " " << j << " " << " " << f[k] << " " << s[k] << "\n";
        }
    }

    vector<int> g(n * m + 1);
    for (int i = 1; i <= k; i++) {
        g[s[i]] += f[i];
        g[s[i]] %= mod;
    }
    
    auto ans = NTT::mul(g, ifac);
    for (int t = 0; t <= n * m; t++) {
        ans[t] = ans[t] * fac[t] % mod;
    }
    auto d = ans;

    int bingo = 0;
    sort(a.begin(), a.end());
    for (int t = 1; t <= n * m; t++) {
        d[t] = ans[t] - ans[t - 1];
        d[t] %= mod;
        if (d[t] < 0) d[t] += mod;
        bingo += d[t] * a[t - 1] % mod;
        bingo %= mod;
    }
    cout << bingo << "\n";



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
3 4
1 1 4 5 1 4 1 9 1 9 8 10
*/