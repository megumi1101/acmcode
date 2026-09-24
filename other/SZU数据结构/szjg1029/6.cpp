#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
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
        cerr << floor(3.4) << "\n";
        vector a(n, vector(m, 0));
        vector<pair<int, int>> dxy = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        DSU dsu(n * m);
        for (auto &v : a) for (auto &i : v) cin >> i;
        int ans = n * m + 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j]) {
                    ans--;
                    continue;
                }
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    dsu.merge(n * m, i * n + j);
                } else {
                    for (auto[dx, dy] : dxy) {
                        int tx = i + dx;
                        int ty = j + dy;
                        if (a[tx][ty]) continue;
                        dsu.merge(tx * n + ty, i * n + j);
                    }
                }
            }
        }
        ans -= dsu.size(n * m);
        cout << ans << "\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
}

int main() {
    return Xbbbz::main(),0;
}