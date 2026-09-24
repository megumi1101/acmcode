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

    // [l, r) +v
    void rangeAdd(int l, int r, int v) {
        add(l, v);
        add(r, -v);
    }

    int query(int x) {
        int res = 0;
        for (; x; x -= x & -x)
            res += t[x];
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int V = 1000000;

    // SPF
    vector<int> spf(V + 1), primes;
    for (int i = 2; i <= V; i++) {
        if (!spf[i]) {
            spf[i] = i;
            primes.push_back(i);
        }

        for (int p : primes) {
            if (p > spf[i] || 1LL * i * p > V)
                break;
            spf[i * p] = p;
        }
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

    // 提前算好每次操作的 LCA，别对每个质因子重复算
    vector<int> lc(n + 1);
    for (int i = 2; i <= n; i++)
        lc[i] = hld.lca(u[i], v[i]);

    /*
        evt[p]:
        所有 a[i] 含 p 的 (i, v_p(a[i]))

        i 按 1..n 枚举，所以天然按照时间顺序。
    */
    vector<vector<pair<int, int>>> evt(V + 1);
    vector<int> usedPrime;

    for (int i = 1; i <= n; i++) {
        int x = a[i];

        while (x > 1) {
            int p = spf[x], cnt = 0;

            while (x % p == 0) {
                x /= p;
                cnt++;
            }

            if (evt[p].empty())
                usedPrime.push_back(p);

            evt[p].push_back({i, cnt});
        }
    }

    /*
        hld.out[root] 可能是 n+1，
        所以 BIT 开 n+1。
    */
    BIT bit(n + 1);

    vector<int> ans(n + 1, 1);

    for (int p : usedPrime) {
        vector<pair<int, int>> changed;

        for (auto [i, e] : evt[p]) {
            int rem;

            if (i == 1) {
                rem = e;
            } else {
                int w = lc[i];

                auto qry = [&](int x) {
                    if (!x) return 0;
                    return bit.query(hld.in[x]);
                };

                // 根 -> x 上 p 指数的总和
                int used =
                      qry(u[i])
                    + qry(v[i])
                    - qry(w)
                    - qry(hld.fa[w]);

                rem = max(0, e - used);
            }

            if (!rem) continue;

            for (int j = 0; j < rem; j++)
                ans[i] *= p;

            /*
                c[i] 中有 p^rem

                i 是 x 的祖先
                <=>
                x 在 subtree(i)

                所以让整个 subtree(i) +rem。
            */
            bit.rangeAdd(hld.in[i], hld.out[i], rem);

            changed.push_back({i, rem});
        }

        // 清空当前质因子的所有修改，给下一个质因子复用 BIT
        for (auto [i, rem] : changed)
            bit.rangeAdd(hld.in[i], hld.out[i], -rem);
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
}