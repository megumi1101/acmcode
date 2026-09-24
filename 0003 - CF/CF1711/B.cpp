#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    constexpr int mod = 998244353;
    void sol() {
        int n, m;
        cin >> n >> m;
        vector<int> a(n + 5), b(m + 5), c(m + 5), in(n + 5);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= m; i++) {
            cin >> b[i] >> c[i];
            in[b[i]]++;
            in[c[i]]++;
        }
        int ans = 0;
        if (m & 1) ans = INT_MAX;
        for (int i = 1; i <= n; i++) {
            if (in[i] & 1) {
                ans = min (ans, a[i]);
            }
        }
        for (int i = 1; i <= m; i++) {
            ans = min (ans, a[b[i]] + a[c[i]]);
        }
        cout << ans << "\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        // init();
        int T = 1;
        cin >> T;
        while (T--) sol(); 
    }
#undef int
}
 
int main() {
    return Xbbbz ::main(), 0;
}
