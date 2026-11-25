#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define debug(x) cerr << #x << " == " << x << "\n";
void sol() {
    int n, d;
    cin >> n >> d;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    #define ls (u << 1)
    #define rs (u << 1 | 1)

    int tot = 2 * n;
    auto ed = vector(6 * n + 5, vector<int>{});
    vector<array<int, 2>> in(4 * n + 5), out(4 * n + 5);
    auto add = [&](int u, int v) { ed[u].push_back({v}); };
    auto build = [&](auto&& self, int u, int l, int r, int op) -> void {
        if (l == r) return void(in[u][op] = out[u][op] = l + op * n);
        in[u][op] = ++tot; out[u][op] = ++tot;
        int m = (l + r) >> 1;
        self(self, ls, l, m, op);
        self(self, rs, m + 1, r, op);
        add(out[u][op], out[ls][op]);
        add(out[u][op], out[rs][op]);
        add(in[ls][op], in[u][op]);
        add(in[rs][op], in[u][op]);
    };
    build(build, 1, 1, n, 0);
    build(build, 1, 1, n, 1);
    

    // x_0 -> out[L,R]_1, in[L, R]_1 -> x_0
    // x_1 -> out[L,R]_0, in[L, R]_0 -> x_1
    auto link = [&](int L, int R, int x) {
        if (L > R) return;
        auto dfs = [&](auto&& self, int u, int l, int r) -> void {
            if (L <= l && r <= R) {
                add(x, out[u][1]);
                add(in[u][1], x);
                add(x + n, out[u][0]);
                add(in[u][0], x + n);
                return;
            }
            int m = (l + r) >> 1;
            if (L <= m) self(self, ls, l, m);
            if (R > m) self(self, rs, m + 1, r);
        };
        dfs(dfs, 1, 1, n);
    };

    #undef ls
    #undef rs

    bool fg = 0;
    for (int i = 1; i <= n; i++) {
        int L = lower_bound(a.begin(), a.end(), min<int>((i64)a[i] + d, 2e9)) - a.begin();
        int R = lower_bound(a.begin(), a.end(), min<int>((i64)a[i] + 2 * d, 2e9)) - a.begin() - 1;
        // debug(L);
        // debug(R);
        if (L <= R) fg = 1;
        link(L, R, i);
    }

    if (!fg) {
        cout << "1\n";
        return;
    }
    
    auto scc = [&](const auto &ed) {
        int n = (int)ed.size() - 1, tim = 0, cnt = 0;
        vector<int> dfn(n + 1), low(n + 1), bel(n + 1), st;
        auto dfs = [&](auto&& self, int u) -> void {
            dfn[u] = low[u] = ++tim;
            st.push_back(u);
            for (int v : ed[u]) {
                if (!dfn[v]) {
                    self(self, v);
                    low[u] = min(low[u], low[v]);
                } else if (!bel[v]) {
                    low[u] = min(low[u], dfn[v]);
                }
            }
            if (low[u] != dfn[u]) return;
            ++cnt;
            while (true) {
                int v = st.back(); st.pop_back();
                bel[v] = cnt;
                if (v == u) break;
            }
        };
        for (int u = 1; u <= n; u++) if (!dfn[u]) dfs(dfs, u);
        return bel;
    };

    auto bel = scc(ed);
    for (int i = 1; i <= n; i++) {
        if (bel[i] == bel[i + n]) {
            cout << "3\n";
            return;
        }
    }

    cout << "2\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) sol();
    
}
/*
3
4 2
1 2 3 5
6 3
1 3 4 6 6 8
8 9
2 5 5 6 7 8 9 9
*/