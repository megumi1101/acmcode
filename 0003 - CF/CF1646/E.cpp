#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
vector<vector<int>> g(25, vector<int>(25, 0));
    int gcd(int a, int b) {
        return b ?  gcd(b, a % b) : a;
    }
    void init() {
        for (int i = 1; i <= 20; i++) 
            for (int j = 1 ; j <= 20; j++) 
                g[i][j] = gcd(i, j);
    }
    void sol() {
        int n, m;
        cin >> n >> m;
        vector<int> f(21);
        vector<bool> vis(max(n, m) + 10);
        for (int mi = 1; mi <= 20; mi++) {
            fill(vis.begin(), vis.end(), 0);
            for (int b = 1; b < mi; b++) {
                int k = mi / g[mi][b];
                for (int i = k; i <= m; i += k) {
                    vis[b * i / mi] = 1;
                } 
            }
            f[mi] = f[mi - 1];
            for (int i = 1; i <= m; i++) {
                if (!vis[i]) f[mi]++;
            }
        }
        long long ans = 1;
        fill(vis.begin(), vis.end(), 0);
        for (int i = 2; i <= n; i++) {
            if (vis[i]) continue;
            int ct = 1;
            long long k = i;
            while (k * i <= n) {
                k *= i;
                vis[k] = 1;
                ct++;
            }
            ans += f[ct];
        }
        cout << ans << "\n";
    }
 
    void main() {
        ios::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
        int T = 1;
        init();
        // cin >> T;
        while (T--) sol();
    }
}
 
int main() {
    return Xbbbz::main(), 0;
}
