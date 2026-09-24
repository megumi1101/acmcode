```cpp
DSU dsu(2 * n);
int cnt = n;
for (auto i : edge) {
    int u = i.u;
    int v = i.v;
    int w = i.w;
    if (dsu.same(u, v)) continue;
    cnt++;
    int fu = dsu.find(u);
    int fv = dsu.find(v);
    ed[cnt].push_back(fu);
    ed[cnt].push_back(fv);
    dsu.merge(cnt, fu);
    dsu.merge(cnt, fv);
    fa[fu][0] = cnt;
    fa[fv][0] = cnt;
    a[cnt] = w;
}
auto dfs = [&](auto &&dfs, int u) -> void {
    for (auto v : ed[u]) {
        dfs(dfs, v);
        sum[u] += sum[v];
    }
};
dfs(dfs, cnt);
auto dfs2 = [&] (auto &&dfs2, int u) -> void {
    mx[u][0] = a[fa[u][0]] - sum[u];
    for (int i = 1; i < 20; i++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
        mx[u][i] = max(mx[u][i - 1], mx[fa[u][i - 1]][i - 1]);
    }
    for (auto v: ed[u]) {
        dfs2(dfs2, v);
    }
};
dfs2(dfs2, cnt);

auto cx = [&](int x, int k) -> int {
    for (int i = 19; i >= 0; i--) {
        if (fa[x][i] && mx[x][i] <= k) {
            x = fa[x][i];
        }
    }
    return sum[x];
};
```


