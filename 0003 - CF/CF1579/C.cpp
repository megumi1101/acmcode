#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    int n, m, k;
    string s;
    bool bl[25][25];
    bool vis[25][25];
    bool pd (int i, int j) {
        if (i && j && i <= n && j <= m && bl[i][j]) return 1;
        return 0;
    }
    void sol() {
        cin >> n >> m >> k;
        memset(bl, 0, sizeof (bl));
        memset(vis, 0, sizeof (vis));
        for (int i = 1; i <= n; i++) {
            cin >> s;
            for (int j = 1; j <= m; j++) {
                if (s[j - 1] == '*') bl[i][j] = 1;
                else bl[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (!bl[i][j]) continue;
                for (int u = 1; u <= k; u++) {
                    if (pd(i - u, j - u) && pd(i - u, j + u));
                    else break;
                    if (u == k) {
                        vis[i][j] = 1;
                        int p = 1;
                        while (pd(i - p, j - p) && pd(i - p, j + p)) {
                            vis[i - p][j - p] = 1;
                            vis[i - p][j + p] = 1;
                            p++;
                        }
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (bl[i][j] && !vis[i][j]) {
                    cout << "NO\n";
                    return;
                }
            }
        }
        cout << "YES\n";
    }
 
    void main() {
        int T;
        cin>>T;
        while(T--) sol();
    }
}
 
int main() {
    return Xbbbz::main(), 0;
}
