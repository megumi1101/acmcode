#include <bits/stdc++.h>

#define int long long

using namespace std;

const int mod = 1e9 + 7;
void sol() {
    int n, k;
    cin >> n >> k;

    vector<int> L(n, 0), R(n);
    iota(R.begin(), R.end(), 0);
    vector<char> vis(n, 0);
    while (k--) {
        int len, x, y;
        string s;
        cin >> len >> x >> y;
        x--; y--;
        vis[x + y] = 1;
        len /= 2;
        
        if (len) cin >> s;

        for (int i = 0; i < len; i++) {
            if (s[i] == 'R') {
                y++;
                R[x + y] = min(R[x + y], y - 1);
            } else {
                x++;
                L[x + y] = max(L[x + y], y + 1);
            }
        }
    }
    int ans = 1;
    for (int i = 0; i < n; i++)
        if (!vis[i])
            ans = ans * (R[i] - L[i] + 1) % mod;
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}