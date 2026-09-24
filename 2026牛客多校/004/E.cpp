#include <bits/stdc++.h>

using namespace std;


using i64 = long long;

struct E {
    int u, v, w;
};

void sol() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<pair<int, int>>> ed(n + 1);
    vector<E> edges(m);
    for (auto& [u, v, w] : edges) {
        cin >> u >> v >> w;
        ed[u].push_back({v, w});
    }

    vector d(n + 1, vector<i64>(n + 1, 1e18));

    auto dij = [&] (int s, auto &dis) -> void {
        dis[s] = 0LL;
        priority_queue<pair<i64, i64>, vector<pair<i64, i64>>, greater<>> q;
        q.emplace(dis[s], s);
        while (!q.empty()) {
            auto[cost, u] = q.top();
            q.pop();
            if (dis[u] == cost) {
                for (auto[v, w] : ed[u]) {
                    if (dis[u] + w < dis[v]) {
                        dis[v] = dis[u] + w;
                        q.emplace(dis[v], v);
                    }
                }
            }
        }
    };

    for (int i = 1; i <= n; i++) {
        dij(i, d[i]);
    }

    while (q--) {
        int k, x;
        cin >> k >> x;
        k--;

        long double ans = 0.0;
        int a = edges[k].u;
        int b = edges[k].v;
        int ww = edges[k].w;

        for (auto [v, u, w] : edges) {
            i64 div = w;
            if (v == a && u == b && ww == w) {
                div = x;
            }

            i64 dis = min(d[u][v], d[u][a] + d[b][v] + x);
            ans = max((long double)1.0 * dis / div, ans);
        }

        cout << fixed << setprecision(12) << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) sol();
}

/*
2
3 3 2
1 2 2
2 3 3
3 1 4
2 1
1 1


5 7 4
1 2 7
1 4 3
2 3 4
4 1 2
1 5 5
5 2 6
3 1 8
5 3
6 5
1 4
3 2
*/