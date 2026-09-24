#include <bits/stdc++.h>
using namespace std;
#define int long long
 
void solve() {
    int x, y;
    cin >> x >> y;
    int min = 1e18, p, q;
    auto upd = [&](int _p, int _q) -> void {
        if ((_p & _q) == 0 && abs(_p - x) + abs(_q - y) < min) {
            min = abs(_p - x) + abs(_q - y);
            p = _p;
            q = _q;
        }  
    };
    upd(x, y);
    for (int i = 29; i >= 0; i--) {
        if ((x & y) >> i & 1) {
            upd((x >> i << i) + (1LL << i), y);
            upd(x, (y >> i << i) + (1LL << i));
            upd(x >> i << i, (y >> i << i) - 1);
            upd((x >> i << i) - 1, y >> i << i);
            break;
        }
        
    }
    cout << p << " " << q << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
