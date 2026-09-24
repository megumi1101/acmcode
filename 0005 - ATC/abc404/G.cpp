// AtCoder user: lnxbb
// Contest: abc404
// Problem: abc404_g
// Submission: https://atcoder.jp/contests/abc404/submissions/65610193
// Language: C++ 20 (gcc 12.2)

#include <bits/stdc++.h>
using namespace std;

namespace Xbbbz {
    #define int long long
    const int N = 5e3 + 10, inf = 1e18;
    int inq[N], dis[N];
    queue<int>q;
    bool vis[N];
    int n, m;
    struct node {
        int v, w;
        node() {}
        node(int v, int w) : v(v), w(w) {}
    };
    vector<node> ed[N];
    bool spfa(int x) {
        while (!q.empty()) q.pop();
        q.push(x);
        inq[x]++;
        vis[x] = 1;
        dis[x] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            vis[u] = 0;
            for (int i = 0; i < ed[u].size(); i++) {
                int v = ed[u][i].v;
                int w = ed[u][i].w;
                if (dis[u] + w < dis[v]) {
                    dis[v] = dis[u] + w;
                    if (!vis[v]) {
                        vis[v] = 1;
                        q.push(v);
                        inq[v]++;
                        if (inq[v] > n) return false;
                    }
                }
            }
        }
        return true;
    }
    void sol() { 
        memset(dis, 0x3f, sizeof(dis));
        cin >> n >> m;
        for (int i = 1; i <= n; i++) ed[i].push_back(node(i - 1, -1));
        // for (int i = 0; i <= n; i++) ed[n + 1].push_back(node(i, 0));
        for (int i = 1; i <= m; i++) {
            int l, r, s;
            cin >> l >> r >> s;
            ed[r].push_back(node(l - 1, -s));
            ed[l - 1].push_back(node(r, s));
        }
        int ans = -1;
        if (spfa(n)) {
            ans = -dis[0];
        }
        cout << ans << "\n";
    }
    void main() {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int T = 1;
        // cin >> T;
        while (T--) {
            sol();
        }
    }
    #undef int
}

int main() {
    return Xbbbz::main(), 0;
}