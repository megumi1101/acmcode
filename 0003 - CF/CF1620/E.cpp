#include <bits/stdc++.h>
using namespace std;
 
namespace Xbbbz {
    void sol() {
        int q;
        cin >> q;
        int cnt = 0;
        vector<vector<int>> s(5e5 + 10);
        while (q--) {
            int op;
            cin >> op;
            if (op == 1) {
                int x;
                cin >> x;
                ++cnt;
                s[x].push_back(cnt);
            } else {
                int x, y;
                cin >> x >> y;
                if (x == y) continue;
                if (s[x].size() > s[y].size()) {
                    swap(s[x], s[y]);
                }
                for (auto u : s[x]) s[y].emplace_back(u);
                s[x].clear();
            }
        }
        vector<int> a(cnt + 1);
        int i = -1;
        for (auto &v : s) {
            ++i;
            for (auto &x : v) {
                a[x] = i;
            }
        }
        for (int i = 1; i <= cnt; i++) cout << a[i] << " ";
    }
 
    void main() {
        ios::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
}
 
int main() {
    return Xbbbz::main(), 0;
}
