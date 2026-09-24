#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
#define db double
    struct node {
        int v, w;
        node(int v, int w) : v(v), w(w) {}
    };
    void sol() {
        int n, m;
        cin >> n >> m;
        vector<vector<node>> ed(n + 5);
        vector<int> q(n + 5), ans(n + 5), vis(n + 5), siz(n + 5), dis(n + 5);
        for (int i = 1; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            ed[x].push_back(node(y, z));
            ed[y].push_back(node(x, z));
        }
        for (int i = 1; i <= m; i++) {
            cin >> q[i];
        }

        int root = 0, mxt = 1e18;
        
        auto get = [&](auto self, int u, int fat, int n) -> void { 
            siz[u] = 1;
            int tmp = 0;
            for (auto[v, w] : ed[u]) {
                if (v == fat || vis[v]) continue;
                self(self, v, u, n);
                siz[u] += siz[v];
                tmp = max(siz[v], tmp);
            }
            tmp = max(tmp, n - siz[u]);
            if (tmp < mxt) {
                mxt = tmp;
                root = u;
            }
        };
        
        auto calc = [&](int u) { 
            set<int> pre = {0}; 
            dis[u] = 0;
            for (auto [v, w] : ed[u]) {
                if (vis[v]) continue;
                vector<int> child; 
                auto dfs = [&] (auto self, int u, int fat) -> void {
                    child.push_back(dis[u]);
                    for (auto[v, w] : ed[u]) {
                        if (v == fat || vis[v]) continue;
                        dis[v] = dis[u] + w;
                        self(self, v, u);
                    }
                };
                dis[v] = w;
                dfs(dfs, v, u);
                for (auto it : child) {
                    for (int i = 1; i <= m; i++) { 
                        if (q[i] < it || !pre.count(q[i] - it)) continue;
                        ans[i] = 1;
                    }
                }
                pre.insert(child.begin(), child.end());
            }
        };

        auto dfz = [&](auto self, int u, int fat) -> void { 
            vis[u] = 1;
            calc(u);
            for (auto[v, w] : ed[u]) {
                if (v == fat || vis[v]) continue;
                mxt = 1e18;
                get(get, v, u, siz[v]);
                self(self, root, 0);
            }
        };

        get(get, 1, 0, n);
        dfz(dfz, root, 0);

        for (int i = 1; i <= m; i++) {
            if (ans[i]) cout << "AYE\n";
            else cout << "NAY\n";
        }
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        // init();
        int T = 1;
        // cin >> T;
        while (T--) sol(); 
    }
#undef int
}

int main() {
    return Xbbbz ::main(), 0;
}