#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e18;
const int mod = 998244353;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    vector ed(n + 1, vector(10, vector<int>{}));
    
    for (int i = 1; i <= m; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        ed[x][c].push_back(y);
    }

    vector<int> vis(n + 1);

    priority_queue<array<int, 4>> q;
    q.push({0, 0, 1, 0});
    vector<int> ans(n + 1);

    int cnt = 0;
    vector to(n, array<int, 10>{}) ;
    while (!q.empty()) {
        auto[tim, cc, u, val] = q.top();
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        ans[u] = val;

        tim = -tim;
        cc = -cc;
        if (to[tim][cc] == 0) {
            to[tim][cc] = ++cnt;
        }
        tim = to[tim][cc];

        for (int c = 1; c <= 9; c++) {
            for (auto v : ed[u][c]) {
                q.push({-tim, -c, v, (val * 10 + c) % mod});
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        cout << ans[i] << "\n";
    }
}

