#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> ed(n + 1);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ed[x].push_back(y);
        ed[y].push_back(x);
    }

    double ans = 0;
    auto dfs = [&](auto &&self, int u, int fat, int deep) -> void {
        ans += 1.0 / deep;
        for (auto v : ed[u]) {
            if (v == fat) continue;
            self(self, v, u, deep + 1);
        }
    };
    dfs(dfs, 1, 0, 1);

    cout << fixed << setprecision(12) << ans << "\n";
}