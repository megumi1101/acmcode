#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
const int inf = 1e9;
    

    void sol() { 
        int n, m, k;
        cin >> n >> m >> k;
        vector<string> s(n + 5);
        vector<vector<int>> bh(n + 5, vector<int>(m + 5)), a(n + 5, vector<int>(m + 5)), lt(n + 5, vector<int>(m + 5));
        vector<int> tx (n * m + 5), ty(n * m + 5);

        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
            s[i] = " " + s[i];
            for (int j = 1; j <= m; j++) {
                bh[i][j] = ++cnt;
                a[i][j] = s[i][j] - '0';
                tx[cnt] = i;
                ty[cnt] = j;
                // if (a[i][j] == 1) dsu.f[cnt] = -1;
            }
        }
        

        vector<vector<int>> vis(n + 5, vector<int>(m + 5));
        vector<vector<int>> vis2(n + 5, vector<int>(m + 5));

        vector<int> dy = {-1, 0, 0};
        vector<int> dx = {0, 1, -1};
        
            queue<int> q;
            q.push(bh[1][m]);
            vis[1][m] = 1;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int i = 0; i < 3; i++) {
                    int x = tx[u] + dx[i];
                    int y = ty[u] + dy[i];
                    if (x >= 1 && x <= n && y >= 1 && y <= m) {
                        if (!vis[x][y] && a[x][y] == 0) {
                            q.push(bh[x][y]);
                            vis[x][y] = 1;
                            // cerr << x << " " << y << "\n";
                        }
                    }
                }
            }
            
        vector<int> dy2 = {1, 0, 0};
        vector<int> dx2 = {0, 1, -1};
            q.push(bh[1][1]);
            vis2[1][m] = 1;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int i = 0; i < 3; i++) {
                    int x = tx[u] + dx2[i];
                    int y = ty[u] + dy2[i];
                    if (x >= 1 && x <= n && y >= 1 && y <= m) {
                        if (!vis2[x][y] && a[x][y] == 0) {
                            q.push(bh[x][y]);
                            vis2[x][y] = 1;
                            // cerr << x << " " << y << "\n";
                        }
                    }
                }
            }
        
        
        cnt = 0;

        vector<int> tr(n * m + 5) ,rd(n * m + 5);
        vector<vector<int>> ed(n * m + 5);
        vector<vector<int>> edf(n * m + 5);

        for (int j = m; j >= 1; j--) {
            for (int i = 1; i <= n; i++) {
                if (a[i][j] == 0) {
                    if (i == 1 || a[i - 1][j] == 1) {
                        cnt++;
                        lt[i][j] = cnt;
                    }
                    else {
                        lt[i][j] = cnt;
                    }
                    if (vis[i][j] == 0 && vis2[i][j] == 1) {
                        tr[cnt] = 1;
                    }
                }
            }
            if (j != m) { 
                int lx = 0, ly = 0, x, y;
                for (int i = 1; i <= n; i++) {
                    if (a[i][j] == 0 && a[i][j + 1] == 0) {
                       x = lt[i][j];
                       y = lt[i][j + 1];
                       if (x != lx || y != ly) {
                            ed[x].push_back(y);
                            rd[y]++;
                            edf[y].push_back(x);
                       }
                       lx = x;
                       ly = y;
                    }
                }
            }
        }
        
        // queue<int> q;
        // vector<int> bian;
        // for (int i = 1; i <= cnt; i++)
        //     if (!rd[i]) q.push(i);
        // while (!q.empty()) {
        //     int u = q.front();
        //     q.pop();
        //     bian.push_back(u);
        //     for (int v : ed[u]) {
        //         rd[v]--;
        //         if (!rd[v]) q.push(v);
        //     }
        // }
        
        vector<int>  dep(n * m + 5);

        auto dfs = [&] (auto &&dfs, int u, int deep) -> void {
            dep[u] = deep;
            for (auto v : edf[u]) {
                if (!dep[v]) dfs(dfs, v, deep + 1);
            }
        };

        for (int i = 1; i <= cnt; i++) {
            if (!dep[i]) {
                dfs(dfs, i, 1);
            }
        }
        
        bool fg = 0;
        for (int i = 1; i <= cnt; i++) {
            // cerr << i << " " << tr[i] << "\n";
            if (tr[i] && dep[i] >= k) {
                fg = 1;
            }
        }
        if (fg) cout << "Yes\n";
        else cout << "No\n";
    }

    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
#undef int
}
 

int main() {
    return Xbbbz::main(), 0;
}