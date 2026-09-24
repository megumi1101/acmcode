#include <bits/stdc++.h>
 
using namespace std;
 
void sol() {
    int n, q;
    cin >> n >> q;
    vector<int> L(n + 1), R(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> L[i] >> R[i];
    }
 
 
    vector<int> eu;
    vector fa(n + 1, array<int, 20>{});
    vector f(n + 1, array<int, 20>{});
 
    auto dfs = [&](auto &&self, int u, int fat) -> void {
        eu.push_back(u);
        if (L[u] && R[u]) f[u][0] = 3;
        else f[u][0] = 1;
        if (L[u]) {
            self(self, L[u], u);
            eu.push_back(u);
        }
        if (R[u]) {
            self(self, R[u], u);
            eu.push_back(u);
        }
        f[u][0] += f[L[u]][0] + f[R[u]][0];
        fa[u][0] = fat;
    };
 
    auto dfs2 = [&](auto &&self, int u) -> void {
        for (int i = 1; i < 20; i++) {
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
            if (fa[u][i]) f[u][i] = f[u][i - 1] + f[fa[u][i - 1]][i - 1];
            f[u][i] = min(f[u][i], (int)1e9 + 10);
        }
        if (L[u]) self(self, L[u]);
        if (R[u]) self(self, R[u]);
    };
    dfs(dfs, 1, 0);
    dfs2(dfs2, 1);
 
 
    vector pos(n + 1, 0);
    eu.push_back(0);
    for (int i = eu.size() - 1; i >= 0; i--)  {
        pos[eu[i]] = i;
    }
    while (q--) {
        int u, k;
        cin >> u >> k;
        for (int i = 19; i >= 0; i--) {
            if (fa[u][i] && f[u][i] <= k) {
                k -= f[u][i];
                u = fa[u][i];
            }
        }
        cout << eu[pos[u] + k] << " ";
    }
    cout << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
