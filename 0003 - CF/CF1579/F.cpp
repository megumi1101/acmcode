#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    const int inf = 1e18;
    
    int gcd (int a, int b) {
        return b ? gcd(b, a % b) : a; 
    }
    void sol() {
        int n, d;
        cin >> n >> d;
        int a[n];
        int k = gcd(n, d);
        int b[k + 5][n / k * 2 + 10];
        memset(b, 0, sizeof(b));
        int cnt = n / k * 2;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 1; i <= k; i++) {
            int p = i - 1;
            for (int j = 1; j <= n / k; j++) {  
                b[i][j] = a[p];
                b[i][j + n / k] = b[i][j];
                p = (p + d) % n;
            }
        }
        int ans = 0;
        for (int i = 1; i <= k; i++) {
            int res = 0;
            for (int j = 1;j <= cnt; j++) {
                if (b[i][j] == 1 && b[i][j - 1] == 0) res = 1;
                if (b[i][j] == 1 && b[i][j - 1] == 1) res++;
                ans = max(res, ans);
            }
        }
        if (ans == cnt) cout << "-1\n";
        else cout << ans << "\n";
    }
 
    void main() {
        int T;
        cin>>T;
        while(T--) sol();
    }
    #undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
