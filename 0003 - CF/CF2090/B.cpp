#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
    void sol() {
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for (auto &i:  a) cin >> i;
        vector vis(n, vector(m, 0));
        for (int j = 0; j < m; j++) {
            if (a[0][j] == '1') {
                for (int i = 0; i < n; i++) {
                    if (a[i][j] == '1') vis[i][j] = 1;
                    else break;
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (a[i][0] == '1') {
                for (int j = 0; j < m; j++) {
                    if (a[i][j] == '1') vis[i][j] = 1;
                    else break;
                }
            }
        }
 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && a[i][j] == '1') {
                    cout << "NO\n";
                    return;
                }
            }
        }
        cout << "YES\n";
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
