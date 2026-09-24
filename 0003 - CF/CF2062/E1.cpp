#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int inf = 2e18;
    void sol() {
        int n;
        cin >> n;
        vector<int> w(n + 1);
        for (int i = 1; i <= n; i++) cin >> w[i];
        vector<vector<int>> ed(n + 1);
        for (int i = 1; i < n; i++) {
            int x, y;
            cin >> x >> y;
            ed[x].push_back(y);
            ed[y].push_back(x);
        }
 
        vector<int> f(n + 1, 0);
        vector<int> tin(n + 1), tout(n + 1), eul(n + 1);
        int timer = 0;
 
        auto dfs = [&](auto &&dfs, int u, int fat) -> void {
            tin[u] = ++timer;
            eul[timer] = u;
            for (int v : ed[u]) if (v != fat) dfs(dfs, v, u);
            tout[u] = timer;
        };
        dfs(dfs, 1, 0);
 
        vector<int> arr(n + 2);
        for (int i = 1; i <= n; i++) arr[i] = w[eul[i]];
 
        vector<int> pref(n + 2), suff(n + 2);
        for (int i = 1; i <= n; i++) pref[i] = max(pref[i - 1], arr[i]);
        for (int i = n; i >= 1; i--) suff[i] = max(suff[i + 1], arr[i]);
 
        int now = 0;
        for (int u = 1; u <= n; u++) {
            f[u] = max(pref[tin[u] - 1], suff[tout[u] + 1]);
            if (f[u] > w[u]) {
                if (w[u] > w[now]) now = u;
            }
        }
        cout << now << "\n";
        
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
