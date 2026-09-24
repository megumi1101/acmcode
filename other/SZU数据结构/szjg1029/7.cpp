#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
const int inf = 1e9;
    void sol() {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> ed(n + 1);
        vector<int> dis(n + 1);
        for (int i = 1; i <= m; i++) {
            int x, y;
            cin >> x >> y;
            ed[x].push_back(y);
            ed[y].push_back(x);
        }
        auto dij = [&] (int s) -> void {
            fill(dis.begin(), dis.end(), inf);
            dis[s] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
            q.emplace(dis[s], s);
            while (!q.empty()) {
                auto[cost, u] = q.top();
                q.pop();
                if (dis[u] == cost) {
                    for (auto v : ed[u]) {
                        if (dis[u] + 1 < dis[v]) {
                            dis[v] = dis[u] + 1;
                            q.emplace(dis[v], v);
                        }
                    }
                }
            }
        };

        int k;
        cin >> k;
        cout << fixed << setprecision(2);
        for (int i = 0; i < k; i++) {
            int x;
            cin >> x;
            dij(x);
            double sum = 0;
            for (int i = 1; i <= n; i++) sum += dis[i];
            sum = double(n - 1) / sum;
            cout << "Cc(" << x << ")=" << sum << "\n";
        }
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
#undef int 
}

int main() {
    return Xbbbz::main(),0;
}