#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    const int mod = 998244353;
    void sol() {
        int n;
        cin >> n;
        int a[n + 1];
        int mx = 0, smx = -1;
        int res1 = 0, res2 = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] > mx) smx = mx, mx = a[i] ;
            if (a[i] > smx && a[i] != mx) smx = a[i];
        }
        for (int i = 1; i <= n; i++) {
            if (a[i] == mx) res1++;
            if (a[i] == smx) res2++;
        }
        int ans = 1;
        
        if (res1 >= 2) {
            for (int i = 1; i <= n; i++) {
                ans *= i;
                ans %= mod;
            }
        }
        else if (mx - smx >= 2) {
            ans = 0;
        }
        else {
            for (int i = 1; i <= n; i++) {
                if (i == res2 + 1)continue;
                ans *= i;
                ans %= mod;
            }
            ans *= res2;
            ans %= mod;
        }
        cout << ans << "\n";
    }
   
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T;
        cin >> T;
        while (T--) {
            sol();
        }
    }
 
    #undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
