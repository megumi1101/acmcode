#include <bits/stdc++.h>
 
using namespace std;
namespace Xbbbz {
#define int long long
const int mod = 998244353;
const int inf = 1e9;
    void sol() {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> segs(m);
        vector<int> mxl(n), mx(n), f(n), sumf(n);
        for (auto&[l, r] : segs) {cin >> l >> r;}
        for (auto&[l, r] : segs) {if (l == r) {cout << "0\n"; return;}}
        if (n == 1) {cout << "2\n"; return;}
        n--;
        for (auto[l, r] :segs) {
            r--;
            if (r) mxl[r] = max(mxl[r], l);
        }
        int cur = 0;
        for (int i = 1; i <= n; i++) {
            cur = max(cur, mxl[i]);
            mx[i] = cur;
        }
        
        f[0] = 1;
        sumf[0] = 1;
        for (int i = 1; i <= n; i++) {
            int t = mx[i] - 1; 
            int tmp = 0;
            if (t <= 0) {
                tmp = sumf[i - 1];
            } else {
                tmp = (sumf[i - 1] - sumf[t - 1]) % mod;
                if (tmp < 0) tmp += mod;
            }
            if (mx[i] == 0) {
                tmp = (tmp + 1) % mod;
            }
            f[i] = tmp;
            sumf[i] = (sumf[i-1] + f[i]) % mod;
        }
        int ans = (2 * f[n]) % mod;
        cout << ans << '\n';
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
