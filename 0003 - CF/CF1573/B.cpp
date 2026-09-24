#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
 
    void sol() {
        int n;
        cin >> n;
        int a[n + 5];
        int b[n + 5];
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        for (int i = 2; i <= n; i++) {
            if (a[i - 1] < a[i]) a[i] = a[i - 1];
            if (b[i - 1] > b[i]) b[i] = b[i - 1];
        }
        int ans = 5 * n;
        for (int i = 1; i <= n; i++) {
            int x = lower_bound(b + 1, b + 1 + n, a[i]) - b;
            ans = min (ans, i + x - 2);
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
