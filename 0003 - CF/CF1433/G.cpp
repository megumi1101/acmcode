 
#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int inf = 1e18;
    void sol() {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<pair<int, int>>> ed(n + 1);
        vector<tuple<int, int, int>> egs(m);
        for (auto &[u, v, w] : egs) {
            cin >> u >> v >> w;
            ed[u].emplace_back(v, w);
            ed[v].emplace_back(u, w);
        }
        
        auto dij = [&] (int s, vector<int> &d) -> void {
            fill(d.begin(), d.end(), inf);
            d[s] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
            q.emplace(d[s], s);
            while (!q.empty()) {
                auto[cost, u] = q.top();
                q.pop();
                if (d[u] == cost) {
                    for (auto[v, w] : ed[u]) {
                        if (d[u] + w < d[v]) {
                            d[v] = d[u] + w;
                            q.emplace(d[v], v);
                        }
                    }
                }
            }
        };
        vector dis(n + 1, vector(n + 1, (int)0));
 
        for (int i = 1; i <= n; i++) dij(i, dis[i]);
 
        vector<pair<int, int>> qrys(k);
        for (auto &[l, r] : qrys) cin >> l >> r;
        int ans = inf;
        for (auto [u, v, w] : egs) {
            int sum = 0;
            for (auto [l, r] : qrys) {
                int mn = inf;
                mn = min({mn, dis[l][r], dis[l][u] + dis[r][v], dis[l][v] + dis[r][u]});
                sum += mn;
            }
            ans = min (ans, sum);
        }
        cout << ans << '\n';
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
}
 
#undef int
int main() {
    return Xbbbz::main(), 0;
}
