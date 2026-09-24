#include<bits/stdc++.h>

using namespace std;


struct HLD {
    int n;
    vector<int> siz, top, dep, fa, in, out, seq;
    vector<vector<int>> ed;
    int cur;
    
    HLD() {}
    HLD(int n) {
        init(n);
    }
    void init(int n) {
        this->n = n;
        siz.resize(n + 5);
        top.resize(n + 5);
        dep.resize(n + 5);
        fa.resize(n + 5);
        in.resize(n + 5);
        out.resize(n + 5);
        seq.resize(n + 5);
        cur = 1;
        ed.assign(n + 5, {});
    }
    void addEdge(int u, int v) {
        ed[u].push_back(v);
    }
    void work(int root = 1) {
        top[root] = root;
        dep[root] = 1;
        fa[root] = 0;
        dfs1(root);
        dfs2(root);
    }
    void dfs1(int u) {
        siz[u] = 1;
        for (auto &v : ed[u]) {
            fa[v] = u;
            dep[v] = dep[u] + 1;
            dfs1(v);
            siz[u] += siz[v];
            if (siz[v] > siz[ed[u][0]]) {
                swap(v, ed[u][0]);
            }
        }
    }
    void dfs2(int u) {
        in[u] = cur++;
        seq[in[u]] = u;
        for (auto v : ed[u]) {
            top[v] = v == ed[u][0] ? top[u] : v;
            dfs2(v);
        }
        out[u] = cur;
    }
};

void sol() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    HLD hld(n);
    int msk = (1 << 22);
    for (int i = 2; i <= n; i++) {
        int fat;
        string s;
        cin >> fat >> s;
        hld.addEdge(fat, i);
        a[i] = s[0] - 'a';
    }
    hld.work(1);

    vector<int> ans(n + 1), f(n + 1), mx(msk), t1(n + 1);
    auto &ed = hld.ed;
    auto &in = hld.in;
    auto &out = hld.out;
    auto &seq = hld.seq;
    auto &dep = hld.dep;

    auto del = [&](int x) -> void {
        mx[f[x]] = 0;
    };

    auto add = [&](int x) -> void {
        int d = dep[x];
        mx[f[x]] = max(mx[f[x]], d);
    };


    auto dfs = [&](auto &&self, int u, int op) -> void {
        if (u != 1) f[u] = f[hld.fa[u]] ^ (1 << a[u]);
        for (int i = 1; i < ed[u].size(); i++) {
            int v = ed[u][i];
            self(self, v, 0);
            ans[u] = max(ans[u], ans[v]);
        }

        if (!ed[u].empty()) { 
            self(self, ed[u][0], 1); 
            ans[u] = max(ans[u], ans[ed[u][0]]);
        }
        
        for (int bit = 0; bit <= 22; bit++) {
            int xo = f[u] ^ (1 << bit);
            if (bit == 22) xo = f[u];
            if (mx[xo] != 0) {
                ans[u] = max(ans[u], mx[xo] - dep[u]);
            }
        }

        add(u);

        for (int i = 1; i < ed[u].size(); i++) {
            int v = ed[u][i];
            for (int j = in[v]; j < out[v]; j++) {
                int now = seq[j];
                for (int bit = 0; bit <= 22; bit++) {
                    int xo = f[now] ^ (1 << bit);
                    if (bit == 22) xo = f[now];
                    if (mx[xo] != 0) {
                        ans[u] = max(ans[u], mx[xo] + dep[now] - 2 * dep[u]);
                    }
                }
            }
            
            for (int j = in[v]; j < out[v]; j++) {
                add(seq[j]);
            }
        }

        
        if (op == 0) {
            for (int j = in[u]; j < out[u]; j++) {
                del(seq[j]);
            }
        }
    };
    dfs(dfs, 1, 0);

    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) sol();
}
