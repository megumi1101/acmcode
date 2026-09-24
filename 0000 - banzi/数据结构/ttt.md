```cpp
//**   树链剖分（HLD）
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
        ed[v].push_back(u);
    }
    void work(int root = 1) {
        top[root] = root;
        dep[root] = 1;
        fa[root] = 0;
        dfs1(root);
        dfs2(root);
    }
    void dfs1(int u) {
        // 只加单向边要去掉这三行
        if (fa[u] != 0) {
            ed[u].erase(find(ed[u].begin(), ed[u].end(), fa[u]));
        }
        
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
    int lca(int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                u = fa[top[u]];
            } else {
                v = fa[top[v]];
            }
        }
        return dep[u] < dep[v] ? u : v;
    }
    
    int dist(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }
    
    int jump(int u, int k) {
        if (k < 0 || dep[u] <= k) return -1;
        if (k == 0) return u;
        
        int d = dep[u] - k;
        
        while (dep[top[u]] > d) {
            u = fa[top[u]];
        }
        
        return seq[in[u] - dep[u] + d];
    }
    
    bool isAncester(int u, int v) {
        return in[u] <= in[v] && in[v] < out[u];
    }
    
    int rootedParent(int u, int v) { // 新根, 询问点
        swap(u, v);
        if (u == v) {
            return u;
        }
        if (!isAncester(u, v)) {
            return fa[u];
        }
        auto it = upper_bound(ed[u].begin(), ed[u].end(), v, [&](int x, int y) {
            return in[x] < in[y];
        }) - 1;
        return *it;
    }
    
    int rootedSize(int u, int v) { // 新根, 询问点
        if (u == v) {
            return n;
        }
        if (!isAncester(v, u)) {
            return siz[v];
        }
        return n - siz[rootedParent(u, v)];
    }
    
    int rootedLca(int a, int b, int c) {
        return lca(a, b) ^ lca(b, c) ^ lca(c, a);
    }



    // 路径加法
    void add_path(int x, int y, int k) {
        while (top[x] != top[y]) {
            if (dep[top[x]] < dep[top[y]]) swap(x, y);
            seg.modify(in[top[x]], in[x], k);
            x = fa[top[x]];
        }
        if (dep[x] > dep[y]) swap(x, y);
        seg.modify(in[x], in[y], k);
    }

    // 路径查询
    int query_path(int x, int y) {
        int res = 0;
        while (top[x] != top[y]) {
            if (dep[top[x]] < dep[top[y]]) swap(x, y);
            res += seg.query(in[top[x]], in[x]).sum;
            res %= Mod;
            x = fa[top[x]];
        }
        if (dep[x] > dep[y]) swap(x, y);
        res += seg.query(in[x], in[y]).sum;
        res %= Mod;
        return res;
    }

    // 子树加法
    void add_subtree(int u, int k) {
        seg.modify(in[u], out[u] - 1, k);
    }

    // 子树查询
    int query_subtree(int u) {
        return seg.query(in[u], out[u] - 1).sum % Mod;
    }
};
```


```cpp
    HLD hld(n);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        hld.addEdge(x, y);
    }
    hld.work(1);

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int sum = 0;
    vector<int> cnt(n + 1, 0);
    vector<int> ans(n + 1, 0);

    auto &ed = hld.ed;
    auto &in = hld.in;
    auto &out = hld.out;
    auto &seq = hld.seq;

    auto del = [&](int x) -> void {
        cnt[a[x]]--;
        if (cnt[a[x]] == 0) sum--;
    };

    auto add = [&](int x) -> void {
        cnt[a[x]]++;
        if (cnt[a[x]] == 1) sum++;
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
        ans[u] = sum;
        if (op == 0) {
            for (int j = in[u]; j < out[u]; j++) {
                del(seq[j]);
            }
        }
    };
    dfs(dfs, 1, 1);
```