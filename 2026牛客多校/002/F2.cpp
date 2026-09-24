#include <bits/stdc++.h>

using namespace std;

struct DynBitset {
    using u64 = unsigned long long;

    int n = 0;
    vector<u64> a;

    DynBitset() {}
    DynBitset(int n_, bool fill = false) { init(n_, fill); }

    void init(int n_, bool fill = false) {
        n = max(0, n_);
        a.assign((n + 63) >> 6, fill ? ~0ULL : 0ULL);
        trim();
    }

    int size() const { return n; }

    void trim() {
        if (!a.empty() && (n & 63))
            a.back() &= (1ULL << (n & 63)) - 1;
    }

    void set(int p) { a[p >> 6] |= 1ULL << (p & 63); }
    void reset(int p) { a[p >> 6] &= ~(1ULL << (p & 63)); }
    void flip(int p) { a[p >> 6] ^= 1ULL << (p & 63); }
    bool test(int p) const { return a[p >> 6] >> (p & 63) & 1; }
    bool operator[](int p) const { return test(p); }

    void set_all() { fill(a.begin(), a.end(), ~0ULL); trim(); }
    void reset_all() { fill(a.begin(), a.end(), 0ULL); }
    void flip_all() { for (auto &x : a) x = ~x; trim(); }

    bool any() const {
        for (u64 x : a) if (x) return true;
        return false;
    }

    bool none() const { return !any(); }

    int count() const {
        int res = 0;
        for (u64 x : a) res += __builtin_popcountll(x);
        return res;
    }

    int first_one() const {
        for (int i = 0; i < (int)a.size(); i++)
            if (a[i]) return i * 64 + __builtin_ctzll(a[i]);
        return -1;
    }

    int last_one() const {
        for (int i = (int)a.size() - 1; i >= 0; i--)
            if (a[i]) return i * 64 + 63 - __builtin_clzll(a[i]);
        return -1;
    }

    int next_one(int p) const {
        if (++p >= n) return -1;
        int i = p >> 6;
        u64 x = a[i] & (~0ULL << (p & 63));
        if (x) return i * 64 + __builtin_ctzll(x);
        for (i++; i < (int)a.size(); i++)
            if (a[i]) return i * 64 + __builtin_ctzll(a[i]);
        return -1;
    }

    DynBitset &operator&=(const DynBitset &o) {
        assert(n == o.n);
        for (int i = 0; i < (int)a.size(); i++) a[i] &= o.a[i];
        return *this;
    }

    DynBitset &operator|=(const DynBitset &o) {
        assert(n == o.n);
        for (int i = 0; i < (int)a.size(); i++) a[i] |= o.a[i];
        return *this;
    }

    DynBitset &operator^=(const DynBitset &o) {
        assert(n == o.n);
        for (int i = 0; i < (int)a.size(); i++) a[i] ^= o.a[i];
        return *this;
    }

    DynBitset &operator<<=(int k) {
        if (k <= 0) return *this;
        if (k >= n) return reset_all(), *this;

        int m = a.size(), b = k >> 6, s = k & 63;

        if (!s) {
            for (int i = m - 1; i >= b; i--) a[i] = a[i - b];
        } else {
            for (int i = m - 1; i > b; i--)
                a[i] = a[i - b] << s | a[i - b - 1] >> (64 - s);
            a[b] = a[0] << s;
        }

        fill(a.begin(), a.begin() + b, 0ULL);
        trim();
        return *this;
    }

    DynBitset &operator>>=(int k) {
        if (k <= 0) return *this;
        if (k >= n) return reset_all(), *this;

        int m = a.size(), b = k >> 6, s = k & 63;
        int lim = m - b;

        if (!s) {
            for (int i = 0; i < lim; i++) a[i] = a[i + b];
        } else {
            for (int i = 0; i + 1 < lim; i++)
                a[i] = a[i + b] >> s | a[i + b + 1] << (64 - s);
            a[lim - 1] = a[m - 1] >> s;
        }

        fill(a.begin() + lim, a.end(), 0ULL);
        return *this;
    }

    friend DynBitset operator&(DynBitset x, const DynBitset &y) { return x &= y; }
    friend DynBitset operator|(DynBitset x, const DynBitset &y) { return x |= y; }
    friend DynBitset operator^(DynBitset x, const DynBitset &y) { return x ^= y; }
    friend DynBitset operator<<(DynBitset x, int k) { return x <<= k; }
    friend DynBitset operator>>(DynBitset x, int k) { return x >>= k; }

    friend DynBitset operator~(DynBitset x) {
        x.flip_all();
        return x;
    }

    string to_string() const {
        string s(n, '0');
        for (int i = 0; i < n; i++) s[n - 1 - i] = test(i) + '0';
        return s;
    }
};

void sol() {
    int n;
    cin >> n;

    vector<vector<pair<int, int>>> ed(n + 1);

    int mxW = 0;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        ed[u].push_back({v, w});
        ed[v].push_back({u, w});
        mxW = max(mxW, w);
    }

    vector<int> w(n + 1), fa(n + 1);
    vector<int> p;
    vector<int> leaf(n + 1, 1);
    [&](this auto &&dfs, int u, int fat) -> void {
        fa[u] = fat;
        for (auto [v, ww] : ed[u]) if (v != fat) {
            w[v] = ww;
            leaf[u] = 0;
            dfs(v, u);
        }
        p.push_back(u);
    }(1, 0);

    
    vector<int> ans(n + 1, 1e9);
    vector f(n + 1, DynBitset());
    for (int W = 2 * mxW - 1; W >= 1; W--) {
        
        for (auto v : p) {
            if (f[v].any()) ans[v] = W;
            int u = fa[v];
            if (f[u].any()) f[u] &= ((f[v] << w[v]) | (f[v] >> w[v]));
        }
    }

    for (int i = 1; i <= n; i++) {
        if (leaf[i]) ans[i] = 0;
        cout << ans[i] << " ";
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        sol();
    }
}

/*
3
3
1 2 1
2 3 1
4
1 2 2
2 3 1
3 4 2
5
1 2 4
1 3 1
2 4 2
2 5 1
*/