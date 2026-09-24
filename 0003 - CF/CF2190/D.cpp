#include <bits/stdc++.h>
 
using namespace std;
 
template<int MOD>
struct ModInt {
    int v;
    ModInt(long long _v = 0) {
        v = int((_v % MOD + MOD) % MOD);
    }
    explicit operator int() const { return v; }
    ModInt& operator+=(const ModInt& other) {
        v += other.v;
        if (v >= MOD) v -= MOD;
        return *this;
    }
    ModInt& operator-=(const ModInt& other) {
        v -= other.v;
        if (v < 0) v += MOD;
        return *this;
    }
    ModInt& operator*=(const ModInt& other) {
        v = (long long)v * other.v % MOD;
        return *this;
    }
    static ModInt power(ModInt a, long long e) {
        ModInt r = 1;
        if (e == -1) return inv(a);
        while (e) {
            if (e & 1) r *= a;
            a *= a;
            e >>= 1;
        }
        return r;
    }
    static ModInt inv(ModInt a) {
        return power(a, MOD - 2);
    }
    ModInt& operator/=(const ModInt& other) {
        return *this *= inv(other);
    }
    friend ModInt operator+(ModInt a, const ModInt& b) { return a += b; }
    friend ModInt operator-(ModInt a, const ModInt& b) { return a -= b; }
    friend ModInt operator*(ModInt a, const ModInt& b) { return a *= b; }
    friend ModInt operator/(ModInt a, const ModInt& b) { return a /= b; }
    friend std::ostream& operator<<(std::ostream& os, const ModInt& m) {
        return os << m.v;
    }
};
 
using Z = ModInt<998244353>;
void sol() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ed(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        ed[x].push_back(y);
        ed[y].push_back(x);
    }
 
    vector<vector<int>> cols;
    vector<int> vis(n + 1), fa(n + 1), col(n + 1, -1), siz(n + 1, -1), son(n + 1, 1);
 
    auto dfs = [&] (auto &&dfs, int u, int fat) -> void {
        fa[u] = fat;
        vis[u] = 1;
        cols.back().push_back(u);
        col[u] = cols.size() - 1;
        for (auto v : ed[u]) if (v != fat) {
            dfs(dfs, v, u);
            son[u] += son[v];
        }
    };
 
    for (int i = n; i >= 1; i--) {
        cerr << i << "\n";
        if (!vis[i]) {cols.emplace_back(); dfs(dfs, i, 0);}
        siz[i] = cols[col[i]].size();
    }
    
cerr << 666 << "\n";
    Z mul = 1;
    int k = cols.size();
    for (auto v : cols) mul = mul * (Z)v.size();
    if (col[n] == col[n - 1]) {
        int u = n - 1;
        while (fa[u] != n) {
            u = fa[u];
            cerr << u << "\n";
        }
        for (int i = 1; i < n; i++) {
            if (i == u) {
                cout << Z::power(n, k - 2) * mul << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << "\n";
        return;
    }
    
    for (int i = 1; i < n; i++) {
        if (col[i] == col[n]) {
            if (fa[i] != n) cout << "0 ";
            else {
                cout << (Z)son[i] * Z::inv(siz[n]) * mul * Z::power(n, k - 2) << " "; 
            }
        } else if (col[i] == col[n - 1]) {
            cout << (Z)(siz[n - 1] + siz[n]) * Z::inv(siz[n]) * Z::inv(siz[n - 1]) * mul * Z::power(n, k - 3) << " ";
        } else {
            cout << Z::inv(siz[n])  * mul * Z::power(n, k - 3) << " ";
        }
    }
    cout << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
 
    int T = 1;
    cin >> T;
    while (T--) sol();
}
