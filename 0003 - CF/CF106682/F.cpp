#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<array<int, 3>>> ed(n + 1);
    vector<pair<int, int>> eds(m + 1);

    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        eds[i] = {x, y};
        ed[x].push_back({y, 1, i});
        ed[y].push_back({x, 1, i});
    }
    
    vector<int> mne(m + 1, inf);

    auto dij = [&] (int s, int t) -> int {
        vector<int> dis(n + 1, inf);
        dis[s] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.emplace(dis[s], s);
        while (!q.empty()) {
            auto[cost, u] = q.top();
            q.pop();
            if (dis[u] == cost) {
                for (auto[v, w, _] : ed[u]) {
                    if (dis[u] + w < dis[v]) {
                        dis[v] = dis[u] + w;
                        q.emplace(dis[v], v);
                    }
                }
            }
        }
        return dis[t];
    };

    
    mne[0] = dij(1, n);
    for (int i = 1; i <= m; i++) {
        for (int u = 1; u <= n; u++) {
            for (auto &[v, w, id] : ed[u]) {
                if (id == i) {
                    w = 0;
                }
            }
        }
        mne[i] = dij(1, n);
    }

    vector<double> ans(m + 1, 1e9);

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < i; j++) {
            ans[i] = min(ans[i], (double)mne[j] / (i - j));
        }
    }

    cout << fixed << setprecision(8);
    for (int i = 1; i <= m; i++) cout << ans[i] << "\n";
}


/*
4 4
1 2
2 3
3 1
2 4
*/