#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    const int N = 1e6 + 5, mod = 1e9 + 7;
    vector<int> g[N];
    int x[N], y[N], to[N], used[N];
 
    array<int, 3> dfs(int u, int fa) {
        to[u] = 1;
        array<int, 3> ans = {1, used[u], (int) g[u].size()};
        for (int v : g[u]) {
            if (v != fa && !to[v]) {
                auto res = dfs(v, u);
                ans[0] += res[0];
                ans[1] += res[1];
                ans[2] += res[2];
            }
        }
        return ans;
    }
 
    void sol() {
        int n, m, k, cnt = 0, ans = 1;
        cin >> n >> m >> k;
        k++;
        vector<vector<int>> num(n + 2, vector<int>(m + 2));
        
        for (int i = 1; i <= n * m; i++) {
            g[i].clear();
            to[i] = 0;
            used[i] = 0;
        }
 
        for (int i = 1; i <= k; i++) {
            cin >> x[i] >> y[i];
        }
 
        for (int i = 1; i < k; i++) {
            if (abs(x[i] - x[i + 1]) + abs(y[i] - y[i + 1]) != 2) {
                cout << 0 << "\n";
                return;
            }
        }
 
        for (int i = 1; i < k; i++) {
            if (x[i] == x[i + 1] || y[i] == y[i + 1]) {
                int xx = (x[i] + x[i + 1]) / 2;
                int yy = (y[i] + y[i + 1]) / 2;
                if (!num[xx][yy]) {
                    num[xx][yy] = ++cnt;
                }
                if (used[num[xx][yy]]) {
                    cout << 0 << "\n";
                    return;
                }
                used[num[xx][yy]] = 1;
            }
        }
 
        for (int i = 1; i < k; i++) {
            if (abs(x[i] - x[i + 1]) == 1) {
                if (!num[x[i]][y[i + 1]]) {
                    num[x[i]][y[i + 1]] = ++cnt;
                }
                if (!num[x[i + 1]][y[i]]) {
                    num[x[i + 1]][y[i]] = ++cnt;
                }
                g[num[x[i]][y[i + 1]]].push_back(num[x[i + 1]][y[i]]);
                g[num[x[i + 1]][y[i]]].push_back(num[x[i]][y[i + 1]]);
            }
        }
 
        for (int i = 1; i <= cnt; i++) {
            if (!to[i]) {
                auto p = dfs(i, 0);
                p[2] /= 2;
                if (p[2] < p[0]) {
                    if (!p[1]) {
                        ans = 1ll * ans * p[0] % mod;
                    } else if (p[1] > 1) {
                        cout << 0 << "\n";
                        return;
                    }
                } else if (p[2] == p[0]) {
                    if (!p[1]) {
                        ans = 1ll * ans * 2 % mod;
                    } else {
                        cout << 0 << "\n";
                        return;
                    }
                } else {
                    cout << 0 << "\n";
                    return;
                }
            }
        }
        cout << ans << "\n";
    }
 
    void main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int T;
        cin >> T;
        while (T--) {
            sol();
        }
    }
}
 
int main() {
    return Xbbbz::main(), 0;
}
