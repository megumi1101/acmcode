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
        int n;
        while (cin >> n) {
            priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    int x;
                    cin >> x;
                    if (x) q.emplace(x, i, j);
                }
            }

            int m;
            cin >> m;
            DSU dsu(n);

            for (int i = 1; i <= m; i++) {
                int x, y;
                cin >> x >> y;
                dsu.merge(x, y);
            }
            int sum = 0;
            int cnt = 1;
            while (!q.empty()) {
                auto[w, x, y] = q.top();
                q.pop();
                if (!dsu.merge(x, y)) continue;
                sum += w;
                cnt++;
            }
            cout << sum << "\n";
        }
        
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
}

int main() {
    return Xbbbz::main(),0;
}