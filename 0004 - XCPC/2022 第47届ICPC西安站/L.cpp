// QOJ user: lnxbb
// Contest: 2022 ç¬?7å±ŠICPCè¥¿å®‰ç«?// Problem: #5124. Tree (5124)
// Submission: https://qoj.ac/submission/1664966
// Language: C++23

#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
const int inf = 1e9;
    void sol() {
        int n;
        cin >> n;
        vector<vector<int>> ed(n + 1);
        
        for (int i = 2; i <= n; i++) {
            int x;
            cin >> x;
            ed[x].push_back(i);
        }
        


        vector<int> siz(n + 1), dep(n + 1), dis(n + 1);
        auto dfs = [&](auto &&dfs, int u, int fat) -> void {
            dep[u] = dep[fat] + 1;
            for (auto v : ed[u]) {
                dfs(dfs, v, u);
                dis[u] = max(dis[u], 1 + dis[v]);
            }
        };
        dfs(dfs, 1, 0);
        
        int ans = inf;
        for (int i = 1; i <= n; i++) siz[dis[i]]++;
        for (int i = 0; i < n; i++) {
            ans = min(ans, i + siz[i]);
        }
        cout << ans << "\n";
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
</code>