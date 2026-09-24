#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
 
    const int N = 2e5 + 10;
    const int inf = 1e18;
    void sol () {
        int n; 
        cin >> n;
        vector <int> a(n + 1);
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        sort(a.begin() + 1, a.begin() + 1 + n);
        int m;
        cin >> m;
        while (m--) {
            int x, y;
            cin >> x >> y;
            auto p = lower_bound(a.begin() + 1, a.begin() + 1 + n, x);
            if (p != a.end()) {
                if (sum - *p >= y) {
                    cout << "0\n";
                }
                else {
                    int ans = y - (sum - *p);
                    if (p != a.begin() + 1) p--, ans = min(ans, (x - *p) + max((int)0, y - sum + *p));
                    cout << ans << "\n";
                }
            }
            else {
                sum -= a[n];
                cout << x - a[n] + max(y - sum, (int)0) << "\n";
                sum += a[n];
            } 
        }
    }
    void main() {
        int T = 1;
        // cin >> T;
        while (T--) {
            sol();
        }
    }
 
    #undef int 
}
 
int main() {
    return Xbbbz::main(), 0;
}
