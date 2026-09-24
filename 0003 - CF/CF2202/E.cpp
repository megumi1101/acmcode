#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int mod = 998244353;
void sol() {
    int n;
    string s;
    cin >> n >> s;
    s = " " + s;
    vector<int> p2(n + 1, 1);
    for (int i = 1; i <= n; i++) p2[i] = p2[i - 1] * 2 % mod;
    vector<int> pre(n + 1, 0);
    int ans = 0;
    vector<int> p;
    int res = 0;
    int lst = 1;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '(') {
            pre[i] = pre[i - 1] + 1;
            ans = (ans + p2[i - 1]) % mod;
            if (pre[i] == 1) {
                lst = i;
                p.push_back(res);
                res = 0;
            }
        }
        else {
            
            pre[i] = pre[i - 1] - 1;
            res = (res + p2[i - lst - 1]) % mod;
            if (pre[i] <= 1) {
                p.push_back(res);
                res = 0;
                lst = i;
            }
        }
        
    }
    res = 1;
    for (auto x : p) {
        res = res * (x + 1) % mod;
    }
    ans = (ans + res - 1 + mod) % mod;
    cout << ans << "\n";
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
