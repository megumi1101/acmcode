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
        siz.resize(n + 1);
        top.resize(n + 1);
        dep.resize(n + 1);
        fa.resize(n + 1);
        in.resize(n + 1);
        out.resize(n + 1);
        seq.resize(n + 1);
        cur = 1;
        ed.assign(n + 1, {});
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

    HLD hld(n);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        int fat;
        cin >> a[i] >> fat;
        hld.addEdge(fat, i);
    }
    hld.work(1);
    
    int sum = 0;
    vector<int> cnt(n + 1, 0);
    vector<int> cntcol(n + 1, 0);

    auto &ed = hld.ed;
    auto &in = hld.in;
    auto &out = hld.out;
    auto &seq = hld.seq;

    auto del = [&](int x) -> void {
        cnt[a[x]]--;
        cntcol[cnt[a[x]]]++;
        cntcol[cnt[a[x]] + 1]--;
    };

    auto add = [&](int x) -> void {
        cnt[a[x]]++;
        cntcol[cnt[a[x]]]++;
        cntcol[cnt[a[x]] - 1]--;
    };

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
        if (cnt[a[u]] * cntcol[cnt[a[u]]] == out[u] - in[u]) sum++;
        if (op == 0) {
            for (int j = in[u]; j < out[u]; j++) {
                del(seq[j]);
            }
        }
    };
    dfs(dfs, 1, 0);

    cout << sum << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) sol();
}