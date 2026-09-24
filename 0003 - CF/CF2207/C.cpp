#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
void sol() {
    int n, h;
    cin >> n >> h;
 
    vector<int> a(n + 1), L(n + 1), R(n + 1);
    vector<int> stk;
    stk.reserve(n);
 
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[0] = h;
    for (int i = 1; i <= n; i++) {
        int lst = 0;
        while (!stk.empty() && a[stk.back()] < a[i]) {
            lst = stk.back();
            stk.pop_back();
        }
        
        if (!stk.empty()) {
            R[stk.back()] = i; 
        }
        L[i] = lst;   
        stk.push_back(i);
    }
 
    vector<int> f(n + 1),mxf(n + 1);
 
    int ans = 0;
    auto dfs = [&](auto &&dfs, int u, int fat, int l, int r) -> void {
        int wid = r - l + 1;
        int hei = a[fat] - a[u];
        f[u] = f[fat] + wid * hei;
 
        if (L[u]) dfs(dfs, L[u], u, l, u - 1);
        if (R[u]) dfs(dfs, R[u], u, u + 1, r);
 
 
        ans = max({ans, mxf[L[u]] + mxf[R[u]] - f[u], f[u]});
        mxf[u] = max({f[u], mxf[L[u]], mxf[R[u]]});
 
    };
 
    dfs(dfs, stk[0], 0, 1, n);
 
    cout << ans << '\n';
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
