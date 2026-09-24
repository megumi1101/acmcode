#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
    void sol() {
        int n;
        cin >> n;
        map<string, int> mp;
        vector<int> vis(n);
        vector<string> s(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
            mp[s[i]] = i;
        }

        int m;
        cin >> m;
        vector<vector<pair<int, int>>> ed(n);
        for (int i = 0; i < m; i++) {
            string x, y;
            int z;
            cin >> x >> y >> z;
            int tx = mp[x];
            int ty = mp[y];
            ed[tx].emplace_back(ty, z);
            ed[ty].emplace_back(tx, z);
        }

        string t;
        cin >> t;
        int st = mp[t];
        vis[st] = 1;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q;
        for (auto [v, w] : ed[st]) {
            q.emplace(w, st, v);
        }
        
        int sum = 0;
        vector<tuple<string, string, int>> ans;
        for (int i = 1; i < n; i++) {
            while (!q.empty() && vis[get<2>(q.top())]) q.pop();
            auto [w, u, v] = q.top();
            q.pop();
            sum += w;
            ans.emplace_back(s[u], s[v], w);
            vis[v] = 1;
            for (auto [tv, tw] : ed[v]) {
                if (vis[tv]) continue;
                q.emplace(tw, v, tv);
            }
        }
        cout << sum << "\n";
        for (auto[u, v, w] : ans) cout << u << " " << v << " " << w << "\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
}

int main() {
    return Xbbbz::main(),0;
}