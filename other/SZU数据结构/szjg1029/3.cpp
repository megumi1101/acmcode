#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
    void sol() {
        int n; 
        cin >> n;
        vector g(n, vector(n, 0));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> g[i][j];

        vector<int> vis(n, 0), seq;

        auto dfs = [&](auto &&dfs, int u) -> void {
            vis[u] = 1;
            seq.push_back(u);
            for (int v = 0; v < n; ++v) {
                if (g[u][v] && !vis[v]) dfs(dfs, v);
            }
        };

        for (int i = 0; i < n; i++) if (!vis[i]) dfs(dfs, i);        

        for (int x : seq) cout << x << ' ';
        cout << '\n';
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
}

int main() {
    return Xbbbz::main(),0;
}