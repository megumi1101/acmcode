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
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ed[x].push_back(y);
        ed[y].push_back(x);
    }
 
    vector<long double> div(n + 1, 0);
    vector<int> divm(n + 1, 0);
    div[1] = 1;
    divm[1] = 1;
 
    auto dfs = [&](auto &&dfs, int u, int fat) -> void {
        for (auto v : ed[u]) if (v != fat) {
            dfs(dfs, v, u);
        }
 
        int mnpos = -1;
        long double mn = 1e18;
        for (auto v : ed[u]) if (v != fat) {
            if (div[v] < mn) {
                mn = div[v];
                mnpos = v;
            }
        }
        if (mnpos != -1) {
            div[u] = 1 / (2 - mn);
            divm[u] = fap((2 - divm[mnpos] + mod) % mod, mod - 2);
        }
    };
 
    dfs(dfs, 1, 0);
 
    vector<int> ans(n + 1);
    ans[1] = 1;
    auto dfs2 = [&](auto &&dfs2, int u, int fat) -> void {
        for (auto v : ed[u]) if (v != fat) {
            ans[v] = ans[u] * divm[v] % mod;
            dfs2(dfs2, v, u);
        }
    };
    dfs2(dfs2, 1, 0);
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
