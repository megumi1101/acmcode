#include <bits/stdc++.h>
 
using namespace std;
namespace Xbbbz {
#define int long long
const int inf = 1e9;
    void sol() {
        int n, k, q;
        cin >> n >> k >> q;
        vector<int> a(n + 1);
        while (q--) {
            int c, l, r;
            cin >> c >> l >> r;
            for (int i = l; i <= r; i++) {
                if (a[i] == c || a[i] == 3) continue;
                a[i] += c;
            }
        }
        vector<int> ans(n + 1);
        int now = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] <= 1) ans[i] = k;
            else if (a[i] == 2) {
                ans[i] = now;
                now = (now + 1) % k;
            } else {
                ans[i] = inf;
            }
        }
 
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
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
    return Xbbbz::main(),0;
}
