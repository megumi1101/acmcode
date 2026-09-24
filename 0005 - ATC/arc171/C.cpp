#include<bits/stdc++.h>

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

    vector<int> mulall(vector<vector<int>> f, int limit = -1) {
        // limit = -1：不截断
        // limit = k ：只保留前 k 项，即次数 < k
        // 例如只需要 0..M 次，就传 M + 1
        if (f.empty()) return {1};
        auto cut = [&](vector<int> &a) {
            if (limit != -1 && (int)a.size() > limit) {
                a.resize(limit);
            }
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < (int)f.size(); i++) {
            cut(f[i]);
            if (f[i].empty()) return {};
            pq.push({(int)f[i].size(), i});
        }
        while (pq.size() > 1) {
            auto [s1, x] = pq.top(); pq.pop();
            auto [s2, y] = pq.top(); pq.pop();
            auto c = mul(f[x], f[y]);
            cut(c);

            int id = f.size();
            f.push_back(move(c));
            pq.push({(int)f[id].size(), id});
        }
        return f[pq.top().second];
    }
}

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

    vector f(n + 1, vector<int>{});
    [&](this auto &&dfs, int u, int fat) -> void {
        vector<vector<int>> p;
        for (auto v : ed[u]) if (v != fat) {
            dfs(v, u);
            int siz = ed[v].size();
            int A = 0, B = 0;
            for (int j = 0; j < siz; j++) {
                A = (A + f[v][j] * fac[j] % mod) % mod; 
                B = (B + f[v][j] * fac[j + 1] % mod) % mod; 
            }
            p.push_back({A, B});
        }
        f[u] = NTT::mulall(p);
    }(1, 0);
    
    int ans = 0;
    for (int i = 0; i <= (int)ed[1].size(); i++) ans = (ans + f[1][i] * fac[i] % mod) % mod;
    cout << ans << "\n";
}