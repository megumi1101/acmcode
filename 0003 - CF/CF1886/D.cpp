#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
const int mod = 998244353;
int fap(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod; b >>= 1;
    }
    return res;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m;
    cin >> n >> m;
    n--;
    string s;
    cin >> s;
    int ans = 1;
    int mul = 1;
    if (s[0] == '?') mul = 0;
    for (int i = 1; i < n; i++) if (s[i] == '?') {ans *= i; ans %= mod;}
    cout << ans * mul << "\n";
    while (m--) {
        int x; string t;
        cin >> x >> t;
        x--;
        if (x == 0) {
            s[x] = t[0];
            mul = (s[0] != '?');
        } else {
            if (s[x] == '?') ans *= fap(x, mod - 2);
            ans %= mod;
            s[x] = t[0];
            if (s[x] == '?') ans *= x;
            ans %= mod;
        }
        cout << ans * mul << "\n";
    }
}
