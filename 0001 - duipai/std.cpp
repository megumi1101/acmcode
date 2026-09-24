#include<bits/stdc++.h>

using namespace std;

#define int long long
const int mod = 998244353, inv2 = 499122177, inv6 = 166374059;
void sol() {
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;

    vector<int> p2(2 * n + 5, 1), pre(n + 5), suf(n + 5);
    int sum = 0;
    for (int i = 1; i <= 2 * n; i++) {
        p2[i] = p2[i - 1] * 2 % mod;
        
    }
    for (int i = 1; i <= n; i++) {
        sum = sum * 2 + (s[i] - '0');
        sum %= mod;
    }
    sum = sum + 1 - p2[n - 1] + mod;
    sum %= mod;
    int ans = (p2[2 * n - 2] - (3 * p2[n - 1] % mod) + 2 + mod) % mod * inv6 % mod;
    ans += sum * ((p2[n] - 1 - sum + mod) % mod) % mod * inv2 % mod;
    ans %= mod;
    cout << ans << "\n";
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
