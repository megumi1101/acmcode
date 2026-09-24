#include <bits/stdc++.h>
 
using namespace std;
#define int long long
const int mod = 1e9 + 7;
void sol() {
    int n, k;
    cin >> n >> k;
    int siz = (1 << k);
 
    vector<int> a(n + 1);
    vector<int> b(k + 1);
    vector<vector<int>> ed(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        ed[u].push_back(v);
        ed[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= k; i++) cin >> b[i];
 
    map<int, int> toi;
    vector<int> toxor(siz);
    for (int i = 0; i < siz; i++) {
        int res = 0;
        for (int bit = 0; bit < k; bit++) {
            if ((i >> bit) & 1) res ^= b[bit + 1];
        }
        toi[res] = i;
        toxor[i] = res;
    }
 
    vector dp(n + 1, vector(siz, (int)0));
    vector<int> sum(n + 1);
    auto dfs = [&](auto &&dfs, int u, int fat) ->void {
        sum[u] = a[u];
        for (int v : ed[u]) {
            if (v == fat) continue;
            dfs(dfs, v, u);
            sum[u] ^= sum[v];
        }
        
        dp[u][0] = 1;
        for (int v : ed[u]) {
            if (v == fat) continue;
            int res = 0;
            for (int mv = 0; mv < (1 << k); mv++) {
                int val = sum[v] ^ toxor[mv];
                for (int j = 1; j <= k; j++) {
                    if (val == b[j]) {
                        res = (res + dp[v][mv]) % mod;
                        break;
                    }
                }
            }
 
            vector<int> ndp(siz);
            for (int mu = 0; mu < (1 << k); mu++) {
                if (dp[u][mu] == 0) continue;
 
                if (toi.count(sum[v])) {
                    int tu = mu ^ toi[sum[v]];
                    ndp[tu] = (ndp[tu] + dp[u][mu] * res) % mod;
                }
                for (int mv = 0; mv < (1 << k); mv++) {
                    ndp[mu ^ mv] = (ndp[mu ^ mv] + dp[u][mu] * dp[v][mv]) % mod;
                }
            }
            for (int i = 0; i < (1 << k); i++) dp[u][i] = ndp[i];
        }
    };
 
    dfs(dfs, 1, 0);
 
    int ans = 0;
    
    for (int i = 0; i < (1 << k); i++) {
        int t =sum[1] ^ toxor[i];
        for (int j = 1; j <= k; j++) {
            if (t == b[j]) {
                ans = (ans + dp[1][i]) % mod;
                break;
            }
        }
    }
    cout << ans << endl;
}
 
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
