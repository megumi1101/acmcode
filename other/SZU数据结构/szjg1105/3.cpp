#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
const int inf = 1e9;
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

        
        vector<int> dis(n, inf), frm(n, -1);
        vector<vector<pair<int, int>>> ed(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x;
                cin >> x;
                if (x) ed[i].emplace_back(j, x);
            }
        }
        
    
        auto dij = [&](int s) {
            dis[s] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
            q.emplace(dis[s], s);
            while (!q.empty()) {
                auto[cost, u] = q.top();
                q.pop();
                if (cost == dis[u]) {
                    for (auto[v, w] : ed[u]) {
                        if (dis[u] + w < dis[v]) {
                            dis[v] = dis[u] + w;
                            q.emplace(dis[v], v);
                            frm[v] = u;
                        }
                    }
                }
            }
        };

        string tt;
        cin >> tt;
        int st = mp[tt];

        dij(st);

        for (int i = 0; i < n; i++) {
            if (i == st) continue;
            if (dis[i] == inf) {
                cout << tt << "-" << s[i] << "-" << "-1\n";
                continue;
            }
            cout << tt << "-" << s[i] << "-" << dis[i] << "----";
            vector<string> ans;
            int x = i;
            while (x != -1) {
                ans.emplace_back(s[x]);
                x = frm[x];
            }
            reverse(ans.begin(), ans.end());
            cout << "[";
            for (auto &v : ans) cout << v << " ";
            cout << "]\n"; 
        }
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
}

int main() {
    return Xbbbz::main(),0;
}