#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int mod = 998244353;
void sol() {
    int n, m, d;
    cin >> n >> m >> d;
    int x = 1 + d / m;
    int ans = (n - 1) / x + 1;
    cout << ans << "\n";
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
