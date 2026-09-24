#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
void sol() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    int last = ranges::max(a);
    ranges::sort(a);
    n--;
 
    auto check = [&](int x) -> bool {
        vector<pair<int, int>> dp(1 << n);
        for (int sta = 0; sta < (1 << n); sta++) {
            for (int bit = 0; bit < n; bit++) {
                if ((sta >> bit) & 1) {
                    int pre = sta ^ (1 << bit);
                    auto cur = dp[pre];
 
                    cur.second += a[bit];
                    if (cur.second >= x) {
                        cur.first++;
                        cur.second = 0;
                    }
                    dp[sta] = max(dp[sta], cur);
                }
            }
        }
        return dp[(1 << n) - 1].first >= k;
    };
 
    int l = 0, r = 2e10;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans + last << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
