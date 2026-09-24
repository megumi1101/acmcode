#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
const int inf = 2e18;


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

double getdis(pair<int, int> p1, pair<int, int> p2) {
    long long dx = p1.first - p2.first;
    long long dy = p1.second - p2.second;
    return sqrt(dx * dx + dy * dy);
}

double gets(pair<int, int> croc) {
    int x = croc.first;
    int y = croc.second;
    return min(50 - abs(x), 50 - abs(y));
}
    void sol() {
        int n;
        double d;
        cin >> n >> d;
        DSU dsu(n + 1);
        vector<pair<int, int>> a(n + 1);  
        for (int i = 1; i <= n; i++) {
            cin >> a[i].first >> a[i].second;
        }

        const double x = 7.5;  
        for (int i = 1; i <= n; i++) {
            if (getdis({0, 0}, a[i]) <= d + x) {
                dsu.merge(0, i);
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (getdis(a[i], a[j]) <= d) dsu.merge(i, j);
            }
        }

        for (int i = 1; i <= n; i++) {
            if (gets(a[i]) <= d) dsu.merge(i, n + 1);
        }

        if (dsu.same(0, n + 1)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
#undef int
}

int main() {
    return Xbbbz::main(),0;
}