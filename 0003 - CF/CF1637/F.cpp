#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
    void sol() {
        int n;
        cin >> n;
        vector<int> h(n + 1);
        int rt = 1;
        for (int i = 1; i <= n; i++) cin >> h[i];
        for (int i = 1; i <= n; i++) if (h[i] > h[rt]) rt = i;
        vector<vector<int>> ed(n + 1);
        for (int i = 1; i < n; i++) {
            int x, y;
            cin >> x >> y;
            ed[x].push_back(y);
            ed[y].push_back(x);
        }
        cerr << rt << "\n";
        int ans = 0;
        auto dfs = [&](auto &&dfs, int u, int fat) -> void {
            int mx1 = 0, mx2 = 0;
            for (auto v : ed[u]) if (v != fat) {
                dfs(dfs, v, u);
                if (h[v] > mx1) {
                    mx2 = mx1;
                    mx1 = h[v];
                }
                else if (h[v] > mx2) {
                    mx2 = h[v];
                }
            }
            if (u != rt) ans += max((int)0, h[u] - mx1);
            else ans += max((int)0, h[u] - mx1) + max((int)0, h[u] - mx2);
            h[u] = max(h[u], mx1);
            cerr << u << "  " << ans << "\n";
        };
        dfs(dfs, rt, 0);
        cout << ans << "\n";
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
    return Xbbbz::main(),0;
}
