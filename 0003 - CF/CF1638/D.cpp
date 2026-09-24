 #include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int inf = 1e18;
    void sol() {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        vector<vector<int>> vis(n, vector<int>(m));
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        vector<tuple<int, int, int>> ans;
        queue<pair<int, int>> q;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m - 1; j++) {
                if (a[i][j] == a[i][j + 1] && a[i][j] == a[i + 1][j] && a[i][j] == a[i + 1][j + 1]) {
                    ans.emplace_back(i, j, a[i][j]);
                    q.emplace(i, j);
                    q.emplace(i + 1, j);
                    q.emplace(i, j + 1);
                    q.emplace(i + 1, j + 1);
                    vis[i][j] = vis[i + 1][j] = vis[i][j + 1] = vis[i + 1][j + 1] = 1;
                }
            }
        }
        
        auto pp = [&](int x, int y, int op1, int op2) -> void {
            if (x + op1 >= 0 && x + op1 < n && y + op2 < m && y + op2 >= 0) {
                int t = -1;
                if (!vis[x + op1][y]) t = a[x + op1][y];
                if (!vis[x][y + op2]) {
                    if (t != -1 && t != a[x][y + op2]) return;
                    t = a[x][y + op2]; 
                }
                if (!vis[x + op1][y + op2]) {
                    if (t != -1 && t != a[x + op1][y + op2]) return;
                    t = a[x + op1][y + op2]; 
                }
                if (t == -1) return;
                if (op1 == 1 && op2 == 1) ans.emplace_back(x, y, t); 
                if (op1 == 1 && op2 == -1) ans.emplace_back(x, y - 1, t); 
                if (op1 == -1 && op2 == 1) ans.emplace_back(x - 1, y, t); 
                if (op1 == -1 && op2 == -1) ans.emplace_back(x - 1, y - 1, t); 
 
                if (!vis[x + op1][y]) q.emplace(x + op1, y);
                if (!vis[x][y + op2]) q.emplace(x, y + op2);
                if (!vis[x + op1][y + op2]) q.emplace(x + op1, y + op2);
 
                vis[x + op1][y] = vis[x][y + op2] = vis[x + op1][y + op2] = 1;
            }
        };
 
        while (!q.empty()) {
            auto[x, y] = q.front();
            q.pop();
            pp(x, y, 1, 1);
            pp(x, y, 1, -1);
            pp(x, y, -1, 1);
            pp(x, y, -1, -1);
        }
 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j]) {
                    cout << "-1\n";
                    return;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for (auto [x, y, z] : ans) {
            cout << x + 1 <<  " " << y + 1 << " " << z << "\n";
        }
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
#undef int 
}
 
int main() {
    return Xbbbz::main(), 0;
}
