#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 998244353;
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

int A(int n, int m) {
    if (n < 0 || m < 0 || n < m) return 0;
    return fac[n] * ifac[n - m] % mod;
}

int C(int n, int m) {
    if (n < 0 || m < 0 || n < m) return 0;
    return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

signed main() {
    int n;
    cin >> n;

    init(n + 5);
    vector<int> ctC(n + 1);
    vector<int> ctG(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        ctC[x]++;
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        ctG[x]++;
    }

    vector<vector<int>> f;
    f.push_back({1});
    for (int i = 1; i <= n; i++) {
        if (ctG[i] && ctC[i]) {
            f.emplace_back();
            int siz = (int)f.size() - 1;
            f[siz].push_back(1);
            for (int j = 1; j <= ctG[i] && j <= ctC[i]; j++) {
                f[siz].push_back(C(ctG[i], j) * A(ctC[i], j) % mod);
            }
        }
    }

    auto poly = NTT::mulall(f, n + 1);
    poly.resize(n + 1);
    int op = 1;
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += op * fac[n - i] * poly[i] % mod;
        ans %= mod;
        if (ans < 0) ans += mod;
        op = -op;
    }

    cout << ans * ifac[n] % mod << "\n";
}