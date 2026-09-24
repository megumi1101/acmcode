#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    const int N = 1e5 + 10;
    const int mod = 998244353;
    vector<int> tmp[2];
    int vis[N][2];
    void sol() {
        int n;
        cin >> n;
        int a[N];
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int v : tmp[0]) {
            vis[v][0] = 0;
        }
        for (int v : tmp[1]) {
            vis[v][1] = 0;
        }
        tmp[0].clear();
        tmp[1].clear();
        vis[a[n]][0] = 1;
        tmp[0].push_back(a[n]);
        bool op = 1;
        int ans = 0;
        for (int i = n - 1; i; i--) {
            op ^= 1;
            vis[a[i]][op ^ 1]++;
            tmp[op ^ 1].push_back(a[i]);
            for (int v : tmp[op]) {
                int t = (a[i] - 1) / v + 1;
                ans += vis[v][op] * (t - 1) % mod * i % mod;
                ans %= mod;
                int x = a[i] / t;
                // cout << i << "  i  \n";
                // cout << v << "  v  \n";
                // cout << t << "  t  \n";
                // cout << x << "  x  \n";
                // cout << ans << "  ans  \n";
                
                if (!vis[x][op ^ 1]) {
                    tmp[op ^ 1].push_back(x);
                }
                vis[x][op ^ 1] += vis[v][op];
                vis[v][op] = 0;
            }
            tmp[op].clear();
        }
        cout << ans << "\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T;
        cin >> T;
        while (T--) sol();
    }
    
    #undef int
}
int main() {
    return Xbbbz::main(), 0;
}
/*
1 3
5 4 3
*/
