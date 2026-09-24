#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
    void sol() {
        int n; 
        cin >> n;
        vector<string> name(n);
        unordered_map<string,int> id;
        for (int i = 0; i < n; ++i) {
            cin >> name[i];
            id[name[i]] = i;
        }

        int m; 
        cin >> m;
        vector<vector<int>> g(n, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            string a, b; 
            cin >> a >> b;
            int u = id[a], v = id[b];
            g[u][v] = g[v][u] = 1;              
        }

        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << name[i];
        }
        cout << '\n';

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j) cout << ' ';
                cout << g[i][j];
            }
            cout << '\n';
        }

        vector<int> vis(n, 0);
        int comp = 0;
        queue<int> q;
        for (int s = 0; s < n; ++s) if (!vis[s]) {
            ++comp;
            vis[s] = 1; q.push(s);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v = 0; v < n; ++v) {
                    if (g[u][v] && !vis[v]) { vis[v] = 1; q.push(v); }
                }
            }
        }

        cout << comp << '\n';
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