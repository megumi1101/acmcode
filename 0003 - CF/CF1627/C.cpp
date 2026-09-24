#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
    constexpr int N = 1e6 + 10;
    struct node {
        int x, y, z;
        node (int x, int y, int z) : x(x), y(y), z(z) {}
    };
    void sol() {
        int n;
        cin >> n;
        vector<vector<node>> ed(n + 5);
        for (int i = 1; i < n; i++) {
            int x, y;
            cin >> x >> y;
            ed[x].push_back({y, i, -1});
            ed[y].push_back({x, i, -1});
        }
        int s = 0;
        for (int i = 1; i <= n; i++) {
            if (ed[i].size() == 1) {
                s = i;
            }
            if (ed[i].size() > 2) {
                cout << "-1\n";
                return;
            }
        }
        // cerr << s << "\n";
        int op = 0;
        auto dfs = [&] (auto &&dfs, int u, int fat) -> void {
            for (auto &i : ed[u]) {
                int v = i.x;
                if (v == fat) continue;
                op ^= 1;
                i.z = op;
                // cerr << i.y << "\n";
                dfs(dfs, v, u);
            }
        };
        dfs(dfs, s, 0);
        vector<int> ans(n - 1);
        for (int i = 1; i <= n; i++) {
            for (auto u : ed[i]) {
                if (u.z != -1) {
                    ans[u.y - 1] = u.z ? 3 : 2;
                }
            } 
        }
        for (int i : ans) cout << i << " ";
        cout << "\n";
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
/*
3 3
010
101
010
*/
