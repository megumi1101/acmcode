#include <iostream>
#include <vector>
#include <numeric>
 
using namespace std;
 
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
            return 0;
        }
        siz[x] += siz[y];
        f[y] = x;
        return 1;
    }
 
    int size(int x) {
        return siz[find(x)];
    }
};
 
void sol() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    vector<int> b(n + 1);
    vector<int> fix(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        if (b[i] != -1) {
            fix[i] = b[i]; 
        }
    }
    
    bool fg = 1;
    
    for (int i = 1; i <= n - k; i++) {
        if (a[i] != a[i + k]) {
            if (fix[i] != -1 && fix[i] != a[i]) fg = 0;
            fix[i] = a[i];
            if (fix[i + k] != -1 && fix[i + k] != a[i + k]) fg = 0;
            fix[i + k] = a[i + k];
        }
    }
    
    if (!fg) {
        cout << "NO\n";
        return;
    }
    DSU dsu(n);
    for (int i = 1; i <= n - k; i++) {
        if (a[i] == a[i + k]) {
            dsu.merge(i, i + k);
        }
    }
    
    vector<int> col(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        int fi = dsu.find(i);
        if (fix[i] != -1) {
            if (col[fi] != -1 && col[fi] != fix[i]) {
                fg = 0;
            }
            col[fi] = fix[i];
        }
    }
    
    if (!fg) {
        cout << "NO\n";
        return;
    }
    
    vector<int> has(n + 1, 0);
    for (int i = 1; i <= k; i++) {
        has[a[i]]++;
    }
    
    for (int i = 1; i <= k; i++) {
        int fi = dsu.find(i);
        if (col[fi] != -1) {
            int val = col[fi];
            if (has[val] == 0) {
                fg = 0;
                break;
            }
            has[val]--;
        }
    }
    
    if (fg) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
