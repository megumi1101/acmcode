#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e18;
void sol() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> ed(n + 1);

    int mxW = 0;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        ed[u].push_back({v, w});
        ed[v].push_back({u, w});
        mxW = max(mxW, w);
    }

    mxW *= 2;
    vector f(n + 1, vector<int>(mxW + 1, 0));
    // f[u][L] -> min R of (a_u = 0, min a >= -L)
    // think v -> f[u][L]
    // v is right of u => a_v = w; 
    // Lv => Lu + w 
    // Ru >= w + f[v][Lv]

    // v is left of u => a_v = -w;
    // Lv = Lu - w;
    // Ru + w >= f[v][Lv]
    // => Ru >= f[v][Lv] - w;

    // f[u][L] >= min of
    // f[v][Lu + w] + w (Lu + w <= mxW)
    // f[v][Lu - w] - w (Lu - w >= 0)

    // f[u][L] = max of min

    vector<int> ans(n + 1, inf);

    auto dfs = [&](auto &&dfs, int u, int fat) -> void {
        for (auto [v, w] : ed[u]) if (v != fat) {
            dfs(dfs, v, u);
        } 
            
        for (auto [v, w] : ed[u]) if (v != fat) {
            for (int Lu = 0; Lu <= mxW; Lu++) {
                int res = inf;
                if (Lu + w <= mxW) res = min(res, f[v][Lu + w] + w);
                if (Lu - w >= 0) res = min(res, f[v][Lu - w] - w);
                f[u][Lu] = max(f[u][Lu], res);
            }
        }
    };

    dfs(dfs, 1, 0);

    for (int i = 1; i <= n; i++) {
        for (int L = 0; L <= mxW; L++) {
            ans[i] = min(ans[i], L + f[i][L]);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
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
3
3
1 2 1
2 3 1
4
1 2 2
2 3 1
3 4 2
5
1 2 4
1 3 1
2 4 2
2 5 1
*/