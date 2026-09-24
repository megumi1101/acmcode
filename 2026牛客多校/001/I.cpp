#include<bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 998244353;

void sol() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<pair<int, int>> e(m);
    vector<vector<pair<int, int>>> ed(n + 1);

    for (int i = 0; i < m; i++) {
        auto &[u, v] = e[i];
        cin >> u >> v;
        ed[u].push_back({v, i});
        ed[v].push_back({u, i});
    }

    vector<int> dfn(n + 1), low(n + 1), bridge(m);
    int tim = 0;
    auto dfs = [&](auto &&dfs, int u, int pe) -> void {
        dfn[u] = low[u] = ++tim;
        for (auto [v, id] : ed[u]) {
            if (id == pe) continue;
            if (!dfn[v]) {
                dfs(dfs, v, id);
                low[u] = min(low[u], low[v]);
                if (low[v] > dfn[u]) bridge[id] = 1;
            } else {
                low[u] = min(low[u], dfn[v]);
            }
        }
    };
    dfs(dfs, 1, -1);

    int ban = -1;
    for (int i = 0; i < m; i++) {
        if (!bridge[i] && a[e[i].first] != a[e[i].second]) {
            ban = i;
            break;
        }
    }

    if (ban == -1) {
        cout << "No\n";
        return;
    }
    int s = e[ban].first;
    int t = e[ban].second;

    vector<int> dep(n + 1, -1);
    queue<int> q;
    dep[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto [v, id] : ed[u]) {
            if (id == ban || dep[v] != -1) continue;
            dep[v] = dep[u] + 1;
            q.push(v);
        }
    }

    vector<pair<int, int>> ans(m);
    for (int i = 0; i < m; i++) {
        if (i == ban) continue;
        auto [u, v] = e[i];
        if (make_pair(dep[u], u) > make_pair(dep[v], v)) {
            ans[i] = {u, v};
        } else {
            ans[i] = {v, u};
        }
    }

    ans[ban] = {s, t};
    cout << "Yes\n";
    for (auto [u, v] : ans) {
        cout << u << ' ' << v << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
}
/*
2
4 5
1 2 3 4
1 2
1 3
1 4
2 3
3 4
2 1
4 -3
1 2
*/