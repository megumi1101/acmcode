#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
vector<pair<int, int>> dxy = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void sol() {
        int n, m;
        cin >> n >> m;
        vector<string> s(n);
        vector vis(n, vector<int>(m, 0));
        for (auto &i : s) cin >> i;
        for (int i = 0; i < m; i++) {
            if (s[0][i] == 'U') vis[0][i] = 1;
            if (s[n - 1][i] == 'D') vis[n - 1][i] = 1;
        }
        for (int i = 0; i < n; i++) {
            if (s[i][0] == 'L') vis[i][0] = 1;
            if (s[i][m - 1] == 'R') vis[i][m - 1] = 1;
        }
 
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j]) q.emplace(i, j);
                vis[i][j] = 0;
            }
        }
        // cerr << q.size() << "\n";
        while (!q.empty()) {
            auto[x, y] = q.front();
            q.pop();
            if (vis[x][y]) continue;
            vis[x][y] = 1;
            for (int i = 0; i < 4; i++) {
                auto[dx, dy] = dxy[i];
                int tx = x + dx;
                int ty = y + dy;
                if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
                if (i == 0 && s[tx][ty] == 'U') {
                    q.emplace(tx, ty);
                }
                if (i == 1 && s[tx][ty] == 'D') {
                   q.emplace(tx, ty);
                }
                if (i == 2 && s[tx][ty] == 'L') {
                    q.emplace(tx, ty);
                } 
                if (i == 3 && s[tx][ty] == 'R') {
                    q.emplace(tx, ty);
                }
            }
        }
 
 
        int ans = n * m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s[i][j] == '?') {
                    bool fg = 1;
                    for (auto[dx, dy] : dxy) {
                        int tx = i + dx;
                        int ty = j + dy;
                        if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
                        if (!vis[tx][ty]) fg = 0;
                    }
                    vis[i][j] = fg;
                }
                if (vis[i][j]) ans--;
            }
        }
        cout << ans << "\n";
    }
    
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
#undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
 
