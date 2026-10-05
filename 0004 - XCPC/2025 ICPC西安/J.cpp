#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int last_[300001], next_[600001], from_[600001], to_[600001], cnt;
void link(int x, int y) {
    from_[cnt] = x, to_[cnt] = y, next_[cnt] = last_[x], last_[x] = cnt++;
}
int f[300001], depth[300001], sz[300001], hson[300001];
void dfs0(int cur = 1, int dep = 1) {
    int maxn = -1;
    depth[cur] = dep, sz[cur] = 1, hson[cur] = cur;
    for (int i = last_[cur]; i != -1; i = next_[i])
        if (f[cur] != to_[i]) {
            f[to_[i]] = cur, dfs0(to_[i], dep + 1);
            sz[cur] += sz[to_[i]];
            if (maxn < sz[to_[i]]) maxn = sz[to_[i]], hson[cur] = to_[i];
        }
}
int dfn[300001], re_dfn[300001], top[300001], cnt_dfs;
void dfs1(int cur = 1, int t = 1) {
    dfn[++cnt_dfs] = cur, re_dfn[cur] = cnt_dfs, top[cur] = t;
    if (hson[cur] != cur) dfs1(hson[cur], t);
    for (int i = last_[cur]; i != -1; i = next_[i])
        if (f[cur] != to_[i] && hson[cur] != to_[i]) dfs1(to_[i], to_[i]);
}
int LCA(int x, int y) {
    while (top[x] != top[y]) {
        if (depth[top[x]] > depth[top[y]]) swap(x, y);
        y = f[top[y]];
    }
    if (depth[x] > depth[y]) swap(x, y);
    return y;
}
vector<ll> c, dp0,dp1;
vector<int> p,q;
void dfs2(int cur = 1) {
    7
    ;
}
void solution() {
    int n, m;
    cin >> n >> m, c.clear(), c.resize(n + 1);
    fill(last_ + 1, last_ + 1 + n, -1), fill(f + 1, f + 1 + n, 0);
    cnt = cnt_dfs = 0;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    for (int i = 1, u, v; i < n; ++i) cin >> u >> v, link(u, v), link(v, u);
    dfs0(), dfs1();
    dp0 = c, dfs2();
}
int main() {
    int T;
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> T;
    while (T--) solution();
    return 0;
}