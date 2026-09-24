#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> G(n + 2);
    G[n + 1] = n + 1;
    for (int i = n; i >= 1; i--) {
        if (i < n && a[i + 1] > a[i] + 1) {
            G[i] = i + 1;
        } else {
            G[i] = G[i + 1];
        }
    }
    vector<int> L(n + 2);
    stack<int> s;
    for (int i = n; i >= 1; i--) {
        while (!s.empty() && a[s.top()] > a[i]) {
            s.pop();
        }
        if (s.empty()) {
            L[i] = n + 1;
        } else {
            L[i] = s.top();
        }
        s.push(i);
    }
 
    vector<int> dp(n + 2, 0);
    int ans = 0;
    for (int i = n; i >= 1; i--) {
        int nxt = min(G[i], L[i]);
        dp[i] = n - i + 1 + dp[nxt];
        ans += dp[i];
    }
 
    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
