#include <bits/stdc++.h>
 
using namespace std;
 
void sol() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    vector<int> f(n + 1);
    int cnt = 0;
    for (int i = 1; i <= n; i++) f[i] = s[i] - '0';
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    map<pair<int, int>, int> mp;
    vector<vector<int>> ed(n + 1);
    for (int i = 1; i <= n; i++) {
        if (mp[{i, a[i]}] | mp[{a[i], i}]) {
            continue;
        }
        ed[i].push_back(a[i]);
        ed[a[i]].push_back(i);
        mp[{i, a[i]}] = 1;
    }
 
    auto pb = [&](int u, int v, vector<int> &ve) {
        if (a[u] == v) ve.push_back(u);
        else ve.push_back(v);
    };
 
    vector<int> parent(n + 5, -1), vis(n + 5, 0);
    
 
    vector<int> vs(n + 1, 0);
    vector<int> ans;
    auto get = [&](int x) -> int {
        vector<int> loop;
        bool fg = 0;
        int cnt = 0;
        auto dfs = [&](auto&&dfs, int u, int p) -> void {
            parent[u] = p;
            for (int v : ed[u]) {
                if (fg) return;
                if (v == p) continue;  
                if (parent[v] != -1) { 
                    int x = u;
                    fg = 1;
                    while (x) {
                        vis[x] = 1;
                        loop.push_back(x);
                        if (x == v) break;
                        x = parent[x];
                    }
                    return;
                }
                dfs(dfs, v, u);
            }
        };
        dfs(dfs, x, 0);
        
 
        auto dfs2 = [&](auto&&dfs2, int u, int fat) -> void {
            vs[u] = 1;
            cnt += f[u];
            for (int v : ed[u]) {
                if (v == fat || vis[v]) continue;  
                dfs2(dfs2, v, u);
                if (f[v]) f[u] ^= 1, f[v] ^= 1, pb(u, v, ans);
            }
        };
        for (int u : loop) dfs2(dfs2, u, 0);
        if (!loop.size()) {dfs2(dfs2, x, 0);}
        if (cnt & 1) return -1;
        // for (auto i : ans) cerr << i << " ";
        // cerr << "\n";
        // for (auto i : f) cerr << i << " ";
        // cerr << "\n";
 
        int siz = loop.size();
        loop.resize(2 * siz);
        for (int i = 0; i < siz; i++) loop[siz + i] = loop[i];
        // for (auto i : loop) cerr << i << " ";
        // cerr << "\n";
 
        auto g = loop;
        for (auto &i : g) i = f[i];
        auto g2 = g;
 
        int st_ = -1, ed_;
        vector<int> t1, t2;
        for (int i = 0; i < siz; i++) if (g[i]) {
            st_ = i;
            ed_ = st_ + siz;
            break;
        }
        if (st_ == -1) return 1;
        // cerr << st_  << " " << ed_ << "\n";
        for (int i = st_; i < ed_; i++) {
            int x = loop[i], y = loop[i + 1];
            if (g[i]) {
                g[i] ^= 1;
                g[i + 1] ^= 1;
                pb(x, y, t1);
            }
        }
 
        g = g2;
        for (int i = ed_; i > st_; i--) {
            int x = loop[i], y = loop[i - 1];
            if (g[i]) {
                g[i] ^= 1;
                g[i - 1] ^= 1;
                pb(x, y, t2);
            }
        }
 
        if (t1.size() < t2.size()) for (auto i : t1) ans.push_back(i);
        else for (auto i : t2) ans.push_back(i);
        return 1;
    };
 
    for (int i = 1; i <= n; i++) {
        if (!vs[i]) {
            if (get(i) == -1) {
                cout << "-1\n";
                return;
            }
        }
    }
    
 
    cout << ans.size() << "\n";
    for (auto i : ans) cout << i << " ";
    cout << "\n";
}
 
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
