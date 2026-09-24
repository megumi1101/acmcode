#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++) cin >> c[i];
    vector<vector<int>> ed(n + 1);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ed[x].push_back(y);
        ed[y].push_back(x);
    }

    vector<int> p2(n + 1);
    p2[0] = 1;
    for (int i = 1; i <= n; i++) p2[i] = p2[i - 1] * 2 % mod;

    vector<int> siz(n + 1), f(n + 1, 1);
    [&](this auto &&dfs, int u, int fat) -> void {
        siz[u] = 1;
        for (auto v : ed[u]) {
            if (v == fat) continue;
            dfs(v, u);
            siz[u] += siz[v];
            f[u] = f[u] * f[v] % mod;
        }
        if (c[u] == 1) f[u] = (f[u] + p2[siz[u] - 1]) % mod;
    }(1, 0);
    cout << f[1] << "\n";
}