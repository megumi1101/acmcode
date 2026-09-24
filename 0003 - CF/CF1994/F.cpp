#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
// #define int long long
#define db double
    struct node {
        int v, id;
        node(int v, int id) : v(v), id(id) {}
    };
    void sol() {
        int n, m;
        cin >> n >> m;
        vector<vector<node>> ed(n + 5), e(n + 5);
        vector<int> dag(n + 5), vis(m + 5), he(n + 5), st;
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            if (z == 1) {
                ed[x].push_back(node(y, i));
                ed[y].push_back(node(x, i));
                dag[x] ^= 1;
                dag[y] ^= 1;
            } 
            else {
                e[x].push_back(node(y, i));
                e[y].push_back(node(x, i));
            }
        }
        
        function<void(int)> dfs = [&](int u) {
            vis[u] = 1;
            for (auto [v, i] : e[u]) {
                if (vis[v]) continue;
                dfs(v);
                if (dag[v]) {
                    ed[u].push_back(node(v, i));
                    ed[v].push_back(node(u, i));
                    dag[v] ^= 1;
                    dag[u] ^= 1;
                }
            }
        };
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                dfs(i);
                if (dag[i]) {
                    cout << "NO\n";
                    return;
                }
            }
        }
 
        fill(vis.begin(), vis.end(), 0);
 
        function<void(int)> euler = [&](int u) {
            for (int &i = he[u]; i < ed[u].size();) {
                int id = ed[u][i].id;
                int v = ed[u][i].v;
                i++;
                if (!vis[id]) {
                    vis[id] = 1;
                    euler(v);
                }
            }
            st.push_back(u);
        };
        cout << "YES\n";
        euler(1);
        reverse(st.begin(), st.end());
        cout << st.size() - 1 << "\n";
        for (int v : st) cout << v << " ";
        cout << "\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        // init();
        int T = 1;
        cin >> T;
        while (T--) sol(); 
    }
#undef int
}
 
int main() {
    return Xbbbz ::main(), 0;
}
