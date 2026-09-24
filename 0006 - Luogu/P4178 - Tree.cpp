#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
// #define int long long
#define db double
    struct node {
        int v, w;
        node(int v, int w) : v(v), w(w) {}
    };

    template <typename T>
    struct Fenwick {
        int n;
        vector<T> a;
        
        Fenwick(int n_ = 0) {
            init(n_);
        }
        
        void init(int n_) {
            n = n_;
            a.assign(n + 5, T{});
        }
        
        void add(int x, const T &v) {
            for (int i = x; i <= n; i += i & -i) {
                a[i] = a[i] + v;
            }
        }
        
        T sum(int x) {
            T ans{};
            for (int i = x; i; i -= i & -i) {
                ans = ans + a[i];
            }
            return ans;
        }
        
        T getsum(int l, int r) {
            return sum(r) - sum(l - 1);
        }
    };

    void sol() {
        int n, m;
        cin >> n;
        vector<vector<node>> ed(n + 5);
        vector<int> q(n + 5), vis(n + 5), siz(n + 5), dis(n + 5);
        int ans = 0;
        for (int i = 1; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            ed[x].push_back(node(y, z));
            ed[y].push_back(node(x, z));
        }
        
        cin >> m;
        int root = 0, mxt = INT_MAX;
        
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
            Fenwick<int> c(m + 1);
            c.add(1, 1);
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
                    if (m + 1 - it > 0) ans += c.sum(m + 1 - it);
                }
                for (auto it : child) {
                    c.add(it + 1, 1);
                }
            }
        };

        auto dfz = [&](auto self, int u, int fat) -> void { 
            vis[u] = 1;
            calc(u);
            for (auto[v, w] : ed[u]) {
                if (v == fat || vis[v]) continue;
                mxt = INT_MAX;
                if (siz[v] == 1) continue;
                get(get, v, u, siz[v]);
                self(self, root, 0);
            }
        };

        get(get, 1, 0, n);
        dfz(dfz, root, 0);
        
        cout << ans;
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