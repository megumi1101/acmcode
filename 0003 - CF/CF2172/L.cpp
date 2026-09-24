#include <bits/stdc++.h>
 
using namespace std;
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    s = " " + s;
    const int inf = 1e9;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i] != s[i - 1]) a[i] = 1;
    }
 
    auto getans = [&]() -> int {
        vector<vector<pair<int, int>>> p(k + 1);
        for (int i = 1; i <= k; i++) {
            int siz = (n - i) / k;
            vector f(siz + 1, array<int, 2>{-inf, -inf});
            f[0][a[i]] = a[i];
            for (int j = 1; j * k + i <= n; j++) {
                vector nf(siz + 1, array<int, 2>{-inf, -inf});
                int now = j * k + i;
                for (int sl = 0; sl < f.size(); sl++) {
                    if (a[now] == 1) {
                        nf[sl][1] = max({nf[sl][1], f[sl][1] + 1, f[sl][0] + 1});
                        if (sl + 1 < f.size()) nf[sl + 1][0] = max({nf[sl + 1][0], f[sl][1] - 1, f[sl][0] + 1});
                    } else {
                        nf[sl][0] = max({nf[sl][0], f[sl][1], f[sl][0]});
                        if (sl + 1 < f.size()) nf[sl + 1][1] = max({nf[sl + 1][1], f[sl][1], f[sl][0] + 2});
                    }
                }
                f = move(nf);
            }
            int mx = 0;
            for (int j = 0; j <= siz; j++) {
                mx = max({f[j][0], f[j][1], mx});
                p[i].push_back({j, mx});
            }
        }
 
        vector<int> f(m + 1);
        for (int i = 1; i <= k; i++) {
            for (int j = m; j >= 0; j--) {
                for (auto[cost, val] : p[i]) {
                    if (j >= cost) {
                        f[j] = max(f[j], f[j - cost] + val);
                    }
                }
            }
        }
        return f[m];
    };
 
    int ans = 0;
    a[1] = 0;
    ans = max(ans, getans());
    a[1] = 1;
    ans = max(ans, getans());
 
    if (m >= 1) {
        a[n + 1 - k] ^= 1;
        m--;
        a[1] = 0;
        ans = max(ans, getans());
        a[1] = 1;
        ans = max(ans, getans());
    }
    
 
    cout << ans << "\n";
}
