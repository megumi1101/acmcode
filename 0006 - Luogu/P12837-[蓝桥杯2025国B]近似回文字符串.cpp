#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;

const int mod = 1e9 + 7;
const int inv2 = (mod + 1) / 2;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> p26(n + 5);
    p26[0] = 1;
    for (int i = 1; i <= n; i++) {
        p26[i] = p26[i - 1] * 26 % mod;
    }
    int t = n / 2;
    int ans = p26[t] * (26 * n - (n - 1)) % mod;
    ans -= p26[(n + 1) / 2];
    ans %= mod;
    if (ans < 0) ans += mod;
    if (n % 2 == 0) {
        for (int i = 1; i <= n / 2; i++) {
            ans -= p26[n / 2 - i] * 650 % mod;
            ans %= mod;
            if (ans < 0) ans += mod;
        }
    }
    cout << ans << "\n";
}
/*
1
7 2
7 1 3 2 2 4 3
1 2
2 3
2 4
2 5
5 6
5 7
*/