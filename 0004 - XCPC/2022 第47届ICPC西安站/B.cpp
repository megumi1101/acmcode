// QOJ user: lnxbb
// Contest: 2022 ç¬?7å±ŠICPCè¥¿å®‰ç«?// Problem: #5114. Cells Coloring (5114)
// Submission: https://qoj.ac/submission/1666425
// Language: C++23

#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
const int inf = 2e18;
struct Dinic {
    struct Edge {
        int to, rev;
        int cap;
        Edge(int to_, int rev_, int cap_) : to(to_), rev(rev_), cap(cap_){}
    };

    int n, s, t;
    vector<vector<Edge>> g;
    vector<int> dep, cur;
    vector<pair<int, int>> fp;

    Dinic(int n, int s, int t) : n(n), s(s), t(t), g(n + 1), dep(n + 1), cur(n + 1) {}
    void reset(int n) {g.resize(n + 1); dep.resize(n + 1); cur.resize(n + 1);}

    int addedge(int u, int v, int cap) {
        int iu = g[u].size();
        int iv = g[v].size();
        g[u].emplace_back(v, iv, cap);
        g[v].emplace_back(u, iu, 0);
        fp.emplace_back(u, iu);
        return (int) fp.size() - 1;
    }

    bool bfs() {
        fill(dep.begin(), dep.end(), -1);
        queue<int> q;
        dep[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto[to, _, cap] : g[u]) {
                if (cap > 0 && dep[to] == -1) {
                    dep[to] = dep[u] + 1;
                    q.push(to);
                }
            }
        }
        return dep[t] != -1;
    }

    long long dfs(int u, int f) {
        if (u == t) return f;
        for (int &i = cur[u]; i < (int)g[u].size(); i++) {
            Edge &e = g[u][i];
            if (e.cap > 0 && dep[e.to] == dep[u] + 1) {
                int pushed = dfs(e.to, min(f, e.cap));
                if (pushed > 0) {
                    e.cap -= pushed;
                    g[e.to][e.rev].cap += pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }

    long long maxflow (long long INF = (1LL << 60)) {
        long long flow = 0;
        while (bfs()) {
            fill (cur.begin(), cur.end(), 0);
            while (long long pushed = dfs(s, INF)) flow += pushed;
        }
        return flow;
    }
};
    void sol() {
        int n, m, c, d;
        cin >> n >> m >> c >> d;
        vector<string> s(n);
        vector vis(n, vector(m, 0));
        for (auto &i : s) cin >> i;
        Dinic dinic(n + m + 5, 0, 1);
        int sume = 0;
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) {
                if (s[i][j] == '.') {
                    sume++;
                    dinic.addedge(i + 2, n + j + 2, 1);
                }
            }
        
        int t = max(n, m);
        int ans = sume * d;
        int flow = 0;
        for (int k = 1; k <= t; k++) {
            for (int i = 0; i < n; i++) dinic.addedge(0, i + 2, 1);
            for (int j = 0; j < m; j++) dinic.addedge(n + j + 2, 1, 1);;
            flow += dinic.maxflow();
            ans = min(ans, (sume - flow) * d + k * c);
            if (flow == sume) break;
        }
        cout << ans << "\n";
    }

    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
}
#undef int
int main() {
    return Xbbbz::main(),0;
}
</code>