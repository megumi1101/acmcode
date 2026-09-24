#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    void sol() {
        int n; 
        cin >> n;
        int a[n + 5];
        int b[n + 5];
        int vis[n + 5];
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] %= 3;
            vis[a[i]]++;
        }
        int res = 0;
        memset(b, 0, sizeof(b));
        int cnt = 0;
        if (vis[0] >= n / 2) {
            cout << "2\n";
            for (int i = 1; i <= n; i++)
                if (a[i] == 0 && cnt < n / 2) b[i] = 1, cnt++;
        }
        else if (vis[1] + vis[2] >= n / 2) {
            cout << "0\n";
            for (int i = 1; i <= n; i++)
                if (a[i] != 0 && cnt < n / 2) b[i] = 1, cnt++;
        }
        for (int i = 1; i <= n; i++) {
            cout << b[i];
        }
    }
    void main () {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        // cin >> T;
        while(T--) sol();
    }
}
 
int main() {
    return Xbbbz::main(), 0;
}
