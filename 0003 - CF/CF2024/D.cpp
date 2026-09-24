#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
    constexpr int N = 1e6 + 10;
    struct node {
        int v, w;
        node (int v, int w) : v(v), w(w) {}
        friend bool operator < (const node &a, const node &b) {
            return a.w > b.w;
        }
    };
    void sol() {
        int n;
        cin >> n;
        vector<vector<node>> ed(n + 5);
        vector<int> a(n + 5), b(n + 5), dis(n + 5, 1e18), vis(n + 5);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];
        for (int i = 1; i < n; i++) {
            ed[i + 1].push_back(node(i, 0));
        }
        for (int i = 1; i <= n; i++) {
            ed[i].push_back(node(b[i], a[i]));
        }
        auto dij = [&] (int s) -> void {
            dis[s] = 0;
            priority_queue<node> q;
            q.push(node(s, dis[s]));
            while (!q.empty()) {
                int u = q.top().v;
                q.pop();
                if (vis[u]) continue;
                vis[u] = 1;
                for (auto[v, w] : ed[u]) {
                    if (dis[u] + w < dis[v]) {
                        dis[v] = dis[u] + w;
                        q.push(node(v, dis[v]));
                    }
                }
            }
        };
        dij(1);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            a[i] += a[i - 1];
            ans = max(ans, a[i] - dis[i]);
        }
        cout << ans << "\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
#undef int
}
 
int main() {
    return Xbbbz ::main(), 0;
}
