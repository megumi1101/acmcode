// AtCoder user: lnxbb
// Contest: agc005
// Problem: agc005_d
// Submission: https://atcoder.jp/contests/agc005/submissions/75679691
// Language: C++23 (GCC 15.2.0)

#include <bits/stdc++.h>

using namespace std;

#define int long long
const int mod = 924844033;

struct DSU {
    vector<int> f, siz;

    DSU() {}
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        f.resize(n + 1);
        iota(f.begin(), f.end(), 0);
        siz.assign(n + 1, 1);
    }

    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    int size(int x) {
        return siz[find(x)];
    }
};

vector<int> fac, facn, inv;
void init(int n) {
    fac.assign(n + 1, 0);
    facn.assign(n + 1, 0);
    inv.assign(n + 1, 0);
    fac[0] = fac[1] = facn[0] = facn[1] = inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
        facn[i] = facn[i - 1] * inv[i] % mod;
    }
}

int C (int i, int j) {
    if (i < j) return 0;
    return fac[i] * facn[j] % mod * facn[i - j] % mod;
}

vector<int> mul(const vector<int> &a, const vector<int> &b) {
    int siz = a.size() + b.size() - 1;
    vector<int> f(siz, 0);
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            f[i + j] += a[i] * b[j] % mod;
            f[i + j] %= mod;
        }
    }
    while (f.back() == 0)f.pop_back();
    return f;
}


mt19937_64 gen (random_device{}());

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init(10005);

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> pts;
    map<pair<int, int>, int> mp;
    int cnt = 0;

    DSU dsu(2 * n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (abs(j - i) == k) {
                cnt++;
                pts.push_back({i, j});
                mp[{i, j}] = cnt;
                auto it = mp.find({i - 2 * k, j});
                if (it != mp.end()) dsu.merge(it->second, cnt);
                it = mp.find({i, j - 2 * k});
                if (it != mp.end()) dsu.merge(it->second, cnt);
            }
        }
    }


    vector<int> a;
    for (int i = 1; i <= cnt; i++) {
        if (dsu.find(i) == i) {
            a.push_back(dsu.size(i));
        }
    }

    if (a.empty()) {
        cout << fac[n] << "\n";
        return 0;
    }

    shuffle(a.begin(), a.end(), gen);

    auto v = ([&](this auto &&dfs, int l, int r) -> vector<int> {
        if (l == r) {
            int x = a[l];
            vector<int> v(x + 1);
            for (int i = 0; i <= x; i++) {
                v[i] = C(x - i + 1, i);
            }
            while (v.back() == 0) v.pop_back();
            return v;
        }

        int mid = (l + r) / 2;
        return mul(dfs(l, mid), dfs(mid + 1, r));
    } (0, a.size() - 1) );
    
    int op = -1;
    int ans = 0;
    for (int i = 0; i < v.size(); i++) {
        op *= -1;
        if (i > n) break;
        ans += op * v[i] * fac[n - i] % mod;
        ans %= mod;
        ans += mod;
        ans %= mod;
    }

    cout << ans << "\n";
}