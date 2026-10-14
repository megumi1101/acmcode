#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 998244353;

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
        assert(n && (n & (n - 1)) == 0 && n <= (1LL << 23));
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
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    init(n + 10);

    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    auto nx = x;
    auto ny = y;
    reverse(nx.begin(), nx.end());
    reverse(ny.begin(), ny.end());
    
    auto dbx = x;
    auto dby = y;
    dbx.resize(2 * n);
    dby.resize(2 * n);
    for (int i = 0; i < n; i++) {
        dbx[n + i] = dbx[i];
        dby[n + i] = dby[i];
    }
    
    auto fL = NTT::mul(nx, dby);
    auto fR = NTT::mul(ny, dbx);
    vector<int> f(n);
    for (int d = 0; d < n; d++) {
        f[d] = fL[n + d - 1] - fR[n + d - 1];
    }
    for (int &x : f) x = (x % mod + mod) % mod;

    auto g0 = f;
    for (int i = 1; i < n; i++) {
        g0[i] = fac[n - i - 1] * f[i] % mod;
    }
    auto g = NTT::mul(g0, ifac);

    for (int k = 3; k <= n; k++) {
        int ans = ifac[k - 2] * g[n - k + 1] % mod;
        cout << ans << "\n";
    }
}

/*
6
0 0
1 0
2 1
2 2
1 2
0 1
*/