#include <bits/stdc++.h>

using namespace std;

#define int long long

using i64 = long long;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int mask = (1 << m);
    vector d(n, vector<int>(m, 0LL));
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> d[i][j];
        }
        string t;
        cin >> t;
        for (int j = 0; j < m; j++) {
            if (t[j] == 'A') s[i] |= (1 << j);
        }
    }


    vector f(m, vector<int>(mask, 0LL));
    auto get = [&](auto &g, int b) -> void {
        for (int i = 0; i < n; i++) {
            g[(s[i] | (1 << b)) ^ (1 << b)] += d[i][b];
        }

        for (int bit = 0; bit < m; bit++) {
            for (int i = 0; i < mask; i++) {
                if (((i >> bit) & 1) == 0) {
                    g[i] += g[i | (1 << bit)];
                }
            }
        }
    };

    for (int i = 0; i < m; i++) get(f[i], i);


    vector<int> dp(mask, 1e18);
    dp[0] = 0;
    for (int i = 0; i < mask; i++) {
        for (int bit = 0; bit < m; bit++) {
            if ((i >> bit) & 1) continue;
            dp[i | (1 << bit)] = min(dp[i] + f[bit][i], dp[i | (1 << bit)]);
        }
    }
    cout << dp[mask - 1] << "\n";
}

/*
3 3
3 10 2 ARA
5 1 4 RAA
2 2 7 AAR
*/