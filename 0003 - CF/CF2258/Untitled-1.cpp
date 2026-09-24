#include <bits/stdc++.h>
using namespace std;

struct HLD {
    int n, cur;
    vector<int> siz, top, dep, fa, in, out, seq;
    vector<vector<int>> ed;

    HLD() {}
    HLD(int n) { init(n); }

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
        if (fa[u] != 0)
            ed[u].erase(find(ed[u].begin(), ed[u].end(), fa[u]));

        siz[u] = 1;
        for (auto &v : ed[u]) {
            fa[v] = u;
            dep[v] = dep[u] + 1;
            dfs1(v);
            siz[u] += siz[v];
            if (siz[v] > siz[ed[u][0]])
                swap(v, ed[u][0]);
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
            if (dep[top[u]] > dep[top[v]])
                u = fa[top[u]];
            else
                v = fa[top[v]];
        }
        return dep[u] < dep[v] ? u : v;
    }
};

struct BIT {
    int n;
    vector<int> t;

    BIT(int n = 0) : n(n), t(n + 1) {}

    void add(int x, int v) {
        for (; x <= n; x += x & -x)
            t[x] += v;
    }

    int sum(int x) {
        int res = 0;
        for (; x; x -= x & -x)
            res += t[x];
        return res;
    }

    int query(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int V = 1000000;

    // 最小质因子
    vector<int> spf(V + 1);
    for (int i = 2; i <= V; i++) {
        if (spf[i]) continue;
        for (int j = i; j <= V; j += i)
            if (!spf[j]) spf[j] = i;
    }

    int n, c1;
    cin >> n >> c1;

    vector<int> a(n + 1), u(n + 1), v(n + 1);
    a[1] = c1;

    HLD hld(n);

    for (int i = 2; i <= n; i++) {
        cin >> a[i] >> u[i] >> v[i];
        hld.addEdge(i, v[i]);
    }

    hld.work();

    /*
        evt[p] = 所有 a[i] 中含 p 的 (i, 次数)
        i 是递增加入的，所以天然按操作时间排序。
    */
    vector<vector<pair<int, int>>> evt(V + 1);
    vector<int> primes;

    for (int i = 1; i <= n; i++) {
        int x = a[i];

        while (x > 1) {
            int p = spf[x], cnt = 0;

            while (x % p == 0) {
                x /= p;
                cnt++;
            }

            if (evt[p].empty())
                primes.push_back(p);

            evt[p].push_back({i, cnt});
        }
    }

    BIT bit(n);

    // 当前 BIT 只维护某一个质数 p
    auto queryPath = [&](int x, int y, int need) {
        int res = 0;

        while (hld.top[x] != hld.top[y]) {
            if (hld.dep[hld.top[x]] < hld.dep[hld.top[y]])
                swap(x, y);

            res += bit.query(hld.in[hld.top[x]], hld.in[x]);

            if (res >= need)
                return need;

            x = hld.fa[hld.top[x]];
        }

        if (hld.dep[x] > hld.dep[y])
            swap(x, y);

        res += bit.query(hld.in[x], hld.in[y]);

        return min(res, need);
    };

    vector<int> ans(n + 1, 1);

    // 每个质数独立处理
    for (int p : primes) {
        vector<pair<int, int>> changed;

        for (auto [i, e] : evt[p]) {
            int rem;

            if (i == 1) {
                rem = e;
            } else {
                int used = queryPath(u[i], v[i], e);
                rem = e - used;
            }

            if (!rem) continue;

            for (int j = 0; j < rem; j++)
                ans[i] *= p;

            // c[i] 中 p 的指数为 rem
            bit.add(hld.in[i], rem);
            changed.push_back({hld.in[i], rem});
        }

        // BIT 清空，复用给下一个质数
        for (auto [x, val] : changed)
            bit.add(x, -val);
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
}