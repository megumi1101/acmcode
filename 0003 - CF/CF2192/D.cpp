#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
const int mod = 998244353;
 
int fap(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod; b /= 2;
    }
    return res;
}
void sol() {
    int n;
    cin >> n;
    vector<vector<int>> ed(n + 1);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ed[x].push_back(y);
        ed[y].push_back(x);
    }
 
 
    vector<int> sum(n + 1, 0), cost(n + 1, 0), dep(n + 1, 0), mxdep(n + 1, 0), up(n + 1, 0), smxdep(n + 1, -1);
    auto dfs = [&](auto &&dfs, int u, int fat) -> void {
        dep[u] = dep[fat] + 1;
        mxdep[u] = dep[u];
        sum[u] = a[u];
        for (auto v : ed[u]) if (v != fat) {
            dfs(dfs, v, u);
            sum[u] += sum[v];
            cost[u] += cost[v] + sum[v];
            if (mxdep[v] >= mxdep[u]) {
                smxdep[u] = mxdep[u];
                mxdep[u] = mxdep[v];
            } else if (mxdep[v] >= smxdep[u]) {
                smxdep[u] = mxdep[v];
            }
            up[u] = max(up[u], up[v]);
        }
        
        for (auto v : ed[u]) if (v != fat) {
            if (mxdep[v] == mxdep[u]) {
                up[u] = max(sum[v] * (smxdep[u] - dep[u]), up[u]);
            } else {
                up[u] = max(sum[v] * (mxdep[u] - dep[u]), up[u]);
            }
        }
    };
    dfs(dfs, 1, 0);
    for (int i = 1; i <= n; i++) cout << cost[i] + up[i] << " ";
    cout << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
