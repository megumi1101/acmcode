// QOJ user: lnxbb
// Contest: 2021 ç¬?6å±ŠICPCæ²ˆé˜³ç«?// Problem: #6613. Bitwise Exclusive-OR Sequence (6613)
// Submission: https://qoj.ac/submission/1710888
// Language: C++23

#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
struct DSU {
    vector <int> f, siz;
    DSU() {}
    DSU(int n) {
        init(n);
    }
    void init(int n) {
        f.resize(n + 1);
        iota(f.begin(), f.end(), 0);
        siz.assign(n + 1, -1);
    }
    
    int find (int x) {
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
        if (x == y) return false;
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
        vector<tuple<int, int, int>> a(m);
        DSU dsu(2 * n);
        DSU dsu2(2 * n);
        long long ans = 0;
        for (auto &[u, v, w] : a) cin >> u >> v >> w;
        for (int bit = 0; bit < 30; bit++) {
            dsu.init(2 * n);
            for (auto [u, v, w] : a) {
                w = (w >> bit) & 1;
                if (w == 1) {
                    dsu.merge(u, v + n);
                    dsu.merge(u + n, v);

                    dsu2.merge(u, v + n);
                    dsu2.merge(u + n, v);
                } else {
                    dsu.merge(u, v);
                    dsu.merge(u + n, v + n);

                    dsu2.merge(u, v);
                    dsu2.merge(u + n, v + n);
                }
            }

            for (int i = 1; i <= n; i++) {
                dsu2.merge(i, i + n);
                if (dsu.same(i, i + n)) {
                    cout << "-1\n";
                    return;
                }
            }
            
            vector<vector<int>> p(n + 1);
            for (int i = 1; i <= n; i++) {
                int x = dsu2.find(i);
                if (x > n) x -= n;
                p[x].push_back(i);
            }

            for (int i = 1; i <= n; i++) if (p[i].size()) {
                int u = p[i][0];
                int s = 1;
                for (int j = 1; j < p[i].size(); j++) {
                    if (dsu.find(u) == dsu.find(p[i][j])) s++; 
                }
                int t = p[i].size() - s;
                // cerr << s << t << "\n";
                s = min(s, t);
                ans += (long long) s * (1 << bit);
            }
            // cerr << ans << "\n";
        }
        cout << ans << "\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
}

int main() {
    return Xbbbz::main(), 0;
}
</code>