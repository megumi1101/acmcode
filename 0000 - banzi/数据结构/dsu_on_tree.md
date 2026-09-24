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