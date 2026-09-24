#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
    #define int long long
    const int N = 2e5 + 10;
    const int mod = 1e9 + 7;
    bool vis[1005];
    int f[2][1005];
    int sum;
    void sol() {
        string s;
        string t;
        int k;
        cin >> s >> t >> k;
        int n = s.size();
        memset(vis, 0 ,sizeof(vis));
        if (s == t) vis[0] = 1;
        for (int i = 0; i < s.size() - 1; i++) {
            string res = s.substr(i + 1, s.size() - i - 1) + s.substr(0, i + 1);
            if (res == t) vis[i + 1] = 1;
        }
        for (int i = 1; i < n; i++) {
            f[1][i] = 1;
        }
        int op = 1;
        for (int i = 2; i <= k; i++) {
            op ^= 1;
            sum = 0;
            for (int j = 0; j < n; j++) {
                sum += f[op ^ 1][j];
                sum %= mod;
            }
            for (int j = 0; j < n; j++) {
                f[op][j] = (sum - f[op ^ 1][j]);
                ((f[op][j] %= mod) += mod) %= mod;
            }
        }
        if (vis[0] && k == 0) {
            cout << "1";
            return;
        }
        if (k == 0) {
            cout << "0";
            return;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i]) {
                ans += f[op][i];
                ans %= mod;
            }
        }
        cout << ans;
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        // cin >> T;
        while(T--) sol();
    }
    #undef int
} 

int main() {
    return Xbbbz :: main(), 0;
}
