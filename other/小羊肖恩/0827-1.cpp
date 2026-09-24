#include <bits/stdc++.h>

using namespace std;

#define int long long

void sol() {
    int n;
    cin >> n;
    vector<int> r(n + 1);
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++) cin >> r[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    
    int ans = 1e18;
    ans = min(ans, r[1] + c[n]);
    ans = min(ans, r[n] + c[1]);
    for (int i = 1; i <= n; i++) {
        ans = min(ans, r[1] + r[n] + c[i]);
        ans = min(ans, c[1] + c[n] + r[i]);
    }

    int sum = accumulate(r.begin(), r.end(), 0LL);
    ans = min(ans, sum);
    sum = accumulate(c.begin(), c.end(), 0LL);
    ans = min(ans, sum);

    cout << ans << "\n";
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
}