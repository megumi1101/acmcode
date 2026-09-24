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
 
template <typename T>
struct Fenwick {
    int n;
    vector<T> a;
    
    Fenwick(int n_ = 0) {
        init(n_);
    }
    
    void init(int n_) {
        n = n_;
        a.assign(n + 5, T{});
    }
    
    void add(int x, const T &v) {
        for (int i = x; i <= n; i += i & -i) {
            a[i] = a[i] + v;
        }
    }
    
    T sum(int x) {
        T ans{};
        for (int i = x; i; i -= i & -i) {
            ans = ans + a[i];
        }
        return ans;
    }
    
    T getsum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    //查找满足前缀和 <= k 的最大位置
    int select(const T &k) {
        int x = 0;
        T cur{};
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i] <= k) {
                x += i;
                cur = cur + a[x];
            }
        }
        return x;
    }
};
 
void sol() {
    int n, m;
    cin >> n >> m;
 
    vector<int> mx(n + 1);
    for (int i = 1; i < n; i++) {
        mx[i] = i + 1;
    }
 
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        mx[u] = max(mx[u], v);
    }
 
 
    HLD hld(n);
    for (int i = 1; i < n; i++) {
        hld.addEdge(mx[i], i);
    }
    hld.work(n);
 
    long long ans = 0;
    Fenwick<int> f0(n);
    Fenwick<long long> f1(n);
 
    auto &ed = hld.ed;
    auto &in = hld.in;
    auto &out = hld.out;
    auto &seq = hld.seq;
    auto &dep = hld.dep;
 
    auto del = [&](int x) -> void {
        int d = dep[x];
        f0.add(d, -1);
        f1.add(d, -d);
    };
 
    auto add = [&](int x) -> void {
        int d = dep[x];
        f0.add(d, 1);
        f1.add(d, d);
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
                int y = seq[j];
                int d = dep[y];
                int cntx = f0.sum(d);
                long long sumx = f1.sum(d);
                ans += sumx - (long long)cntx * dep[u];
 
                int cnty = f0.sum(n) - f0.sum(d - 1);
                ans += (long long)cnty * (dep[y] - dep[u]);
            }
            for (int j = in[v]; j < out[v]; j++) {
                add(seq[j]);
            }
        }
 
        add(u);
        if (op == 0) {
            for (int j = in[u]; j < out[u]; j++) {
                del(seq[j]);
            }
        }
    };
    dfs(dfs, n, 0);
 
    cout << ans << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
