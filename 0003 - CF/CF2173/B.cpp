#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int mod = 998244353;
const int inf = 1e18;
    void sol() {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (auto &x : a) cin >> x;
        for (auto &x : b) cin >> x;
 
        int mx = 0, mn = 0;
        for (int i = 0; i < n; ++i) {
            int mx2 = max(mx - a[i], b[i] - mn);
            int mn2 = min(mn - a[i], b[i] - mx);
            mx = mx2;
            mn = mn2;
        }
        cout << mx << '\n';
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
    return Xbbbz::main(), 0;
}
