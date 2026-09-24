#include <bits/stdc++.h>

using namespace std;

#define int long long

void sol() {
    int n;
    cin >> n;
    vector<int> fa(n + 1), dep(n + 1);
    vector<vector<int>> ed(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        ed[u].push_back(v);
        ed[v].push_back(u);
    }

    int rt = 1;
    int c = 1;

    auto dfs = [&](this auto &&dfs, int u, int fat, int deep) -> void {
        dep[u] = deep;
        if (dep[u] > dep[c]) {
            c = u;
        }
        for (auto v : ed[u]) if (v != fat) {
            fa[v] = u;
            dfs(v, u, deep + 1);
        }
    };

    dfs(rt, 0, 1);

    fill(dep.begin(), dep.end(), 0);
    rt = c;
    dfs(rt, 0, 1);

    vector<int> p;
    while (c != rt) {
        p.push_back(c);
        c = fa[c];
    }
    p.push_back(rt);

    int siz = p.size();
    int mxdep = siz / 2;
    int rt1 = p[siz / 2 - 1];
    int rt2 = p[siz / 2];

    auto work = [&](int rt, int ban) {
        vector<int> f(n + 1), ans;
        [&](this auto &&dfs, int u, int fat, int deep) -> void {
            if (deep == mxdep) {
                f[u] = 1;
                ans.push_back(deep - 1);
                return;
            }
            int cnt = 0;
            for (auto v : ed[u]) if (v != fat && v != ban) {
                dfs(v, u, deep + 1);
                cnt += f[v];
            }
            f[u] = (cnt > 0);
            if (cnt >= 2) {
                ans.push_back(deep - 1);
            }
        }(rt, 0, 1);

        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    };

    auto a = work(rt1, rt2);
    auto b = work(rt2, rt1);

    vector<int> ok(n + 1);

    for (auto x : a) {
        for (auto y : b) {
            ok[x + y + 1] = 1;
        }
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (ok[i]) ans.push_back(i);
    }
    cout << ans.size() << " ";
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) sol();
}