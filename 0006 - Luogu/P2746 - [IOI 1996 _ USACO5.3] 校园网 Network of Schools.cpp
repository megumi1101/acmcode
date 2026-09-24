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

    void run(auto &ed) {
        for (int i = 1; i <= n; ++i) {
            if (!dfn[i]) dfs(i);
        }
        ed.resize(comp_cnt + 1);
        for (int i = 1; i <= n; i++) {
            for (auto v : g[i]) {
                if (comp[i] != comp[v]) {
                    ed[comp[i]].push_back(comp[v]);
                }
            }
        }
    }
};

void sol() {
    int n;
    cin >> n;
    vector<vector<int>> ed;
    TarjanSCC tj(n);
    for (int i = 1; i <= n; i++) {
        int x;
        while (1) {
            cin >> x;
            if (x == 0) break;
            tj.add_edge(i, x);
        }
    }
    tj.run(ed);
    int cnt = tj.comp_cnt;
    vector<int> rd(cnt + 1);
    int t = 0;
    for (int i = 1; i <= cnt; i++) {
        if (!ed[i].size()) t++;
        for (auto v: ed[i]) rd[v]++;
    }
    
    queue<int> q;
    int ans = 0;
    for (int i = 1; i <= cnt; i++) {
        if (!rd[i]) ans++;
    }
    
    if (cnt == 1) {
        cout << "1\n0";
        return;
    }
    cout << ans << "\n";
    cout << max(ans, t) << "\n";


}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) sol();
}