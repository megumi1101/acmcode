#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 2);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    a[n] = a[0];
    a[n + 1] = a[1];
    
    const int inf = 1e18;
    auto get = [&] (int x, int y, int z) -> int {
        return max({x, y, z}) - min({x, y, z});
    };
    
    int ans = inf;
    for (int l = 0; l < 3; l++) {
        vector<int> dp(n + 1, inf);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            if (i + 2 <= n) dp[i + 2] = min(dp[i + 2], dp[i] + abs(a[l + i] - a[l + i + 1]));
            if (i + 3 <= n) dp[i + 3] = min(dp[i + 3], dp[i] + get(a[l + i], a[l + i + 1], a[l + i + 2]));
        }
        ans = min(ans, dp[n]);
    }
    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
 
    int T;
    cin >> T;
    while (T--) sol();
}
