#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
const int inf = 1e18;
struct TarjanSCC {
    int n;
    vector<vector<int>> g;
    vector<int> dfn, low, comp, st;
    vector<bool> in_st;
    int clk, comp_cnt;
 
    TarjanSCC(int n_ = 0) { init(n_); }
 
    void init(int n_) {
        n = n_;
        g.assign(n + 1, {});
        dfn.assign(n + 1, 0);
        low.assign(n + 1, 0);
        comp.assign(n + 1, 0);
        in_st.assign(n + 1, false);
        st.clear();
        clk = comp_cnt = 0;
    }
 
    void add_edge(int u, int v) {
        g[u].push_back(v);
    }
 
    void dfs(int u) {
        dfn[u] = low[u] = ++clk;
        st.push_back(u);
        in_st[u] = true;
        for (int v : g[u]) {
            if (!dfn[v]) {
                dfs(v);
                low[u] = min(low[u], low[v]);
            } else if (in_st[v]) {
                low[u] = min(low[u], dfn[v]);
            }
        }
        if (dfn[u] == low[u]) {
            ++comp_cnt;
            while (true) {
                int x = st.back(); st.pop_back();
                in_st[x] = false;
                comp[x] = comp_cnt;
                if (x == u) break;
            }
        }
    }
 
    void run(auto &a, auto &b, auto &ed, auto &siz) {
        for (int i = 1; i <= n; ++i) {
            if (!dfn[i]) dfs(i);
        }
        ed.resize(comp_cnt + 1);
        b.assign(comp_cnt + 1, 0);
        siz.assign(comp_cnt + 1, 0);
        for (int i = 1; i <= n; i++) {
            b[comp[i]] += a[i];
            siz[comp[i]]++;
            for (auto v : g[i]) {
                if (comp[i] != comp[v]) {
                    ed[comp[i]].push_back(comp[v]);
                }
            }
        }
    }
};
 
void sol() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b, siz;
    vector<vector<int>> ed;
    for (int i = 1; i <= n; i++) cin >> a[i];
    TarjanSCC tj(n);
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        tj.add_edge(x, y);
    }
    tj.run(a, b, ed, siz);
    int cnt = tj.comp_cnt;
    vector<int> rd(cnt + 1);
    for (int i = 1; i <= cnt; i++) {
        for (auto v: ed[i]) rd[v]++;
    }
    
    queue<int> q;
    for (int i = 1; i <= cnt; i++) {
        if (!rd[i]) q.push(i);
    }
 
    vector<int> f(cnt + 1, 0), g(cnt + 1, inf);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (siz[u] > f[u]) {
            f[u] = siz[u];
            g[u] = b[u];
        } else if (siz[u] == f[u]) {
            g[u] = min(g[u], b[u]);
        }
 
        for (auto v : ed[u]) {
            rd[v]--;
            if (!rd[v]) q.push(v);
            if (f[u] + siz[v] > f[v]) {
                f[v] = f[u] + siz[v];
                g[v] = g[u] + b[v];
            } else if (f[u] + siz[v] == f[v]) {
                g[v] = min(g[v], g[u] + b[v]);
            }
        }
    }
 
    int t = -1, ans = inf;
    for (int i = 1; i <= cnt; i++) t = max(t, f[i]);
    for (int i = 1; i <= cnt; i++) {
        if (f[i] == t) ans = min(ans, g[i]);
    }
    cout << t << " " << ans << " \n";
 
}
 
signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) sol();
}
