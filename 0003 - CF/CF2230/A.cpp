#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
void sol() {
    int n, a, b;
    cin >> n >> a >> b;
    int ans = min({n * a, n / 3 * b + (n % 3) * a, ((n - 1) / 3 + 1) * b});
    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
