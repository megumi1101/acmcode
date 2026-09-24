#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
    const vector<int> dx = {0, 1, 0, -1};
    const vector<int> dy = {1, 0, -1, 0};

    void sol() {
        int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));
        vector<vector<int>> vis(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];

        vector<pair<int,int>> path;
        bool fg = 0;

        auto dfs = [&](auto &&dfs, int x, int y) -> void {
            if (fg) return;
            if (x == n - 1 && y == n - 1) {
                path.emplace_back(x,y);
                fg = 1;
                return;
            }
            vis[x][y] = 1;
            path.emplace_back(x,y);
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && a[nx][ny] == 0 && !vis[nx][ny]) {
                    dfs(dfs, nx, ny);
                    if (fg) return;
                }
            }
            path.pop_back();
            vis[x][y] = 0;
        };

        if (a[0][0]==0 && a[n - 1][n - 1]==0) dfs(dfs, 0, 0);

        if (!fg) {
            cout << "no path\n";
            return;
        }
        for (int i = 0; i < path.size(); i++) {
            auto[x, y] = path[i];
            cout << "[" << x << "," << y << "]--";
            if (!((i + 1) % 4)) cout << "\n";
        }
        cout << "END\n";
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