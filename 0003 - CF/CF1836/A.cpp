#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    void sol() {
        int n; 
        cin >> n;
        int vis[105];
        memset(vis, 0, sizeof(vis));
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            vis[x]++;
            mx = max(mx, x);
        }
        if (!vis[0]) {
            cout << "NO\n";
            return;
        }
        for (int i = 1; i <= mx; i++) {
            if (!vis[i] || vis[i] > vis[i - 1]) {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
    }
    void main () {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T;
        cin >> T;
        while(T--) sol();
    }
}
 
int main() {
    return Xbbbz::main(), 0;
}
