#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
void sol() {
    int t, h, u;
    cin >> t >> h >> u;
    int ans = 0;
    if (t && u) {
        int tmp = min(t, u);
        t -= tmp;
        u -= tmp;
        ans += tmp * 4;
    }
    if (t && h) {
        int tmp = min(t / 2, h);
        t -= tmp * 2;
        h -= tmp;
        ans += tmp * 7;
 
        tmp = min(t, h);
        t -= tmp;
        h -= tmp;
        ans += tmp * 5;
    }
    if (t) {
        ans += 2 * t + 1;
    } 
    if (u || h) {
        ans += 3 * (u + h);
    }
    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t;
    cin >> t;
    while (t--) sol();
}
