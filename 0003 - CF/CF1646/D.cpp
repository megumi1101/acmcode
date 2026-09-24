#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int mod = 20100403;
pair<int, int> operator+ (const pair<int, int> &a, const pair<int, int> &b) {
    return {a.first + b.first, a.second + b.second};
}
vector<int> f;
    void sol() {
        int n;
        cin >> n;
        if (n == 2) {
            cout << "2 2\n1 1\n";
            return;
        }
        vector<vector<int>> ed(n + 1);
        for (int i = 1; i < n; i++) {
            int x, y;
            cin >> x >> y;
            ed[x].push_back(y);
            ed[y].push_back(x);
        }
        
        vector<vector<pair<int, int>>> f(n + 1, vector<pair<int, int>>(2));
        auto dfs = [&](auto &&dfs, int u, int fat, int deep) -> void {
            f[u][0] = {0, 0};
            f[u][1] = {1, -ed[u].size()};
            for (auto v : ed[u]) {
                if (v == fat) continue;
                dfs(dfs, v, u, deep + 1);
                f[u][1] = f[u][1] + f[v][0];
                f[u][0] = f[u][0] + max(f[v][0], f[v][1]);
            }
        };
        dfs(dfs, 1, 0, 1);
 
        vector<int> a(n + 1, 1);
        auto dfs2 = [&](auto &&dfs2, int u, int fat, int op) -> void {
            if (op) a[u] = ed[u].size();
            for (auto v : ed[u]) {
                if (v == fat) continue;
                if (op || (!op && (f[v][0] > f[v][1]))) dfs2(dfs2, v, u, 0);
                else dfs2(dfs2, v, u, 1);
            }
        };
 
        if (f[1][0] > f[1][1]) {
            auto [x, y] = f[1][0];
            cout << x << " " << n - x - y << "\n";
            dfs2(dfs2, 1, 0, 0);
        } else {
            auto [x, y] = f[1][1];
            cout << x << " " << n - x - y << "\n";
            dfs2(dfs2, 1, 0, 1);
        }
 
        for (int i = 1; i <= n; i++) cout << a[i] << " ";
    }
 
    void main() {
        ios::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
#undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
