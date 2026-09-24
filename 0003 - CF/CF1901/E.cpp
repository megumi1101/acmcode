#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
const int inf = 1e18;
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector f(n + 1, vector(4, -inf));
    for (int i = 1; i <= n; i++) {cin >> a[i]; f[i][0] = a[i];}
 
    vector<vector<int>> ed(n + 1);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ed[x].push_back(y);
        ed[y].push_back(x);
    }
 
    auto dfs = [&](auto &&dfs, int u, int fat) -> void {
        for (auto v : ed[u]) if (v != fat) {
            dfs(dfs, v, u);
        }
        
        vector<int> p;
        for (auto v : ed[u]) if (v != fat) {
            f[u][1] = max(f[u][1], a[u] + max({f[v][0], f[v][1] - a[v], f[v][2], f[v][3]}));
            int t = max({f[v][0], f[v][1] - a[v], f[v][2], f[v][3]});
            p.push_back(t);
        }
        sort(p.rbegin(), p.rend());
        if(p.size() >= 2) f[u][2] = a[u] + p[0] + p[1];
        if(p.size() >= 3) {
            f[u][3] = a[u] + p[0] + p[1] + p[2];
            for (int i = 3; i < p.size(); i++) {
                if (p[i] > 0) {
                    f[u][3] += p[i];
                } else {
                    break;
                }
            }
        }
        // cerr << u << " :";
        // for (int i = 0; i <= 3; i++) cerr << f[u][i] << " ";
        // cerr << "\n";
    };
    dfs(dfs, 1, 0);
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int t = max({f[i][0], f[i][1], f[i][2] - a[i], f[i][3]});
        // cerr << t << "\n";
        ans = max(ans, t);
    }
    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int T;
    cin >> T;
    while (T--) sol();
}
