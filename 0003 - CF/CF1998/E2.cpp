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
void sol() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1), L(n + 1), R(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    DSU dsu(n);
 
    vector<int> stk, sum(n + 1);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
        int lst = 0;
        while (!stk.empty() && a[stk.back()] < a[i]) {
            lst = stk.back();
            stk.pop_back();
        }
        L[i] = lst;
        if (!stk.empty()) {
            if (lst && a[i] <= sum[i - 1] - sum[stk.back()]) dsu.merge(i, lst);
            R[stk.back()] = i;
        } else {
            if (lst && a[i] <= sum[i - 1]) dsu.merge(i, lst);
        }
        stk.push_back(i);
        int fat = dsu.find(stk[0]);
        int u = R[fat];
        while (u) {
            if (sum[i] - sum[fat] >= a[fat]) dsu.merge(u, fat);
            fat = dsu.find(u); u = R[fat];
        }
        cout << dsu.size(stk[0]) << " ";
    }
    cout << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
