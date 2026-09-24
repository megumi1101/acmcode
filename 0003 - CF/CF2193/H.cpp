#include <bits/stdc++.h>
 
using namespace std;
 
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i], a[i] = a[i] & 1;
    vector<vector<int>> ed(n + 1);
    vector<pair<int, int>> egs;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        egs.push_back({x, y});
        ed[x].push_back(y);
        ed[y].push_back(x);
    }
    vector<int> vis(n + 1);
    vector<vector<int>> cols;
    auto get = [&](auto &&get, int u, int fat) -> void {
        vis[u] = 1;
        cols.back().push_back(u);
        for (auto v : ed[u]) {
            if (v != fat && a[v] != 0) {
                get(get, v, u);
            }
        }
    };
    for (int i = 1; i <= n; i++) {
        if (vis[i] || a[i] == 0) continue;
        cols.emplace_back();
        get(get, i, 0);
    }
 
    vector<int> col(n + 1);
    for (int i = 1; i <= n; i++) if (a[i] == 0) col[i] = i;
    for (int i = 0; i < cols.size(); i++) {
        if (cols[i].size() % 2 == 0) {
            cout << "NO\n";
            return;
        }
        for (auto x : cols[i]) {
            col[x] = n + i + 1;
        }
    }
 
    vector<vector<int>> adj(2 * n + 1);
    for (auto[x, y] : egs) {
        if (col[x] != col[y]) {
            adj[col[x]].push_back(col[y]);
            adj[col[y]].push_back(col[x]);
        }
    }
    for (auto &v : adj) {
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
    }
    vector<int> ans;
    fill(vis.begin(), vis.end(), 0);
    for (int i = 1; i <= n; i++) {
        if (!a[i]) {
            int res = 0;
            for (auto x : adj[i]) {
                if (x > n) res++;
            }
            if (res & 1){
                vis[i] = 1;
                ans.push_back(i);
            } 
        }
    }
    
    vector<int> p1, p2;
    auto dfs = [&](auto &&dfs, int u, int fat, int co, int rt) ->void {
        vector<int> tmp;
        for (auto v : ed[u]) {
            if (v == fat || col[v] != co) continue;
            dfs(dfs, v, u, co, rt);
            if (!vis[v]) tmp.push_back(v);
        }
        if (u == rt || tmp.size() & 1) {
            p1.push_back(u);
            for (auto x : tmp) p1.push_back(x);
            vis[u] = 1;
        } else {
            for (auto x : tmp) p2.push_back(x);
        }
    };
 
    for (int i = 0; i < cols.size(); i++) {
        int ii = i + n + 1;
        vector<int> p;
        for (auto x : adj[ii]) {
            if (x <= n && !vis[x]) {
                vis[x] = 1;
                p.push_back(x);
            }
        }
        p1.clear();
        p2.clear();
        dfs(dfs, cols[i][0], 0, ii, cols[i][0]);
        for (auto x : p1) ans.push_back(x);
        reverse(p2.begin(), p2.end());
        for (auto x : p2) ans.push_back(x);
        for (auto x : p) ans.push_back(x);
    }
    if (ans.size() == n) {
        cout << "YES\n";
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    else cout << "NO\n";
}
 
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
