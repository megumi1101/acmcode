#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
    void sol() {
        int n;
        cin >> n;
        list<int> unused;
        list<pair<int, string>> used;
        vector<int> vis(125);
        for (int i = 1; i <= n; i++) {
            string s;
            int x;
            cin >> s >> x;
            used.emplace_back(x, s);
            vis[x] = 1;
        }
        for (int i = 101; i <= 120; i++) {
            if (!vis[i]) unused.emplace_back(i);
        }
        
        used.sort();

        int m;
        cin >> m;
        while (m--) {
            string op;
            cin >> op;
            if (op == "assign") {
                string s;
                cin >> s;
                if (unused.empty()) continue;
                int u = unused.front();
                unused.pop_front();

                auto it = used.begin();
                while (it != used.end() && it->first < u) ++it;
                used.insert(it, {u, s});
            }
            else if (op == "return") {
                int x; 
                cin >> x;
                for (auto it = used.begin(); it != used.end(); ++it) {
                    if (it->first == x) {
                        used.erase(it);
                        unused.push_back(x);
                        break;
                    }
                }
            }
            else if (op == "display_used") {
                bool fg = 1;
                for (auto& [x, s] : used) {
                    if (!fg) cout << "-";
                    fg = 0;
                    cout << s << "(" << x << ")";
                }
                cout << '\n';
            } 
            else if (op == "display_free") {
                bool fg = 1;
                for (auto& x : unused) {
                    if (!fg) cout << "-";
                    fg = 0;
                    cout << x;
                }
                cout << '\n';
            }
        }
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
}

int main() {
    return Xbbbz::main(), 0;
}