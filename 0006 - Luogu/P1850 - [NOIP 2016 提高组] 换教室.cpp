#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
    #define int long long
    #define db double
    const int N = 2e3 + 10;
    db f[N][N][2];
    void sol() {
        int n, m ,v, e;
        cin >> n >> m >> v >> e;
        int dis[v + 5][v + 5];
        memset(dis, 0x3f, sizeof(dis));
        int c[n + 5], d[n + 5];
        for (int i = 1; i <= n; i++) cin >> c[i];
        for (int i = 1; i <= n; i++) cin >> d[i];
        
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= m; j++) 
                f[i][j][0] = f[i][j][1] = 1e18;
        
        db p[n + 5];
        for (int i = 1; i <= n; i++) cin >> p[i];
        
        for (int i = 1; i <= e; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            dis[x][y] = min(dis[x][y], z);
            dis[y][x] = min(dis[y][x], z);
        }
        for (int i = 1; i <= v; i++) dis[i][i] = 0;
        for (int k = 1; k <= v; k++)
            for (int i = 1; i <= v; i++) 
                for (int j = 1; j <= v; j++) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
        
        f[1][0][0] = 0.0;
        f[1][1][1] = 0.0;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= min(i, m); j++) {
                f[i][j][0] = min(f[i - 1][j][0] + (db)dis[c[i]][c[i - 1]], 
                    f[i - 1][j][1] + (1.0 - p[i - 1]) * (db)dis[c[i]][c[i - 1]] + p[i - 1] * (db)dis[c[i]][d[i - 1]]);
                if (j > 0) {
                    f[i][j][1] = min(f[i - 1][j - 1][0] + (1.0 - p[i]) * (db)dis[c[i]][c[i - 1]] 
                            + p[i] * (db)dis[d[i]][c[i - 1]], 
                        f[i - 1][j - 1][1] + (1.0 - p[i]) * (1.0 - p[i - 1]) * (db)dis[c[i]][c[i - 1]] 
                            + (1.0 - p[i]) * p[i - 1] * (db)dis[c[i]][d[i - 1]]
                            + p[i] * (1.0 - p[i - 1]) * (db)dis[d[i]][c[i - 1]]
                            + p[i] * p[i - 1] * (db)dis[d[i]][d[i - 1]]);
                }
            }
        }
        double ans = 1e18;
        for (int j = 0; j <= m; j++) {
            for (int op = 0; op < 2; op++) {
                ans = min(ans, f[n][j][op]);
            }
        }
        cout << fixed << setprecision(2) << ans;
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }   
    
    #undef int
}
int main() {
    return Xbbbz::main(), 0;
}
/*
1 3
5 4 3
*/