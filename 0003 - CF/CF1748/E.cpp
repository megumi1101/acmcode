#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
const int mod = 1e9 + 7;
void sol() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    vector<int> stk;
    stk.reserve(n);
    vector<int> lson(n + 1), rson(n + 1);
    for (int i = 1; i <= n; i++) {
        int lst = 0;
        while (!stk.empty() && a[stk.back()] < a[i]) {
            lst = stk.back();
            stk.pop_back();
        }
        if (!stk.empty()) {
            rson[stk.back()] = i;
        }
        lson[i] = lst;
        stk.push_back(i);
    }
 
    vector f(n + 1, vector(m + 1, (int)0));
    auto dfs = [&](auto &&dfs, int u) -> void {
        vector<int> tmp(m + 1, 1);
        tmp[0] = 0;
        if (lson[u]) dfs(dfs, lson[u]);
        if (rson[u]) dfs(dfs, rson[u]);
        if (lson[u]) {
            for (int i = 1; i <= m; i++) {
                tmp[i] *= f[lson[u]][i - 1];
                tmp[i] %= mod;
            }
        }
        if (rson[u]) {
            for (int i = 1; i <= m; i++) {
                tmp[i] *= f[rson[u]][i];
                tmp[i] %= mod;
            }
        }
        for (int i = 1; i <= m; i++) {
            f[u][i] = (tmp[i] + f[u][i - 1]) % mod;
        }
    };
    dfs(dfs, stk[0]);
    cout << f[stk[0]][m] << "\n";
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
    
}
