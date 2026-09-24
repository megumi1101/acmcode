#include<bits/stdc++.h>

using namespace std;

#define int long long
const int mod = 998244353;
void sol() {
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;

    vector<int> p2(n + 5, 1), pre(n + 5), suf(n + 5);
    for (int i = 1; i <= n; i++) {
        p2[i] = p2[i - 1] * 2 % mod;
        pre[i] = (pre[i - 1] * 2 + s[i] - '0') % mod;
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = (suf[i + 1] + p2[n - i] * (s[i] - '0')) % mod;
    }
    int ans = 0;
    for (int i = n; i > 1; i--) {
        int ws = n + 1 - i;
        int tmp = pre[i - 1] * p2[ws - 1] % mod;
        if (s[i] == '0') tmp += suf[i + 1] + 1 - p2[ws - 1] + mod;
        ans += tmp * p2[ws - 1] % mod;
        ans %= mod;
    }
    cout << ans << "\n";
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
