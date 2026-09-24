// AtCoder user: lnxbb
// Contest: agc002
// Problem: agc002_d
// Submission: https://atcoder.jp/contests/agc002/submissions/75210505
// Language: C++23 (GCC 15.2.0)

#include<bits/stdc++.h>

using namespace std;

struct DSU {
    vector<int> f, siz;
    DSU(){}
    DSU(int n) {init(n);}

    void init(int n) {
        f.assign(n + 1, 0);
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
        if (x == y) return 0;
        siz[x] += siz[y];
        f[y] = x;
        return 1;
    }

    int size(int x) {
        return siz[find(x)];
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n + m);

    vector<vector<int>> ed(n + m + 1);
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        x = dsu.find(x);
        y = dsu.find(y);
        ed[n + i].push_back(x);
        dsu.merge(n + i, x);
        if (x != y) {
            ed[n + i].push_back(y);
            dsu.merge(n + i, y);
        }
    }

    vector dep(n + m + 1, 0);
    vector fa(n + m + 1, array<int, 20>{});
    vector siz(n + m + 1, 0);
    for (int i = 1; i <= n; i++) siz[i] = 1;
    [&](this auto &&dfs, int u, int deep) -> void {
        dep[u] = deep;
        for (int i = 1; i < 20; i++) {
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }
        for (auto v : ed[u]) {
            fa[v][0] = u;
            dfs(v, deep + 1);
            siz[u] += siz[v];
        }
    }(n + m, 1);

    auto get_lca = [&](int x, int y) -> int {
        if (dep[x] < dep[y]) swap(x, y);

        for (int i = 19; i >= 0; i--) {
            if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
        }
        if (x == y) return x;

        for (int i = 19; i >= 0; i--) {
            if (fa[x][i] != fa[y][i]) {
                x = fa[x][i];
                y = fa[y][i];
            }
        }
        return fa[x][0];
    };

    int q;
    cin >> q;
    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        int lca = get_lca(x, y);
        int l = 1, r = m;

        auto check = [&](int mid) -> bool {
            int res = 0;
            if (lca <= mid + n) {
                int u = lca;
                for (int i = 19; i >= 0; i--) {
                    if (fa[u][i] && fa[u][i] <= mid + n) u = fa[u][i];
                }
                res = siz[u];
            } else {
                int u = x;
                for (int i = 19; i >= 0; i--) {
                    if (fa[u][i] && fa[u][i] <= mid + n) u = fa[u][i];
                }
                res += siz[u];

                u = y;
                for (int i = 19; i >= 0; i--) {
                    if (fa[u][i] && fa[u][i] <= mid + n) u = fa[u][i];
                }
                res += siz[u];
            }
            return res >= z;
        };

        int ans = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << "\n";
    }
}
/*
5 6
2 3
4 5
1 2
1 3
1 4
1 5
6
2 4 3
2 4 4
2 4 5
1 3 3
1 3 4
1 3 5

*/