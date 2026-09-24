#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);

    int m, d;
    cin >> m >> d;
    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < m; i++) if (s[i] == '.') {
        bool fg = 1;
        for (int j = i - d; j <= i + d; j++) {
            if (j >= 0 && j < m) {
                if (s[j] == 'G') fg = 0;
            }
        }
        ans += fg;
    }
    cout << ans << "\n";
}