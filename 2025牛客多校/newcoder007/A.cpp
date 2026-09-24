#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
    void sol() {
        int id, m, K, n;
        cin >> id >> m >> K >> n;
        vector<int> d(m + 1), p(m + 1);
        for (int i =  1; i <= m; i++) p[i] = i;
        for (int i = 1; i <= m; i++) {
            int res1 = 0;
            int res2 = 0;
            for (int j = 1; j <= K; j++) {
                vector<vector<int>>  s(n + 1, vector<int> (n + 1));
                for (int a = 1; a <= n; a++) {
                    for (int b = 1; b <= n; b++) {
                        cin >> s[a][b];
                    }
                }
                for (int b = 1; b <= n; b++) {
                    res1 += s[1][b];
                    res2 += s[n][b];
                }
            }
            d[i] = res2 - res1;
        }
        sort(p.begin() + 1, p.end(), [&](int i, int j){return d[i] < d[j];});
        vector<int> vis(m + 1);
        for (int i = 1; i * 2 <= m; i++) {
            vis[p[i]] = 1;
        }
        for (int i = 1; i<= m; i++) {
            if (vis[i]) cout << 1;
            else cout << 0;
        }
    }
    
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        // cin >> T;
        while (T--) {
            sol();
        }
    }
#undef int
}

int main() {
    return Xbbbz::main(), 0;
}