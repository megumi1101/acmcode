#include <bits/stdc++.h>
using namespace std;
 
struct DSU {
    vector<int> fa;
    void init(int n) {fa.assign(n + 1, 0); iota(fa.begin(), fa.end(), 0); }
    DSU(int n) {init(n);}
    int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
    void merge(int x,int y) {fa[find(x)] = find(y);}
    bool same(int x,int y) {return find(x) == find(y);}
};
 
void solve() {
    int n, m; cin >> n >> m;
    DSU dsu(n);
 
    int ans = 0;
    for (int i = 0 ;i <m;++i) {
        int u,v; cin>> u >>v;
        if (dsu.same(u, v)) {
            ++ans; continue;
        }
 
        dsu.merge(u, v);
    }
 
    for (int i = 2; i <= n;++i){
        if (dsu.same(1, i)) continue;
        dsu.merge(i, 1); 
        ++ans;
    }
 
    cout << ans << "\n";
}
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    solve();
    return 0;
}
