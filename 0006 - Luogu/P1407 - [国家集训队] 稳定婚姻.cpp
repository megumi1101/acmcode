#include <bits/stdc++.h>

using namespace std;

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

    void run(auto &siz) {
        for (int i = 1; i <= n; ++i) {
            if (!dfn[i]) dfs(i);
        }
        siz.assign(comp_cnt + 1, 0);
        for (int i =1 ; i <= n; i++) {
            siz[comp[i]]++;
        }
    }
};

void sol() {
    int n;
    cin >> n;
    map<string, int> mp;
    TarjanSCC itj(n);
    for (int i = 1; i <= n; i++) {
        string s, t;
        cin >> s >> t;
        mp[s] = i;
        mp[t] = i;
    }

    int m;
    cin >> m;
    vector<pair<int, int>> edgs(m);
    for (int i = 0; i < m; i++) {
        string s, t;
        cin >> s >> t;
        int u = mp[s];
        int v = mp[t];
        edgs[i] = {u, v};
        itj.add_edge(u, v);
    }
    
    vector<int> siz;
    itj.run(siz);
    int cnt = itj.comp_cnt;
    for (int t = 1; t <= n; t++) {
        if (siz[itj.comp[t]] > 1) {
            cout << "Unsafe\n";
        } else {
            cout << "Safe\n";
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) sol();
}