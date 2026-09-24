#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
void solA() {
    int n, s;
    cin >> n >> s;
    s--;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if (u > v) swap(u, v);
        if (((s >> u) & 1) == ((s >> v) & 1)) swap(u, v); // small to big not equal  else equal
        cout << u + 1 << " " << v + 1 << endl;
    }
}
 
void solB() {
    int n;
    cin >> n;
    vector<vector<int>> ed(n);
    vector vis(n, vector(n, 0));
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        vis[u][v] = 1;
        ed[u].push_back(v);
        ed[v].push_back(u);
    }
    vector<int> f(n);
 
    [&](this auto &&dfs, int u, int fat) -> void {
        if (u != n - 1) {
            int x = u, y = fat;
            if (x < y) {
                if (vis[x][y]) f[x] = f[y] ^ 1;
                else f[x] = f[y];
            } else {
                if (vis[y][x]) f[x] = f[y] ^ 1;
                else f[x] = f[y];
            }
        }
        for (auto v : ed[u]) if (v != fat) {
            dfs(v, u);
        }
    }(n - 1, -1);
 
    int s = 0;
    for (int bit = 0; bit < n - 1; bit++) {
        if (f[bit]) s |= (1 << bit);
    }
    s++;
    cout << s << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("E.out", "w", stdout);
    int t, q;
    cin >> t >> q;
    if (q == 1) while (t--) solA();
    if (q == 2) while (t--) solB();
}
 
/*
1 2
7
6 1
5 3
4 2
3 4
2 1
7 6
*/
