#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
constexpr int inf = 1e18;
    struct node {
        int v, w;
        node(int v, int w) : v(v), w(w){}
        friend bool operator < (const node &a, const node& b) {
            return a.w > b.w;
        }
    };
    struct Line {
        int k, b;
        Line(int k, int b) : k(k), b(b){}
        friend bool operator < (const Line &a, const Line &b) {
            if (a.k == b.k) return a.b > b.b; // ***
            return a.k > b.k;
        }
    };
    struct Edge {
        int u, v, w, t;
        Edge(int u, int v, int w, int t) : u(u), v(v), w(w), t(t){}
    };
    void sol() {
        int n, m, q;
        cin >> n >> m;
        vector<Edge>edges;
        vector<int> dis1(n + 1, inf), dis2(n + 1, inf);
        vector<bool> vis(n + 1);
        for (int i = 1; i <= m; i++) {
            int u, v, w, t;
            cin >> u >> v >> w >> t;
            edges.emplace_back(u, v, w, t);
        }
        
        vector<vector<node>> ed(n + 1);
        for (auto [u, v, w, t] : edges) {
            ed[u].emplace_back(v, w);
        }
        
        auto dij1 = [&] (int s) -> void {
            dis1[s] = 0;
            priority_queue<node> q;
            q.push(node(s, dis1[s]));
            while (!q.empty()) {
                int u = q.top().v;
                q.pop();
                if (vis[u]) continue;
                vis[u] = 1;
                for (auto[v, w] : ed[u]) {
                    if (dis1[u] + w < dis1[v]) {
                        dis1[v] = dis1[u] + w;
                        q.push(node(v, dis1[v]));
                    }
                }
            }
        };
        dij1(1);

        for (int i = 0; i <= n; i++) ed[i].clear();
        fill(vis.begin(), vis.end(), 0);
        for (auto [u, v, w, t] : edges) {
            ed[v].emplace_back(u, w);
        }

        auto dij2 = [&] (int s) -> void {
            dis2[s] = 0;
            priority_queue<node> q;
            q.push(node(s, dis2[s]));
            while (!q.empty()) {
                int u = q.top().v;
                q.pop();
                if (vis[u]) continue;
                vis[u] = 1;
                for (auto[v, w] : ed[u]) {
                    if (dis2[u] + w < dis2[v]) {
                        dis2[v] = dis2[u] + w;
                        q.push(node(v, dis2[v]));
                    }
                }
            }
        };
        dij2(n);
        
        vector<Line>lines, slines;
        for (auto [u, v, w, t] : edges) {
            if (dis1[u] != inf && dis2[v] != inf)
                lines.emplace_back(-t, dis1[u] + dis2[v] + w);
        }
        
        sort(lines.begin(), lines.end());
        for (auto[k, b] : lines) {
            while (slines.size() > 1) {
                auto[k1, b1] = slines[slines.size() - 2];
                auto[k2, b2] = slines[slines.size() - 1];
                if ((__int128)1 * (b - b2) * (k1 - k2) <= (__int128)1 * (b2 - b1) * (k2 - k)) slines.pop_back();
                else break;
            }
            slines.emplace_back(k, b);
        }
        
        cin >> q;
        int siz = slines.size();
        while (q--) {
            int x;
            cin >> x;
            int l = 0, r = siz - 2, ans = -1;
            while (l <= r) {
                int mid = (l + r) / 2;
                auto[k1, b1] = slines[mid];
                auto[k2, b2] = slines[mid + 1];
                if(k1 * x + b1 > k2 * x + b2) ans = mid, l = mid + 1;
                else r = mid - 1;
            }
            ans++;
            auto[k, b] = slines[ans];
            cout << k * x + b << "\n";
        }
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T;
        cin >> T;
        while (T--) sol();
    }
#undef int
}

int main() {
    return Xbbbz::main(), 0;
}