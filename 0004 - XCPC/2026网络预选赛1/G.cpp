#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    i64 C;
    cin >> n >> m >> C;

    vector<i64> c(n);
    for (auto &x : c) cin >> x;

    vector<vector<int>> e(n), re(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        e[u].push_back(v);
        re[v].push_back(u);
    }

    const int INF = 1e9;

    auto bfs = [&](int s, const vector<vector<int>>& E) {
        vector<int> d(n, INF);
        queue<int> q;
        d[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : E[u]) {
                if (d[v] == INF) {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
        return d;
    };

    auto d1 = bfs(0, e);
    auto dn = bfs(n - 1, re);

    if (d1[n - 1] == INF) {
        cout << 0 << '\n';
        return 0;
    }

    int D = d1[n - 1];

    vector<vector<int>> g(n), rg(n), layer(D + 1);

    for (int u = 0; u < n; u++) {
        if (d1[u] + dn[u] == D)
            layer[d1[u]].push_back(u);
    }

    for (int u = 0; u < n; u++) {
        for (int v : e[u]) {
            if (d1[u] + 1 + dn[v] == D) {
                g[u].push_back(v);
                rg[v].push_back(u);
            }
        }
    }

    vector<u64> f(n), h(n);
    f[0] = 1;

    for (int d = 0; d < D; d++) {
        for (int u : layer[d]) {
            for (int v : g[u])
                f[v] += f[u];
        }
    }

    h[n - 1] = 1;
    for (int d = D; d >= 1; d--) {
        for (int v : layer[d]) {
            for (int u : rg[v])
                h[u] += h[v];
        }
    }

    int mid = 0;
    u64 best = ULLONG_MAX;

    for (int d = 0; d <= D; d++) {
        u64 L = 0, R = 0;
        for (int v : layer[d]) {
            L += f[v];
            R += h[v];
        }
        u64 cur = max(L, R);
        if (cur < best) {
            best = cur;
            mid = d;
        }
    }

    vector<vector<i64>> L(n), R(n);

    auto dfs1 = [&](this auto&& dfs, int u, i64 sum) -> void {
        if (sum > C) return;
        if (d1[u] == mid) {
            L[u].push_back(sum);
            return;
        }
        for (int v : g[u])
            dfs(v, sum + c[v]);
    };

    auto dfs2 = [&](this auto&& dfs, int u, i64 sum) -> void {
        if (sum > C) return;
        if (d1[u] == mid) {
            R[u].push_back(sum);
            return;
        }
        for (int v : rg[u])
            dfs(v, sum + c[v]);
    };

    dfs1(0, c[0]);
    dfs2(n - 1, c[n - 1]);

    u64 ans = 0;

    for (int v : layer[mid]) {
        auto &a = L[v];
        auto &b = R[v];

        // 排序较小的一边
        if (a.size() > b.size()) swap(a, b);

        sort(a.begin(), a.end());

        for (i64 x : b) {
            i64 lim = C + c[v] - x;
            ans += upper_bound(a.begin(), a.end(), lim) - a.begin();
        }
    }

    cout << ans << '\n';
}