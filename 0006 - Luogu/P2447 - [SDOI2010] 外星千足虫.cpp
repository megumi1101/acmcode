#include <bits/stdc++.h>
using namespace std;

namespace Xbbbz {
#define int long long
const int mod = 20100403;
    void sol() {
        int n, m;
        cin >> n >> m;
        vector<bitset<1005>> f(m + 5);
        for (int i = 1; i <= m; i++) {
            string s;
            cin >> s;
            for (int j = 1; j <= n; j++) {
                f[i][j] = s[j - 1] - '0';
            }
            int x;
            cin >> x;
            f[i][n + 1] = x;
        }
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            bool fg = 0;
            mx = max(mx, i);
            if (f[i][i] != 1) {
                for (int j = i + 1; j <= m; j++) {
                    if (f[j][i] == 1) {
                        swap(f[i], f[j]);
                        fg = 1;
                        mx = max(mx, j);
                        break;
                    }
                }
            } else {
                fg = 1;
            }
            if (!fg) {
                cout << "Cannot Determine\n";
                return;
            }
            for (int j = 1; j <= m; j++) {
                if (j != i) {
                    if (f[j][i] == 1) f[j] ^= f[i];
                }
            }
        }
        cout << mx << "\n";
        for (int i = 1; i <= n; i++) {
            if (f[i][n + 1] == 1) cout << "?y7M#\n";
            else cout << "Earth\n";
        }
    }

    void main() {
        ios::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
#undef int
}

int main() {
    return Xbbbz::main(), 0;
}
