#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> ed(n + 1);
    vector<int> fa(n + 1), dep(n + 1);

    for (int i = 2; i <= n; i++) {
        cin >> fa[i];
        ed[fa[i]].push_back(i);
    }

    auto dfs1 = [&](auto&& self, int u) -> void {
        for (int v : ed[u]) {
            dep[v] = dep[u] + 1;
            self(self, v);
        }
    };
    dfs1(dfs1, 1);

    vector<set<pair<int, int>>> s(n + 1);

    while (q--) {
        int u, v;
        cin >> u >> v;
        s[u].insert({-dep[v], v});
    }

    vector<int> pa(n + 1, 1);

    auto dfs2 = [&](auto&& self, int u) -> void {
        for (int v : ed[u]) {
            self(self, v);
        }

        if (!s[u].empty()) {
            auto [d, v] = *s[u].begin();
            pa[u] = v;
            s[u].erase(s[u].begin());
        }

        if (pa[u] != 1) {
            if (s[pa[u]].size() < s[u].size())
                swap(s[pa[u]], s[u]);
            s[pa[u]].merge(s[u]);
        }
    };
    dfs2(dfs2, 1);

    vector<vector<int>> adj(n + 1);

    for (int i = 2; i <= n; i++) {
        adj[pa[i]].push_back(i);
    }

    long long ans = 0;

    auto dfs3 = [&](auto&& self, int u, int d) -> void {
        ans += d;
        for (int v : adj[u]) {
            self(self, v, d + 1);
        }
    };
    dfs3(dfs3, 1, 0);

    cout << ans << "\n";
}