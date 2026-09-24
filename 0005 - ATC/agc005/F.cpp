#include<bits/stdc++.h>

using namespace std;

#define int long long

namespace NTT {
    const int P = 924844033, G = 5;
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
        assert(need <= (1LL << 23));
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

const int mod = 924844033, inf = 1e9;
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

mt19937_64 gen(random_device{}());
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    init(n);
    vector<vector<int>> ed(n + 1);

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ed[x].push_back(y);
        ed[y].push_back(x);
    }

    vector<int> siz(n + 1), c(n + 1);
    [&](this auto &&dfs, int u, int fat) -> void {
        siz[u] = 1;
        for (auto v : ed[u]) if (v != fat) {
            dfs(v, u);
            siz[u] += siz[v];
        }
        if (u != 1) {
            c[siz[u]]++;
            c[n - siz[u]]++;
        }
    } (1, 0);

    vector<int> d(n + 1);
    for (int i = 0; i <= n; i++) {
        d[n - i] = c[i] * fac[i] % mod;
    }

    auto f = NTT::mul(d, ifac);

    for (int k = 1; k <= n; k++) {
        int ans = (n * C(n, k) % mod) - (ifac[k] * f[n - k] % mod);
        ans %= mod;
        if (ans < 0) ans += mod;
        cout << ans << "\n";
    }
}