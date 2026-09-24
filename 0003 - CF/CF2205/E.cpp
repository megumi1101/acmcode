#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int mod = 998244353;
 
vector<int> get_pi(vector<int> &s) {
    int n = (int)s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}
 
void sol() {
    int n;
    cin >> n;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
 
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int lst = 0; lst < n; lst++) {
        if (dp[lst] == 0) continue;
        vector<int> b(a.begin() + lst, a.end());
        auto pi = get_pi(b);
 
        for (int i = 0; i < pi.size(); i++) {
            if (pi[i] == 0) {
                dp[i + lst + 1] = (dp[i + lst + 1] + dp[lst]) % mod;
            }
        }
    }
    cout << dp[n] << "\n";
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
