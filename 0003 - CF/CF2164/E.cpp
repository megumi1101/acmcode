#include <bits/stdc++.h>
 
using namespace std;
 
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
 
 
const int inf = 1e9 + 10;
 
void sol() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n + m);
    vector<int> fa(n + m + 1), a(n + m + 1, inf), cost(n + m + 1, inf), odd(n + m + 1);
    vector<vector<int>> ed(n + m + 1);
    long long ans = 0;
    for (int now = n + 1; now <= n + m; now++) {
        int u, v, w;
        cin >> u >> v >> w;
        int fu = dsu.find(u);
        int fv = dsu.find(v);
        odd[u] ^= 1;
        odd[v] ^= 1;
        a[now] = w;
        ans += w;
        if (fu == fv) {
            fa[fu] = now;
            ed[now].push_back(fu);
            dsu.merge(now, fu);
        } else {
            fa[fu] = now;
            fa[fv] = now;
            ed[now].push_back(fu);
            ed[now].push_back(fv);
            dsu.merge(now, fu);
            dsu.merge(now, fv);
        }
    }
    
    auto dfs = [&] (auto &&self, int u, int x) -> void {
        cost[u] = min(a[u], x);
        for (auto v : ed[u]) {
            self(self, v, cost[u]);
        }
    };
    dfs(dfs, n + m, inf);
 
    for (int i = 1; i <= n + m; i++) {
        int prs = odd[i] / 2;
        odd[i] -= prs * 2;
        odd[fa[i]] += odd[i];
        ans += 1LL * prs * cost[i];
    }
    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
