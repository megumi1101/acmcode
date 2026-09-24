#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int inf = 1e18;
    void sol() {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 1) sum += a[i];
            else sum -= a[i];
        }
        if (n == 1) {
            cout << sum << "\n";
            return;
        }
        int x1 = 0;
        x1 = (n % 2 ? n - 1  : n - 2);
 
        vector<int> pref(n + 2, -inf), suf(n + 2, -inf);
        int cur = -inf;
        for (int i = 1; i <= n; i++) {
            if (i & 1) cur = max(cur, - i - 2 * a[i]);
            pref[i] = cur;
        }
        cur = -inf;
        for (int i = n; i >= 1; i--) {
            if (i & 1) cur = max(cur, i - 2 * a[i]);
            suf[i] = cur;
        }
        int res = -inf;
        for (int j = 2; j <= n; j+= 2) { 
            int t = max(j + pref[j], -j + suf[j]);
            res = max(res, 2 * a[j] + t);
        }
 
        int t = max(x1, res);
        int ans = sum + t;
        cout << ans << '\n';
        
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
# undef int
}
 
int main() {
    return Xbbbz :: main(), 0;
}
