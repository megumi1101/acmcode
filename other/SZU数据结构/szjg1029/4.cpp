#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
    void sol() {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> ed(n);
        for (int i = 0; i < m; ++i) {
            int u, v; 
            cin >> u >> v;
            ed[u].push_back(v);
            ed[v].push_back(u);
        }
        int s; 
        cin >> s;

        for (int i = 0; i < n; ++i) {
            sort(ed[i].begin(), ed[i].end());
            ed[i].erase(unique(ed[i].begin(), ed[i].end()), ed[i].end());
        }

        vector<int> vis(n, 0), order;


        auto bfs = [&] (int s) {
            queue<int> q;
            vis[s] = 1; 
            q.push(s);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                order.push_back(u);
                for (int v : ed[u]) if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        };
        

        cout << "BFS from " << s << ": ";
        bfs(s);
        for (int i = 0; i < n; i++) if (!vis[i]) bfs(i);
        for (int i = 0; i < (int)order.size(); ++i) {
            if (i) cout << ' ';
            cout << order[i];
        }
        cout << '\n';
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