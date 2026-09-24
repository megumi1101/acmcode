#include <bits/stdc++.h>
 
using namespace std;
 
namespace xbbbz{
    #define int long long
    const int inf = 1e18;
    int f[2][2005];
    void sol () {
        int n;
        cin >> n;
        memset(f, 0x3f, sizeof(f));
        f[0][0] = 0;
        int op = 0;
        for (int i = 1; i <= n; i++) {
            op ^= 1;
            int x;
            cin >> x;
            memset(f[op], 0x3f, sizeof(f[op]));
            for (int j = 0; j <= 2000; j++) {
                f[op][max(j - x, (int)0)] = min(f[op][max(j - x, (int)0)], f[op ^ 1][j] + x);
                if(j + x <= 2000)f[op][j + x] = min(f[op][j + x], max(f[op ^ 1][j] - x, (int)0));
            }
        }
        int ans = 1e18;
        for (int i = 0; i <= 2000; i++) {
            ans = min(ans, f[op][i] + i);
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
    return xbbbz::main(),0;
}
