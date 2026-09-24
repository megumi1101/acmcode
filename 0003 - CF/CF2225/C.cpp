#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
void sol() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    s = " " + s;
    t = " " + t;
    vector f(n + 1, array<int, 2>{});
    f[0][1] = 1e18;
    for (int i = 1; i <= n; i++) {
        f[i][0] = min(f[i - 1][0] + (s[i] != t[i]), f[i - 1][1] + (s[i] != s[i - 1]) + (t[i] != t[i - 1]));
        f[i][1] = f[i - 1][0];
    }
    cout << f[n][0] << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
 
/*
6
0 0
3 0
6 0
6 3
6 6
1 1
*/
