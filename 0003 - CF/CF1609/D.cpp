#include <bits/stdc++.h>
using namespace std;
 
namespace Xbbbz {
struct DSU {
    vector<int> f, siz;
    set<pair<int, int>> s;
 
    DSU() {}
    DSU(int n) {
        init(n);
    }
 
    void init(int n) {
        f.resize(n + 1);
        iota(f.begin(), f.end(), 0);
        siz.assign(n + 1, 1);
        for (int i = 1; i <= n; i++) s.insert({-1, i});
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
        s.erase(s.lower_bound({-siz[x], 0}));
        s.erase(s.lower_bound({-siz[y], 0}));
        siz[x] += siz[y];
        s.insert({-siz[x], x});
        f[y] = x;
        return true;
    }
 
    int size(int x) {
        return siz[find(x)];
    }
};
    void sol() {
        int n, q;
        cin >> n >> q;
        DSU dsu(n);
        int cnt = 1;
        while (q--) {
            int x, y;
            cin >> x >> y;
            if (!dsu.merge(x, y)) cnt++;
            int ans = 0;
            auto it = dsu.s.begin();
            for (int i = 1;  i <= cnt; i++) {
                if (it == dsu.s.end()) break;
                ans -= (it->first);
                it = next(it);
            } 
            cout << ans - 1 << "\n";
        }
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
