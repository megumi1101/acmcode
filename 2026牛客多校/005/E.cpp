#include <bits/stdc++.h>

using namespace std;

#define int long long

vector<int> pr, g, vis;
void init(int n) {
    vis.assign(n + 1, 0);
    g.assign(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) {
            pr.push_back(i);
            g[i] = 1;
        }
        for (int j : pr) {
            int m = i * j;
            if (m > n) break;
            vis[m] = 1;
            g[m] = g[i] + g[j];
            if (i % j == 0) {
                break;
            }
        }
    }
}


const int mod = 998244353;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init(1e7);
    
    int n, c;
    cin >> n >> c;
    vector<int> pc(n + 1);
    pc[0] = 1;

    int ans = 0;
    g[1] = 1;
    for (int i = 1; i <= n; i++) {
        pc[i] = 1LL * pc[i - 1] * c % mod;
        if (g[i] == 1) {
            ans += 1LL * pc[i] % mod;
        }
        else ans += 1LL * pc[i] * pr[g[i] - 2] % mod;
        ans %= mod;
    }
    cout << ans << "\n";
}
