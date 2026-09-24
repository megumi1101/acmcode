#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    #define db double
    const int N = 1e5 + 10;
    const int mod = 1e9 + 7;
    bitset<N << 1> f, g;
   
    void sol() {
        int n;
        cin >> n;
        int a[n + 5];
        for (int i = 1; i <= n; i++) cin >> a[i];
        f[1] = 1;
        g.set();
        for (int i = 1; i <= n; i++) {
            f = ((g & f) << a[i]) | f;
            g[i] = 0;
        }
        int ans = 0;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += a[i];
            if (f[i])ans = max (ans, sum - i + 1);
        }
        for (int i = 1; i <= n; i++) {
            if (f[n + i]) {
                ans = max (ans, sum - n - i + 1);
            }
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
/*
1 3
5 4 3
*/
