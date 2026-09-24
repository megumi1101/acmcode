#include <bits/stdc++.h>
 
using namespace std;
 
const int inf = 1e9;
 
struct DSU {
    vector<int> f, siz;
 
    DSU() {}
    DSU(int n) {
        init(n);
    }
 
    void init(int n) {
        f.resize(n + 1);
        iota(f.begin(), f.end(), 0);
        siz.assign(n + 1, 1);
    }
 
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
 
    bool same(int x, int y) {
        return find(x) == find(y);
    }
 
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
 
    int size(int x) {
        return siz[find(x)];
    }
};
 
void sol() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto &x : p) {cin >> x;}
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    int mx = p.back();
    
    DSU dsu(mx);
    int lstn = p.size();
    vector<int> viss(mx + 1), del(mx + 1);
    for (auto x : p) viss[x] = 1;
    for (auto x : p) {
        if (del[x]) continue;
        for (int y = x + x; y <= mx; y += x) {
            if (viss[y]) {del[y] = 1; dsu.merge(x, y);}
        }
    }
    
    // vector<int> p2;
    // for (auto x : p) if(!del[x]) p2.emplace_back(x);
    // p = p2;
    // n = p.size();
    // mx = p.back();
    int ans = 0;
 
    while (dsu.size(p[0]) != lstn) {
        set<int> s;
        for (auto x : p) s.insert(x);
 
        int cnt = 0;
        vector<vector<int>> cols;
        vector<int> vis(mx + 1, -1);
        for (auto x : p) {
            int y = dsu.find(x);
            if (vis[y] == -1) {
                vis[y] = cnt;
                cols.emplace_back();
                cnt++;
            }
            cols[vis[y]].emplace_back(x);
        }
        
        vector<int> mn(cnt, inf);
        vector<pair<int, int>> mnedgs(cnt);
        for (auto &v : cols) {
            for (auto x : v) s.erase(x);
            for (auto x : v) {
                int mx_ = *s.rbegin();
                for (int y = x; y < mx_; y += x) {
                    int z = *s.upper_bound(y);
                    
                    y = z / x * x;
                    int col1 = vis[dsu.find(x)];
                    int col2 = vis[dsu.find(z)];
                    int now = z - y;
 
                    if (now < mn[col1]) {
                        mn[col1] = now;
                        mnedgs[col1] = {x, z};
                    }
 
                    if (now < mn[col2]) {
                        mn[col2] = now;
                        mnedgs[col2] = {x, z};
                    }
                }
            }
            for (auto x : v) s.insert(x);
        }
    
        for (int i = 0; i < cnt; i++) {
            if (mn[i] == inf) continue;
            auto [x, y] = mnedgs[i];
            if (dsu.merge(x, y)) {
                ans += mn[i];
            }
        }
    }
 
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
 
    int T = 1;
    cin >> T;
    while (T--) sol();
 
}
