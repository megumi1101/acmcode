#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
const int inf = 1e18;
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
 
void sol() {
    int n, m;
    cin >> n >> m;
    vector w(n + 1, vector(m + 1, 0));
    vector v(n + 1, vector(m + 1, 0));
    vector p(n + 1, vector(m + 1, 0));
    vector q(n + 1, vector(m + 1, 0));
 
    int siz = (n + 1) * (m + 1);
    DSU dsu(siz);
    vector<int> val(siz);
 
    auto cal = [&](int i, int j) {
        return i * (m + 1) + j;
    };
    for (int j = 0; j < m + 1; j++) {
        val[cal(0, j)] = val[cal(n, j)] = -inf;
    }
 
    for (int i = 0; i < n + 1; i++) {
        val[cal(i, 0)] = val[cal(i, m)] = -inf;
    }
 
    
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> w[i][j];
            val[cal(i, j - 1)] -= w[i][j];
            val[cal(i, j)] += w[i][j];
        }
    }
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < m; j++) {
            cin >> v[i][j];
            val[cal(i - 1, j)] -= v[i][j];
            val[cal(i, j)] += v[i][j];
        }
    }
 
    for (int i = 1; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++) {
            p[i][j] = s[j - 1] - '0';
            if (!p[i][j]) dsu.merge(cal(i, j - 1), cal(i, j));
        }
    }
 
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j < m; j++) {
            q[i][j] = s[j - 1] - '0';
            if (!q[i][j]) dsu.merge(cal(i - 1, j), cal(i, j));
        }
    }
 
    vector<int> ans(siz);
    for (int i = 0; i < siz; i++) {
        int fat = dsu.find(i);
        ans[fat] += val[i];
        if (ans[fat] < -inf) ans[fat] = -inf;
    }
 
    int sum = 0;
    for (auto x : ans) if (x > 0) sum += x;
    cout << sum << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
