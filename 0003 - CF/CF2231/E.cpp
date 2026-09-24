#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
void sol() {
    int n, d;
    cin >> n >> d;
 
    vector f(n + 1, vector(n + 1, array<int, 4>{}));
    vector<vector<int>> ed(n + 1);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ed[x].push_back(y);
        ed[y].push_back(x);
    }
    
    vector<int> siz(n + 1);
    int ans = 0;
    [&](this auto &&dfs, int u, int fat) -> void {
        siz[u] = 1;
        f[u][1][1] = f[u][1][0] = 1;
        for (auto v : ed[u]) if (v != fat) {
            dfs(v, u);
            vector nf(siz[u] + siz[v] + 1, array<int, 4>{});
            for (int du = 0; du <= siz[u]; du++) {
                for (int x = 0; x <= 3; x++) {
                    nf[du][x] = f[u][du][x];
                }
            }
 
            for (int x = 0; x <= 2; x++) {
                for (int du = 1; du <= siz[u]; du++) {
                    for (int y = 1; y <= 2; y++) {
                        if (x + y > 3) continue;
                        for (int dv = 1; dv <= siz[v]; dv++) {
                            nf[du + dv][x + y] += f[u][du][x] * f[v][dv][y]; 
                        }
                    }
                }
            }
            siz[u] += siz[v];
            for (int du = 0; du <= siz[u]; du++) {
                for (int x = 0; x <= 3; x++) {
                    f[u][du][x] = nf[du][x];
                }
            }
        }
        ans += f[u][d][3];
    } (1, 0);
 
    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
