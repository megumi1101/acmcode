#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
const int inf = 1e18;
void sol() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n <= 2) {
        cout << "1\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') break;
        if (i == n - 1) {
            cout << (n - 1) / 3 + 1 << "\n";
            return;
        }
    }
    int cnt = 0;
    int ans = 0;
    bool fg = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') cnt++;
        else {
            if (!fg) ans += (cnt + 1) / 3 + 1;
            else ans += cnt / 3 + 1;
            fg = 1;
            cnt = 0;
        }
    }
    if (cnt > 0) ans += (cnt + 1) / 3;
    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int T;
    cin >> T;
    while (T--) sol();
}
