#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
const int mod = 998244353;
const int inf = 1e18;
    void sol() {
        int n, k;
        cin >> n >> k;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        vector f(k + 1, vector(k + 1, (int)0));
        int mx = 0;
        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] > mx) {
                res += a[i];
                res = min(res, k);
                for (int now = a[i]; now >= mx + 1; now--) {
                    for (int lst = 0; lst <= mx; lst++) {
                        for (int snow = res; snow >= now; snow--) {
                            f[now][snow] = max(f[now][snow], f[lst][snow - now] + (n + 1 - i) * (now - lst));
                        }
                    }
                }
            }
            
            mx = max(a[i], mx);
        }
        
        int ans = 0;
        for (int now = 0; now <= k; now++) 
            for (int snow = 0; snow <= k; snow++) 
                ans = max(ans, f[now][snow]);
        cout << ans << "\n";
        
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
}
int main() {
    return Xbbbz::main(), 0;
}
