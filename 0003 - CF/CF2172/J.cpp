#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
struct DSU {
    vector<int> f, siz, lsty, hasx, R, d;
 
    DSU() {}
    DSU(int n, vector<int> &a) {
        init(n, a);
    }
 
    void init(int n, vector<int> &a) {
        f.resize(n + 1);
        R.resize(n + 1);
        iota(f.begin(), f.end(), 0);
        iota(R.begin(), R.end(), 0);
        siz.assign(n + 1, 1);
        lsty.assign(n + 1, 1);
        hasx.assign(n + 1, 1);
        d.assign(n + 2, 0);
    }
 
    void add (int x, int nowy) {
        x = find(x);
        int l = R[x] - hasx[x] + 1;
        int r = R[x];
        int up = nowy - lsty[x];
        lsty[x] = nowy;
        d[l] += up;
        d[r + 1] -= up;
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
 
    bool merge(int x, int y, int nowy) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        add(x, nowy);
        add(y, nowy);
        siz[x] += siz[y];
        hasx[x] += hasx[y];
        f[y] = x;
        lsty[x] = nowy;
        return true;
    }
 
    int size(int x) {
        return siz[find(x)];
    }
};
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1), h(n + 1);
    vector<vector<int>> pa(n + 1), ph(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i], pa[a[i]].push_back(i);
    for (int i = 1; i < n; i++) cin >> h[i], ph[h[i]].push_back(i);
    // h[n] = n; // 这里没加，一会再看
    
    DSU dsu(n, a);
    for (int hei = 0; hei <= n; hei++) {
        int nowy = hei + 1;
        for (auto id : pa[hei]) {
            dsu.add(id, nowy);
            dsu.hasx[dsu.find(id)]--;
        }
        for (auto id : ph[hei]) {
            int y = dsu.R[dsu.find(id)] + 1;
            dsu.merge(y, id, nowy);
        }
    }
    auto &d = dsu.d;
    for (int i = 1; i <= n; i++) {
        d[i] += d[i - 1];
        cout << d[i] << " ";
    }
    cout << "\n";
}
 
/*
aaaaa
bbbb
ccc
 
cacababababc
*/
