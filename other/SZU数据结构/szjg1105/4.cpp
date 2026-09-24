#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
const int inf = 1e9;
    void sol() {
        int n, m;
        cin >> n >> m;
        vector vis(n + 1, vector(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            int x, y;
            cin >> x >> y;
            vis[x][y] = 1;
            vis[y][x] = 1;
        }
        int t;
        cin >> t;
        while (t--) {
            int k;
            cin >> k;
            vector<int> a(k);
            for (auto &i : a) cin >> i;
            bool fg = 1;
            if (a[0] == a[k - 1]) {
                vector<int> vs(n + 1, 0);
                for (int i = 0; i + 1 < k; i++) {
                    if (!vis[a[i]][a[i + 1]]) {
                        fg = 0;
                        break;
                    } else {
                        vs[a[i]]++;
                    }
                }
                for (int i = 1; i <= n; i++) {
                    if (vs[i] != 1) {
                        fg = 0;
                        break;
                    }
                }
            } else fg = 0;
            if (!fg) cout << "NO\n";
            else cout << "YES\n";
        }
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
}

int main() {
    return Xbbbz::main(),0;
}