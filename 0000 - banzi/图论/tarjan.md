### 强连通分量
```cpp
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

    int run() {
        for (int i = 1; i <= n; ++i) {
            if (!dfn[i]) dfs(i);
        }
        return comp_cnt;
    }

    // 返回每个强连通分量包含哪些点（comp_id 从 1..comp_cnt）
    vector<vector<int>> groups() {
        vector<vector<int>> res(comp_cnt + 1);
        for (int i = 1; i <= n; ++i) {
            res[comp[i]].push_back(i);
        }
        return res;
    }
};
```

### 边双
```cpp
struct DSU {
    vector<int> fa, sz;
    DSU(int n = 0) { init(n); }
    void init(int n) {
        fa.resize(n + 1);
        sz.assign(n + 1, 1);
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
    void unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        fa[y] = x;
        sz[x] += sz[y];
    }
};

struct EdgeBCC {
    int n;
    vector<pair<int,int>> edges;                  // 0-based 存所有边 (u,v)
    vector<vector<pair<int,int>>> g;             // g[u] : (v, edge_id)
    vector<int> dfn, low;
    vector<bool> is_bridge;
    int clk;

    // 结果：
    int comp_cnt;                                // 边双分量数
    vector<int> comp;                            // comp[u] ∈ [1..comp_cnt]
    vector<vector<int>> comp_vertices;           // 每个分量里的点
    vector<bool> in_edge_bcc;                    // 点 u 是否在“非平凡”边双分量中（size >= 2）

    EdgeBCC(int n_ = 0) { init(n_); }

    void init(int n_) {
        n = n_;
        g.assign(n + 1, {});
        edges.clear();
        dfn.assign(n + 1, 0);
        low.assign(n + 1, 0);
        clk = 0;
        comp_cnt = 0;
        comp.assign(n + 1, 0);
        in_edge_bcc.assign(n + 1, false);
    }

    // 返回边 id（0-based）
    int add_edge(int u, int v) {
        int id = (int)edges.size();
        edges.push_back({u, v});
        g[u].push_back({v, id});
        g[v].push_back({u, id});
        return id;
    }

    void dfs_bridge(int u, int in_edge) {
        dfn[u] = low[u] = ++clk;
        for (auto [v, id] : g[u]) {
            if (!dfn[v]) {
                dfs_bridge(v, id);
                low[u] = min(low[u], low[v]);
                if (low[v] > dfn[u]) {
                    is_bridge[id] = true; // 这条边是桥
                }
            } else if (id != in_edge) {
                // 回边 / 横叉边
                low[u] = min(low[u], dfn[v]);
            }
        }
    }

    void run() {
        int m = (int)edges.size();
        is_bridge.assign(m, false);

        // 1) Tarjan 找桥
        for (int i = 1; i <= n; ++i) {
            if (!dfn[i]) dfs_bridge(i, -1);
        }

        // 2) DSU 缩非桥边
        DSU dsu(n);
        for (int id = 0; id < m; ++id) {
            if (!is_bridge[id]) {
                int u = edges[id].first;
                int v = edges[id].second;
                dsu.unite(u, v);
            }
        }

        // 3) 压缩出 comp[u] ∈ [1..comp_cnt]
        unordered_map<int,int> mp;
        comp_cnt = 0;
        for (int u = 1; u <= n; ++u) {
            int fu = dsu.find(u);
            if (!mp.count(fu)) {
                mp[fu] = ++comp_cnt;
            }
            comp[u] = mp[fu];
        }

        comp_vertices.assign(comp_cnt + 1, {});
        for (int u = 1; u <= n; ++u) {
            comp_vertices[comp[u]].push_back(u);
        }

        // 4) 标记“属于边双连通块的点”
        //    一般认为 size >= 2 的分量才算“真正的”边双连通部分
        for (int c = 1; c <= comp_cnt; ++c) {
            if (comp_vertices[c].size() >= 2) {
                for (int u : comp_vertices[c]) {
                    in_edge_bcc[u] = true;
                }
            }
        }
    }

    //  // 3) 建桥树
    //     tree.assign(comp_cnt + 1, {});
    //     for (int id = 0; id < m; ++id) {
    //         if (!is_bridge[id]) continue;
    //         auto [u, v] = edges[id];
    //         int cu = comp[u], cv = comp[v];
    //         if (cu == cv) continue; // 理论上不会
    //         tree[cu].push_back(cv);
    //         tree[cv].push_back(cu);
    //     }
    //     // 最终 tree 是森林，每颗树就是原图一个连通块的“桥树”
};
```

### 点双
```cpp
struct VertexBCC {
    int n;
    vector<vector<int>> g;

    vector<int> dfn, low, parent;
    vector<bool> is_cut;
    int clk;

    vector<pair<int,int>> estack;      // 边栈 (u, v)
    vector<vector<int>> bcc;           // 每个点双分量的顶点集合
    vector<vector<int>> bcc_of;        // bcc_of[u] : u 属于哪些点双（下标是 bcc_id）

    VertexBCC(int n_ = 0) { init(n_); }

    void init(int n_) {
        n = n_;
        g.assign(n + 1, {});
        dfn.assign(n + 1, 0);
        low.assign(n + 1, 0);
        parent.assign(n + 1, -1);
        is_cut.assign(n + 1, false);
        clk = 0;
        estack.clear();
        bcc.clear();
        bcc_of.assign(n + 1, {});
    }

    void add_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    void dfs(int u) {
        dfn[u] = low[u] = ++clk;
        int child = 0;
        for (int v : g[u]) {
            if (!dfn[v]) {
                parent[v] = u;
                child++;
                estack.emplace_back(u, v);  // 树边入栈
                dfs(v);
                low[u] = min(low[u], low[v]);

                if (low[v] >= dfn[u]) {
                    // u 是割点（非根时）
                    if (parent[u] != -1) {
                        is_cut[u] = true;
                    }

                    // 以 (u, v) 为分界形成一个点双
                    vector<int> comp;
                    while (true) {
                        auto e2 = estack.back();
                        estack.pop_back();
                        comp.push_back(e2.first);
                        comp.push_back(e2.second);
                        if (e2.first == u && e2.second == v) break;
                    }
                    sort(comp.begin(), comp.end());
                    comp.erase(unique(comp.begin(), comp.end()), comp.end());
                    int id = (int)bcc.size();
                    bcc.push_back(comp);
                    // 记录每个点属于哪些点双
                    for (int x : comp) {
                        bcc_of[x].push_back(id);
                    }
                }

            } else if (v != parent[u] && dfn[v] < dfn[u]) {
                // 反向到祖先的回边，避免重复
                estack.emplace_back(u, v);
                low[u] = min(low[u], dfn[v]);
            }
        }
        // 根割点：至少两个子女
        if (parent[u] == -1 && child >= 2) {
            is_cut[u] = true;
        }
    }

    void run() {
        for (int i = 1; i <= n; ++i) {
            if (!dfn[i]) {
                parent[i] = -1;
                dfs(i);
                // 此时该连通块的边应全部弹空
            }
        }
    }


    // // 2) 建块点树
    //     int tot = n + bcc_cnt;            // 总节点数
    //     tree.assign(tot + 1, {});
    //     for (int id = 1; id <= bcc_cnt; ++id) {
    //         int block_node = n + id;      // 这个点双作为树上的一个“块节点”
    //         for (int v : bcc[id]) {
    //             tree[v].push_back(block_node);
    //             tree[block_node].push_back(v);
    //         }
    //     }
    //     // tree 是森林，每个连通块对应一棵块点树
};
```
