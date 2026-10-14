#include <bits/stdc++.h>

using namespace std;

struct Node {
    map<int, int> ch;
    vector<pair<int, int>> path;
    int fa = 0, dep = 0;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> ed(n + 1);
    for (int j = 0; j < m; j++) {
        int x, y;
        int w;
        cin >> x >> y >> w;
        ed[x].push_back({y, w});
    }
    for (auto &a : ed) sort(a.begin(), a.end(), [](const auto &x, const auto &y) {
        return x.second < y.second;
    });
    vector<Node> tr(1);
    tr.reserve(n + 2 * k + 5);
    auto add = [&](int p, int x, int i) {
        if (i >= (int)ed[x].size()) return;
        int w = ed[x][i].second;
        int u = tr[p].ch[w];
        if (!u) {
            u = (int)tr.size();
            tr[p].ch[w] = u;
            tr.emplace_back();
            tr[u].fa = p;
            tr[u].dep = tr[p].dep + 1;
        }
        tr[u].path.push_back({x, i});
    };

    for (int x = 1; x <= n; x++) add(0, x, 0);
    int cnt = 0;
    auto dfs = [&](auto &&self, int u) -> void {
        while (cnt < k && !tr[u].path.empty()) {
            auto [x, i] = tr[u].path.back();
            tr[u].path.pop_back();
            cout << tr[u].dep << '\n';
            if (++cnt == k) return;
            int v = ed[x][i].first, p = tr[u].fa;
            add(u, v, 0);       
            add(p, x, i + 1);   
        }

        for (auto [w, v] : tr[u].ch) {
            if (cnt == k) return;
            self(self, v);
        }
    };
    dfs(dfs, 0);
    while (cnt < k) cout << -1 << '\n', cnt++;
    return 0;
}