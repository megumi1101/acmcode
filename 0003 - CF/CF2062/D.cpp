#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int inf = 2e18;
    void sol() {
        int n;
        cin >> n;
        vector<int> L(n + 1), R(n + 1), tim(n + 1);
        for (int i = 1; i <= n; i++) cin >> L[i] >> R[i];
        int now = 0;
        vector<vector<int>> ed(n + 1);
        for (int i = 1; i < n; i++) {
            int x, y;
            cin >> x >> y;
            ed[x].push_back(y);
            ed[y].push_back(x);
        }
        
        vector<int> f(n + 1);
        auto dfs = [&](auto &&dfs, int u, int fat) -> void {
            if (ed[u].size() == 1 && u != 1) {
                f[u] = L[u]; 
                return;
            }
            for (auto v : ed[u]) if (v != fat) {
                dfs(dfs, v, u);
            }
            int mx = 0;
            vector<int> a;
            for (auto v : ed[u]) if (v != fat) {
                f[v] += now - tim[v];
                mx = max(mx, f[v]);
                a.push_back(f[v]);
            }
            
            int t1 = 0;
            if (mx > R[u] + now) {
                f[u] = R[u] + now;
                for (auto v : ed[u]) if (v != fat) 
                if (f[v] > f[u]) t1 += f[v] - f[u];
            }
            else if (mx < L[u] + now) {
                f[u] = L[u] + now;
            } else f[u] = mx;
            // int t1 = get(a, f[u]);
            f[u] += t1;
            now += t1;
            tim[u] = now;
        };
 
        dfs(dfs, 1, 0);
        cout << f[1] << "\n";
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
    return Xbbbz::main(),0;
}
