#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int mod = 998244353;
 
bool check(int n, int s, int m) {
    int res = s;
    for (int i = 60; i >= 0; --i) {
        if ((m >> i) & 1) {
            int w = 1LL << i;
            int t = min(n, res / w);
            res -= t * w;
        }
    }
    return res == 0;
}
 
void sol() {
    int s, m;
    cin >> s >> m;
 
    int r = s / (m & -m);
    int l = 1;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid, s, m)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << "\n";
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
