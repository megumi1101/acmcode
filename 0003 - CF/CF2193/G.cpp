#include <bits/stdc++.h>
 
using namespace std;
 
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
 
    vector<int> fa(n + 1), a(n + 1);
    for (int i = 1; i <= n; i++) a[i] = i;
    bool fg = 0;
    auto ask = [&] (int u, int v) -> void {
        if (fg) return;
        cout << "? " << a[u] << " " << a[v] << endl;
        int x;
        cin >> x;
        if (x == 1) {
            fg = 1;
            cout << "? " << a[u] << " " << a[u] << endl;
            int y;
            cin >> y;
            if (y) {
                cout << "! " << a[u] << endl;
            } else {
                cout << "! " << a[v] << endl;
            }
        }
    };
 
    vector<int> vis(n + 1);
    auto dfs = [&](auto &&dfs, int u, int fat) -> void {
        fa[u] = fat;
        vector<int> p;
        for (auto v : ed[u]) {
            if (v == fat) continue;
            dfs(dfs, v, u);
            if(!vis[v]) p.push_back(v);
        }
        if (!p.empty()) {
            ask(u, p[0]);
            for (int i = 1; i + 1 < p.size(); i += 2) {
                ask(p[i], p[i + 1]);
            }
            if (p.size() %2 == 0) {
                a[u] = a[p.back()];
            } else {
                vis[u] = 1;
            }
        }
    };
    dfs(dfs, 1, 0);
    if (!fg) {
        cout << "! " << a[1] << endl;
    }
}
 
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
