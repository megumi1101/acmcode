#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
const int inf = 1e9;
    void sol() {
        int n, m;
        cin >> n >> m;
        vector<string> s(n);
        for (auto &x : s) cin >> x;
        bool swaped = 0;
        if (m > n) swap(n, m), swaped = 1;
        vector a(n, vector(m, 0));
        vector ans(n, vector(m, inf));
        if (swaped) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    a[i][j] = s[j][i] - '0';
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    a[i][j] = s[i][j] - '0';
                }
            }
        }
 
        for (int len = 2; len <= m; len++) {
            vector<deque<pair<int, int>>> q(n);
            
            for (int l = 0; l < m; l++) {
                int lst = -1;
                int r = l + len - 1;
                if (r < m) {
                    for (int i = 0; i < n; i++) {
                        if (a[i][l] == 1 && a[i][r] == 1) {
                            if (lst == -1) {
                                lst = i;
                                continue;
                            }
 
                            int siz = i - lst + 1;
                            for (int j = lst; j <= i; j++) {
                                while (!q[j].empty() && q[j].back().second >= siz) q[j].pop_back();
                                q[j].emplace_back(r, siz);
                            }
                            lst = i;
                        }
                    }
                }
 
 
                for (int i = 0; i < n; i++) {
                    while (!q[i].empty() && q[i].front().first < l) q[i].pop_front();
                    if (!q[i].empty()) ans[i][l] = min(ans[i][l], q[i].front().second * len);
                }
            }
        }
 
        if (!swaped) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m ;j++) {
                    if (ans[i][j] == inf) ans[i][j] = 0;
                    cout << ans[i][j] << " ";
                }
                cout << "\n";
            }
        } else {
            for (int j = 0; j < m; j++) {
                for (int i = 0; i < n; i++) {
                    if (ans[i][j] == inf) ans[i][j] = 0;
                    cout << ans[i][j] << " ";
                }
                cout << "\n";
            }
        }
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
}
int main() {
    return Xbbbz::main(),0;
}
