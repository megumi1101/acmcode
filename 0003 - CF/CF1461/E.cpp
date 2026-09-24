#include <bits/stdc++.h>
 
using namespace std;
#define int long long
void sol() {
    int k, l, r, t, x, y;
    cin >> k >> l >> r >> t >> x >> y;
    k -= l;
    r -= l;
    int mx = 0;
    if (x >= y) {
        if (k + y <= r) k += y;
        if (k - x >= 0) {
            k -= x;
            if (x == y) {
                mx = t;
            } else {
                mx = 1 + k / (x - y);
            }
        }
    }
 
    else {
        vector<int> f(x, 0);
        while (1) {
            mx += k / x;
            k %= x;
            if (f[k]) {
                mx = t;
                break;
            }
            f[k] = 1;
            if (k + y <= r) {
                k += y;
            } else {
                break;
            }
        }
    }
    
 
    if (mx >= t) cout << "Yes\n";
    else cout << "No\n";
}
 
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int T = 1;
    // cin >> T;
 
    while (T--) sol();
}
