#include <bits/stdc++.h>
 
using namespace std;

#define int long long
const int inf = 1e18;
int lcm(int a, int b) {
    int d = gcd(a, b);
    __int128 c = (__int128)(a / d) * b;
    if (c >= inf) return inf;
    return (int)c;
}
void sol() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> ed(n + 1);
    vector<int> fa(n + 1), dis(n + 1);
    for (int i = 2; i <= n; i++) {
        cin >> fa[i];
        ed[fa[i]].push_back(i);
    }
    for (int i = 2; i <= n; i++) {
        cin >> dis[i];
        dis[i] += dis[fa[i]];
    }

    vector<int> ask(q), ids(q);
    vector<int> ans(q);
    for (auto &i : ask) cin >> i;
    iota(ids.begin(), ids.end(), 0);
    [&](this auto &&dfs, int u, vector<int> &ids, int mod) -> void {
        int deg = ed[u].size();
        if (deg == 0) {
            for (auto id : ids)
                ans[id] = u;
            return;
        }

        if (mod % deg == 0 || mod == inf) {
            dfs(ed[u][(dis[u] + ask[ids[0]]) % deg], ids, mod);
        } else {
            vector buc(deg, vector<int>{});
            for (auto id : ids) {
                int k = (ask[id] + dis[u]) % deg;
                buc[k].push_back(id);
            }
            int nmod = lcm(mod, deg);
            for (int k = 0; k < deg; k++) {
                if (!buc[k].empty()) {
                    dfs(ed[u][k], buc[k], nmod);
                }
            }
        }
    }(1, ids, 1);
    for (auto i : ans) cout << i << " ";
    cout << "\n";
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t;
    cin >> t;
    while (t--) sol();
}
