#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
const int mod = 998244353;
 
int fap(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod; b /= 2;
    }
    return res;
}
void sol() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (int t = 0; t < n; t++) {
        int cnt = 1;
        for (int j = 1; j < n; j++) {
            if (s[(j + t) % n] != s[(j + t - 1) % n]) cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
