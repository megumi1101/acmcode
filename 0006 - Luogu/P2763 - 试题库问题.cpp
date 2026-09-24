#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
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
        g.assign(n + 1, {});
        dep.assign(n + 1, 0);
        cur.assign(n + 1, 0);
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


    void sol() {
        int k, n;
        cin >> k >> n;
        vector<pair<int, int>> edgs;
        Dinic mf(n + k + 5, 0, 1);
        int sum = 0;
        for (int i = 2; i <= k + 1; i++) {
            int x;
            cin >> x;
            edgs.emplace_back(0, i);
            mf.add_edge(0, i, x);
            sum += x;
        }
        for (int i = k + 2; i <= k + 1 + n; i++) {
            int siz;
            cin >> siz;
            for (int j = 0; j < siz; j++) {
                int x;
                cin >> x;
                edgs.emplace_back(x + 1, i);
                mf.add_edge(x + 1, i, 1);
            }
            edgs.emplace_back(i, 1);
            mf.add_edge(i, 1, 1);
        }
        if (mf.maxflow() != sum) {
            cout << "No Solution!\n";
            return;
        }
        
        vector<vector<int>> ans(k + 5);
        for (int i = 0; i < edgs.size(); i++) {
            auto [u, v] = edgs[i];
            if (u <= k + 1 && u >= 2 && v >= k + 2 && v <= k + 1 + n) {
                if (mf.edge_flow(i)) {
                    ans[u - 1].push_back(v - k - 1);
                }
            }
        }

        for (int i = 1; i <= k; i++) {
            cout << i << ": ";
            for (auto x : ans[i]) cout << x  << " ";
            cout << "\n";
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