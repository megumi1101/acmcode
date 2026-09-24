#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    const int N = 2e5 + 10;
    const int inf = 1e18;
    void sol () {
        int n, m;
        cin >> n >> m;
        int a[n + 5], suma[n + 5];
        int b[m + 5], sumb[m + 5];
        int c[n + 5], d[m + 5];
        memset(suma, 0, sizeof(suma));
        memset(sumb, 0, sizeof(sumb));
        memset(c, 0x3f, sizeof(c));
        memset(d, 0x3f, sizeof(d));
        for (int i = 1; i <= n; i++) cin >> a[i], suma[i] = suma[i - 1] + a[i];
        for (int i = 1; i <= m; i++) cin >> b[i], sumb[i] = sumb[i - 1] + b[i];
        int x;
        cin >> x;
        for (int len = 1; len <= n; len++) {
            for(int i = 1; i + len - 1 <= n; i++) {
                int j = i + len - 1;
                c[len] = min(c[len], suma[j] - suma[i - 1]);
            }
        }
        for (int len = 1; len <= m; len++) {
            for(int i = 1; i + len - 1 <= m; i++) {
                int j = i + len - 1;
                d[len] = min(d[len], sumb[j] - sumb[i - 1]);
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                if (c[i] * d[j] <= x) ans = max (ans, i * j); 
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
