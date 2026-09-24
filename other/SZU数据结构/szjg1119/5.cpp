#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<vector<int>> adj(N);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        if (u >= 0 && u < N && v >= 0 && v < N) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    int K;
    cin >> K;
    vector<int> lod(K);
    for (int i = 0; i < K; ++i) {
        cin >> lod[i];
    }

    vector<int> lost(N, 0);

    auto cc = [&](const vector<int>& removed) -> int {
        vector<int> vis(N, 0);
        int comps = 0;
        for (int i = 0; i < N; ++i) {
            if (removed[i] || vis[i]) continue;
            ++comps;
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) {
                    if (!removed[v] && !vis[v]) {
                        vis[v] = 1;
                        q.push(v);
                    }
                }
            }
        }
        return comps;
    };

    int pc = cc(lost);
    int lcc = 0;

    for (int i = 0; i < K; ++i) {
        int c = lod[i];
        lost[c] = 1;
        ++lcc;
        int ccp = cc(lost);
        if (ccp > pc) {
            cout << "Red Alert: City " << c << " is lost!" << "\n";
        } else {
            cout << "City " << c << " is lost." << "\n";
        }
        pc = ccp;
        if (lcc == N) {
            cout << "Game Over." << "\n";
        }
    }

    return 0;
}
