#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    const int N = 2e5 + 10;
    const int inf = 1e18;
    void sol () {
        int n;
        cin >> n;
        vector<int> a(n + 5, 0);
        vector<int> vis(n + 5, 0);
        vector<int> b(n + 5, 0);
        for (int i = 1; i <= n; i++) cin >> a[i], vis[a[i]]++;
        int ans = 0;
        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (vis[i]) ans++, i += 2;
        }
        cout << ans << " ";
        ans = 0;
        for (int i = 1; i <= n; i++) {
            if (vis[i] && !vis[i - 1] && !b[i - 1]) vis[i]--, b[i - 1]++;
            if (vis[i] && vis[i] + b[i] > 1) vis[i]--, b[i + 1]++; 
        }
        for (int i = 0; i <= n + 1; i++) {
            if (vis[i] || b[i]) ans++;
        }
        cout << ans;
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
