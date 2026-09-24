#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int inf = 1e18;
int lb(int x) {
    return x & -x;
}
 
void sol() {
    int l, r;
    cin >> l >> r;
    int ans = 0;
    if ((l ^ r) & 1) {
        ans = min(lb(l), lb(r - l + 1)) - 1;
        int len = r - l + 1;
        int i = 1;
        while (i < len) i <<= 1;
        int midup = (l + r + 1) / 2;
        for (; i < inf; i <<= 1) {
            int x = i / 2;
            if (midup - x < 0) {
                break;
            }
            if (lb(midup - x) >= i || midup - x == 0) {
                ans = lb(r - l + 1) - 1;
                break;
            }
        }
    }
    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) sol();
}
