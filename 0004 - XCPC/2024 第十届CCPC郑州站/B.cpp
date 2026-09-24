// QOJ user: xbbbz
// Contest: 2024 第十届CCPC郑州�?// Problem: #9769. Rolling Stones (9769)
// Submission: https://qoj.ac/submission/1433575
// Language: C++23

#include <bits/stdc++.h>
using namespace std;

namespace Xbbbz {
#define int long long
const int inf = 1e18;
struct Edge {
    int op, dc, v; 
};
struct node {
    int op, mian, x, y, z;
};
    void sol() {
        int n;
        cin >> n;
        int cnt = 0;
        vector<vector<int>> a(n + 5, vector<int>(2 * n + 5)), id(n + 5, vector<int>(2 * n + 5)), opt(n + 5, vector<int>(2 * n + 5)); 
        vector<int> num(n * n + 5);
        for (int i = 1; i <= n; i++) {
            int res = 1;
            for (int j = n - i + 1; j <= n + i - 1; j++) {
                cin >> a[i][j];
                id[i][j] = ++cnt;
                num[cnt] = a[i][j];
                res++;
                opt[i][j] = res & 1;
            }
        }
        int endx, endy;
        cin >> endx >> endy;
        int endu = id[endx][n - endx + endy];
        // cerr << endu << "\n";
        vector<vector<Edge>> ed(n * n + 1);
        for (int i = 1; i <= n; i++) {
            for (int j = n - i + 1; j <= n + i - 1; j++) {
                int op = opt[i][j];
                int u = id[i][j];
                int v = id[i][j - 1];
                if (v) {
                    ed[u].push_back({op, 1, v});
                }
                v = id[i][j + 1];
                if (v) {
                    ed[u].push_back({op, 3, v});
                }

                if (!op) {
                    v = id[i + 1][j];
                    if (v) {
                        ed[u].push_back({op, 2, v});
                        ed[v].push_back({op ^ 1, 2, u});
                    }
                }
            }
        }
        
        auto get = [&](node tt) -> int {
            auto [m1, m2, m3, m4, m5] = tt;
            m1 = m1 * 2 * 5 * 5 * 5;
            m2 = m2 * 5 * 5 * 5;
            m3 = m3 * 5 * 5;
            m4 = m4 * 5;
            return m1 + m2 + m3 + m4 + m5;
        };

        queue<pair<int, node>> q;
        vector<vector<bool>> vis(n * n + 5, vector<bool>(2 * 5 * 5 * 5 * 5));
        vector<vector<int>> dis(n * n + 5, vector<int>(2 * 5 * 5 * 5 * 5, 0));
        q.push({1, {0, 4, 1, 2, 3}});
        while (!q.empty()) {
            auto [u, t] = q.front();
            auto [m1, m2, m3, m4, m5] = t;
            if (u == endu) {
                cout << dis[u][get(t)] << "\n";
                return;
            }
            q.pop();
            if (vis[u][get(t)]) continue;
            vis[u][get(t)] = 1;
            node nd;
            if (!m1) {
                for (Edge edge : ed[u]) {
                    auto[op, dc, v] = edge;
                    if (dc == 1) {
                        nd = {m1 ^ 1, m3, m4, m5, m2};
                    } else if (dc == 2) {
                        nd = {m1 ^ 1, m4, m3, m2, m5};
                    } else {
                        nd = {m1 ^ 1, m5, m2, m3, m4};
                    }
                    auto [d1, d2, d3, d4, d5] = nd;
                    if (num[v] != d2) continue;
                    dis[v][get(nd)] = dis[u][get(t)] + 1;
                    q.push({v, nd});
                }
            } else {
                for (Edge edge : ed[u]) {
                    auto[op, dc, v] = edge;
                    if (dc == 1) {
                        nd = {m1 ^ 1, m3, m4, m5, m2};
                    } else if (dc == 2) {
                        nd = {m1 ^ 1, m4, m3, m2, m5}; 
                    } else {
                        nd = {m1 ^ 1, m5, m2, m3, m4};
                    }
                    auto [d1, d2, d3, d4, d5] = nd;
                    
                    if (num[v] != d2) continue;
                    dis[v][get(nd)] = dis[u][get(t)] + 1;
                    q.push({v, nd});
                }
            }
        }
        cout << "-1\n";
    }

    void main() {
        ios::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
#undef int
}

int main() {
    return Xbbbz::main(), 0;
}

</code>