#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int mod = 998244353;
const int inf = 1e18;
    void sol() {
        int n;
        cin >> n;
        vector<vector<int>> ed(n + 1);
        vector<int> dep(n + 1);
        vector<int> mndep(n + 1, inf), dis(n + 1, 0);
        for (int i = 1; i < n; i++) {
            int x, y;
            cin >> x >> y;
            ed[x].push_back(y);
            ed[y].push_back(x);
        }
        
        vector<int> f(n + 1, inf), g(n + 1, inf), h(n + 1, inf);
        int ans = 0;
        auto dfs = [&](auto &&dfs, int u, int fat, int deep) -> void {
            dep[u] = deep;
            if (u != 1 && ed[u].size() == 1) {
                f[u] = 0;
                g[u] = 1;
                h[u] = 2;
                mndep[u] = deep;
                return;
            }
            
            set<pair<int, int>> s;
 
            int mx = 0;
            int sed = 0;
            for (auto v : ed[u]) {
                if (v == fat) continue;
                dfs(dfs, v, u, deep + 1);
                mndep[u] = min(mndep[u], mndep[v]);
                if (dis[v] + 1 > mx) mx = dis[v] + 1;
                else if (dis[v] + 1 > sed) sed = dis[v] + 1;
                
            }
 
            dis[u] = mndep[u] - dep[u];
            if (u != 1) {
                ans = max(ans, mx + 1);
            } else {
                ans = max(ans, mx);
                ans = max(ans, sed + 1);
            }
        };
        dfs(dfs, 1, 0, 1);
        cout << ans << "\n";
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
}
#undef int
 
int main() {
    return Xbbbz::main(), 0;
}
