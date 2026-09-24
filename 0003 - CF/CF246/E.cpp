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

    vector<string> s(n + 5);
    vector<string> all;
    HLD hld(n);
    for (int i = 1; i <= n; i++) {
        int fat;
        cin >> s[i] >> fat;
        all.push_back(s[i]);
        hld.addEdge(fat, i);
    }
    hld.work(0);

    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    vector<int> a(n + 5);
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(all.begin(), all.end(), s[i]) - all.begin() + 1;
    }
    
    int q;
    cin >> q;
    vector<vector<pair<int, int>>> p(n + 5);
    for (int i = 1; i <= q; i++) {
        int v, k;
        cin >> v >> k;
        p[v].push_back({k, i});
    }

    vector<int> cnt(n + 5);
    vector<map<int, int>> S(n + 5);

    auto &ed = hld.ed;
    auto &in = hld.in;
    auto &out = hld.out;
    auto &seq = hld.seq;
    auto &dep = hld.dep;

    auto del = [&](int x) -> void {
        int d = dep[x];
        int t = --S[d][a[x]];
        if (t == 0) cnt[d]--;
        
    };

    auto add = [&](int x) -> void {
        int d = dep[x];
        int t = ++S[d][a[x]];
        if (t == 1) cnt[d]++;
    };


    vector<int> ans(q + 1);
    auto dfs = [&](auto &&self, int u, int op) -> void {
        for (int i = 1; i < ed[u].size(); i++) {
            int v = ed[u][i];
            self(self, v, 0);
        }

        if (!ed[u].empty()) self(self, ed[u][0], 1);
        for (int i = 1; i < ed[u].size(); i++) {
            int v = ed[u][i];
            for (int j = in[v]; j < out[v]; j++) {
                add(seq[j]);
            }
        }

        add(u);
        for (auto [k, id] : p[u]) {
            if (dep[u] + k <= n + 1) ans[id] = cnt[dep[u] + k];
        }
        if (op == 0) {
            for (int j = in[u]; j < out[u]; j++) {
                del(seq[j]);
            }
        }
    };
    dfs(dfs, 0, 0);

    for (int i = 1; i <= q; i++) cout << ans[i] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) sol();
}
