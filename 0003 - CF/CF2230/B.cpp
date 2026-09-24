#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
void sol() {
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    vector<int> pre(n + 5), suf(n + 5);
 
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1];
        if (s[i] == '2') pre[i]++;
    }
 
    int ans = pre[n];
    for (int i = n; i >= 1; i--) {
        suf[i] = suf[i + 1];
        if (s[i] == '1' || s[i] == '3') suf[i]++;
        ans = max(suf[i] + pre[i - 1], ans);
    }
    cout << n - ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
