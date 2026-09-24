#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
// #define int long long
const int inf = 2e9;
const int mod = 1e9 + 7;
int tun(int x) {
    return 64 - __builtin_clzll(x);
}
    vector<int> f(2e5 + 10);
    void init() {
        f[0] = 0;
        f[1] = 1;
        for (int i = 2; i < f.size(); i++) {
            f[i] = f[i - 1] + f[i - 2];
            f[i] %= mod;
        }
    }
    int ff(int x) {
        if (x < 3) return 0;
        else return f[x] - 1;
    }
    void sol() {
        int n, p;
        cin >> n >> p;
        vector<int> a(n + 1);
        set<int> s;
        for (int i = 1; i <= n; i++) cin >> a[i], s.insert(a[i]);
        
        auto dfs = [&](auto && dfs, int x, int rt) -> bool {
            if (!x) return 0;
            if (x != rt && s.count(x)) return 1;
            if (x & 1)  if (dfs(dfs, x >> 1, rt)) return 1;
            if (!(x & 3)) if (dfs(dfs, x >> 2, rt)) return 1;
            return 0;
        };
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dfs(dfs, a[i], a[i])) continue;
            ans += ff(p - tun(a[i]) + 3);
            ans %= mod;
        }
        cout << ans << "\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        init();
        // cin >> T;
        while (T--) sol();
    }
#undef int
}
 
int main() {
    return Xbbbz::main(),0;
}
