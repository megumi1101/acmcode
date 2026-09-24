#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int mod = 1e9 + 7;
void sol() {
    int n, c;
    cin >> n >> c;
    string s;
    cin >> s;
    int ans = 1;
    int res = 1;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '1') ans = ans * 2 % mod;
        else ans = ans * i % mod;
 
        if (s[i] == '1') res = res * 2 % c;
        else res = res * i % c;
    }
    if (s[0] == '0' || s[n - 1] == '0' || res == 0) ans = -1;
    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
 
    int T;
    cin >> T;
    while (T--) sol();
}
