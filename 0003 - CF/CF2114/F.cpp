#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int mod = 998244353;
const int inf = 1e18;
    void sol() {
        int x, y, k;
        cin >> x >> y >> k;
        int d = __gcd(x, y);
        x /= d;
        y /= d;
        
        int n = max(x, y);
        vector<int> f(n + 1, -1);
        auto dfs = [&](auto &&dfs, int u) ->int {
            if (f[u] != -1) return f[u];
            if (u == 1) return f[u] = 0;
            if (u <= k) return f[u] = 1;
            
            int res = inf;
            for (int i = 2; i * i <= u; i++) {
                if (u % i == 0) {
                    if (i <= k) res = min(res, dfs(dfs, u / i) + 1);
                    if (u / i <= k) res = min(res, dfs(dfs, i) + 1);
                }
            }
            return f[u] = res;
        };
 
        int ans = 0;
        ans += dfs(dfs, x);
        ans += dfs(dfs, y);
        if (ans >= inf) {
            cout << "-1\n";
        } else {
            cout << ans << '\n';
        }
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
    return Xbbbz::main(), 0;
}
