#include <bits/stdc++.h>
 
using namespace std;
 
namespace xbbbz{
    #define int long long
    const int inf = 1e18;
    const int N = 2e5 + 10;
    int n, m, cnt, k;
    bool fg;
    vector<int>ed[N];
    int a[N];
    void dfs(int u, int f) {
        for (int v : ed[u]) {
            if (v == f) continue;
            dfs(v, u);
            if (fg) return;
            a[u] ^= a[v];
        }
        if (a[u] == m) {
            a[u] = 0;
            cnt++;
            if (cnt == 2) fg = 1;
        }
    }
    void sol () {
        cin >> n >> k;
        m = 0;
        cnt = 0;
        fg = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            m ^= a[i];
            ed[i].clear();
        }
        for (int i = 1; i < n; i++) {
            int x, y;
            cin >> x >> y;
            ed[x].push_back(y);
            ed[y].push_back(x);
        }
        if (m == 0) {
            cout << "YES\n";
            return;
        }
        if (k == 2) {
            cout << "NO\n";
            return;
        }
        dfs(1, 0);
        if (fg) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
        
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T;
        cin >> T;
        while (T--) sol();
    }
 
    #undef int
}
 
int main() {
    return xbbbz::main(),0;
}
