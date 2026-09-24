#include <bits/stdc++.h>
 
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
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    
    for (int i = 0; i < n; i++) {
        if (s[i][i] == '0') {cout << "NO\n"; return;}
    }
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                if (s[i][j] == s[j][i] && s[i][j] == '1') {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
 
    vector vis(n, vector(n, 0));
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (k == i || k == j || i == j) continue;
                if (s[i][k] == '1' && s[k][j] == '1') vis[i][j] = 1;
            }
        }
    }
 
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            if (s[i][j] == '1' && vis[i][j] == 0) {
                ans.push_back({i, j});
            }
        }
    }
 
 
    vector<string> t(n);
    for (int i = 0; i < n; i++) t[i].resize(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            t[i][j] = '0';
    for (int i = 0; i < n; i++) t[i][i] = '1';
    for (auto [x, y] : ans) t[x][y] = '1';
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (t[i][k] == '1' && t[k][j] == '1') {
                    t[i][j] = '1';
                }
            }
        }
    }
 
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            cout << "NO\n";
            return;
        }
    }
 
 
 
 
    if (ans.size() == n - 1) {
        DSU dsu(n);
        for (auto [x, y] : ans) dsu.merge(x, y);
        if (dsu.size(0) != n) {
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
        for (auto [x, y] : ans) {
            cout << x + 1 << " " << y + 1 << "\n";
        }
    } else {
        cout << "NO\n";
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) sol();
}
