#include <bits/stdc++.h>
 
using namespace std;
#define int long long
 
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
 
const int mod = 1e9 + 7;
void sol() {
    int n, m;
    cin >> n >> m;
    DSU dsu(m);
    vector<int> ans;
    int lstx = -1;
    vector<int> mi(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        mi[i] = mi[i - 1] * 2 % mod;
    }
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        if (k == 1) {
            int x;
            cin >> x;
            if (lstx == -1) {
                lstx = x;
                ans.push_back(i);
            } else {
                if (dsu.merge(lstx, x)) {
                    ans.push_back(i);
                }
            }
        } else {
            int x, y;
            cin >> x >> y;
            if (dsu.merge(x, y)) {
                ans.push_back(i);
            }
        }
    }
    cout << mi[ans.size()] << " ";
    cout << ans.size() << "\n";
    for (auto x : ans) cout << x << " ";
    cout << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int T = 1;
    // cin >> T;
 
    while (T--) sol();
}
