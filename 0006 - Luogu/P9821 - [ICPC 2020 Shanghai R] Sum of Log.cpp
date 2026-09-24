#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
    #define int long long
    #define db double
    const int N = 105;
    const int mod = 1e9 + 7;
    int f[40][2][2];
    int x, y;
    int dfs(int len, int lim1, int lim2) {
        if (len < 0) return 1;
        if (f[len][lim1][lim2] != -1) return f[len][lim1][lim2];
        int up1 = 1, up2 = 1;
        int res = 0;
        if (lim1) up1 = (x >> len) & 1;
        if (lim2) up2 = (y >> len) & 1;
        for (int i = 0; i <= up1; i++) {
            for (int j = 0; j <= up2; j++) {
                if (i & j) continue;
                res += dfs(len - 1, lim1 & (i == up1), lim2 & (j == up2));
                res %= mod;
            }
        }
        return f[len][lim1][lim2] = res;
    }
    void sol() {
        cin >> x >> y;
        int ans = 0;
        memset(f, -1, sizeof(f));
        for (int k = 0; k <= 30; k++) {
            if (x >= (1 << k)) ans += dfs(k - 1, (x - (1 << k)) < (1 << k), y < (1 << k)) * (k + 1);
            if (y >= (1 << k)) ans += dfs(k - 1, x < (1 << k), (y - (1 << k)) < (1 << k)) * (k + 1);
            ans %= mod;
        }
        cout << ans << "\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }   
    
    #undef int
}
int main() {
    return Xbbbz::main(), 0;
}
/*
1 3
5 4 3
*/