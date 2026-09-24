#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
// #define int long long
#define db double
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
        int n, m;
        cin >> n >> m;
        vector<int> a(n + 5);
        vector<vector<int>> b(n + 5);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= m; i++) {
            int k;
            cin >> k;
            for (int j = 1; j <= k; j++) {
                int x;
                cin >> x;
                b[x].push_back(i);
            }
        }
        DSU dsu(2 * m);
        for (int i = 1; i <= n; i++) {
            if (!a[i]) {
                dsu.merge(b[i][0], b[i][1] + m);
                dsu.merge(b[i][0] + m, b[i][1]);
            }
            else {
                dsu.merge(b[i][0], b[i][1]);
                dsu.merge(b[i][0] + m, b[i][1] + m);
            }
        }
        for (int i = 1; i <= m; i++) {
            if (dsu.same(i, i + m)) {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        // init();
        int T = 1;
        // cin >> T;
        while (T--) sol(); 
    }
#undef int
}
 
int main() {
    return Xbbbz ::main(), 0;
}
