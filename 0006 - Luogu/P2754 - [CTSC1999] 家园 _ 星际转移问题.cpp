#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
struct DSU {
    vector<int> f, siz;

    DSU() {}
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        f.resize(n + 1);
        iota(f.begin(), f.end(), 0);
        siz.assign(n + 1, 1);
    }

    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    int size(int x) {
        return siz[find(x)];
    }
};
struct Dinic {
    struct Edge {
        int to, rev;          // 反向边在 g[to] 中的下标
        long long cap;        // 残量
        Edge(int _to, int _rev, long long _cap) : to(_to), rev(_rev), cap(_cap) {}
    };

    int n, s, t;              
    vector<vector<Edge>> g;   
    vector<int> dep, cur;     
    vector<pair<int,int>> forward_pos; // (u, idx_in_g[u]) 记录前向边位置，便于恢复流量

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        g.resize(n + 1);
        dep.resize(n + 1);
        cur.resize(n + 1);
    }
    
    void reset(int n_) {
        n = n_;
        g.resize(n + 1);
        dep.resize(n + 1);
        cur.resize(n + 1);
    }
    int add_edge(int u, int v, long long cap) {
        int iu = (int)g[u].size();
        int iv = (int)g[v].size();
        g[u].push_back(Edge(v, iv, cap));
        g[v].push_back(Edge(u, iu, 0));
        forward_pos.emplace_back(u, iu);
        return (int)forward_pos.size() - 1; // 该前向边的 id
    }

    // 无向边（两向各 cap）
    void add_undirected(int u, int v, long long cap) {
        add_edge(u, v, cap);
        add_edge(v, u, cap);
    }

    bool bfs() {
        fill(dep.begin(), dep.end(), -1);
        queue<int> q;
        dep[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto &e : g[u]) {
                if (e.cap > 0 && dep[e.to] == -1) {
                    dep[e.to] = dep[u] + 1;
                    q.push(e.to);
                    if (e.to == t) { /* 可选：不提前返回，稳定些 */ }
                }
            }
        }
        return dep[t] != -1;
    }

    long long dfs(int u, long long f) {
        if (u == t) return f;
        for (int &i = cur[u]; i < (int)g[u].size(); ++i) { // 当前弧优化
            Edge &e = g[u][i];
            if (e.cap > 0 && dep[e.to] == dep[u] + 1) {
                long long pushed = dfs(e.to, min(f, e.cap));
                if (pushed > 0) {
                    e.cap -= pushed;
                    g[e.to][e.rev].cap += pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }

    long long maxflow(long long INF = (1LL<<60)) {
        long long flow = 0;
        while (bfs()) {
            fill(cur.begin(), cur.end(), 0);
            while (long long pushed = dfs(s, INF)) flow += pushed;
        }
        return flow;
    }

    vector<char> mincut_side() const {
        vector<char> vis(n + 1, 0);
        queue<int> q;
        q.push(s); vis[s] = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto &e : g[u]) if (e.cap > 0 && !vis[e.to]) {
                vis[e.to] = 1;
                q.push(e.to);
            }
        }
        return vis;
    }

    // 恢复第 id 条“前向边”的最终流量（调用 maxflow() 之后）
    long long edge_flow(int id) const {
        auto [u, idx] = forward_pos[id];
        const Edge &fwd = g[u][idx];
        const Edge &rev = g[fwd.to][fwd.rev];
        // 反向边残量 = 该前向边的实际流量
        return rev.cap;
    }
};

constexpr int inf = 1e9;
    void sol() {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> h(m + 1), siz(m + 1);
        vector<vector<int>> S(m + 1);
        DSU dsu(n + 5);
        for (int i = 1; i <= m; i++) {
            cin >> h[i] >> siz[i];
            S[i].resize(siz[i]);
            for (auto &x : S[i]) {
                cin >> x;
                if (x == -1) x = n + 1;
            }
            for (int j = 0; j + 1 < siz[i]; j++) {
                dsu.merge(S[i][j], S[i][j + 1]);
            }
        }
        if (!dsu.same(0, n + 1)) {
            cout << "0\n";
            return;
        }


        vector<int> now(m + 1, 0);
        Dinic mf(n + 5, 0, 1);
        mf.add_edge(0, 2, inf);
        mf.add_edge(n + 3, 1, inf);
        int flow = 0;
        for (int days = 1; ; days++) {
            int earth = days * (n + 2) + 2;
            int moon = days * (n + 2) + n + 1 + 2;
            mf.reset(moon + 5);
            mf.add_edge(0, earth, inf);
            mf.add_edge(moon, 1, inf);
            for (int i = earth; i <= moon; i++) {
                mf.add_edge(i - n - 2, i, inf);
            }
            for (int i = 1; i <= m; i++) {
                int x = S[i][now[i]] + earth - n - 2;
                now[i] = (now[i] + 1) % siz[i];
                int y = S[i][now[i]] + earth;
                mf.add_edge(x, y, h[i]);
            }
            flow += mf.maxflow();
            if (flow >= k) {
                cout << days << "\n";
                return;
            }
        }
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) {
            sol();
        }
    }
}

int main() {
    return Xbbbz::main(), 0;
}