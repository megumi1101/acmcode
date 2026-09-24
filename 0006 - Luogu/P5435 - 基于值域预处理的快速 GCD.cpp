#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
    const int mod = 998244353;
    vector<int> pr, vis;
    vector<array<int, 3>> fac;
    vector<vector<int>> pre;
    void init() {
        int n = 1e6;
        vis.assign(n + 5, 0);
        fac.assign(n + 5, {0, 0, 0});
        for (int i = 2; i <= n; i++) {
            if (!vis[i]) {
                pr.push_back(i);
                fac[i][0] = fac[i][1] = 1;
                fac[i][2] = i;
            }
            for (int j : pr) {
                if (i * j > n) break;
                int m = i * j;
                vis[m] = 1;
                fac[m] = fac[i];
                fac[m][0] *= j;
                if (fac[m][0] > fac[m][1]) fac[m][0] ^= fac[m][1] ^= fac[m][0] ^= fac[m][1]; 
                if (fac[m][1] > fac[m][2]) fac[m][1] ^= fac[m][2] ^= fac[m][1] ^= fac[m][2];
                if (i % j == 0) break; 
            }
        }
        fac[1] = {1, 1, 1};
        int m = 1e3;
        pre.assign(m + 5, vector<int>(m + 5, 0));
        for (int i = 0; i <= m; i++) pre[i][0] = pre[0][i] = i;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= i; j++) {
                pre[i][j] = pre[j][i] = pre[j][i % j];
            }
        }
    }

    int gcd(int a, int b) {
        int ans = 1;
        for (int i = 0; i < 3; i++) {
            int x = fac[a][i], tmp = 1;
            if (vis[x]) tmp = pre[x][b % x];
            else if (b % x == 0) tmp = x;
            ans *= tmp;
            b /= tmp;
        }
        return ans;
    }

    void sol() {
        int n;
        cin >> n;
        vector<int> a(n + 1), b(n + 1);
        vector<long long> ans(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];
        for (int i = 1; i <= n; i++) {
            long long res = 1;
            for (int j = 1; j <= n; j++) {
                (res *= i) %= mod;
                ans[i] += res * gcd(a[i], b[j]) % mod;
                ans[i] %= mod;
            }
        }
        for (int i = 1; i <= n; i++) cout << ans[i] << "\n";
    }

    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        init();
        // cin >> T;
        while (T--) sol();

    }
}

int main() {
    return Xbbbz::main(), 0;
}