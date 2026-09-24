#include <bits/stdc++.h>

using namespace std;

#define int long long

struct DSU {
    int n;
    vector<int> f, siz, mx;
    DSU(int n_) {
        n = n_;
        f.assign(n + 5, 0);
        siz.assign(n + 5, 0);
        mx.assign(n + 5, 0);
        iota(f.begin(), f.end(), 0);
    }

    int find(int x) {
        vector<int> stk;
        while (x != f[x]) {
            stk.push_back(x);
            x = f[x];
        }

        int root = x;
        while (!stk.empty()) {
            int now = stk.back();
            stk.pop_back();
            mx[now] = max(mx[now], mx[f[now]]);
            f[now] = root;
        }

        return root;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) { // x is father
        x = find(x);
        y = find(y);
        if (x == y) return false;
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
};

const vector<int> dx{1, 0, -1, 0};
const vector<int> dy{0, 1, 0, -1};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;
    
    auto getid = [&](int x, int y) {
        return (x - 1) * m + y;
    };

    auto check = [&](int x, int y) -> bool {
        return x >= 1 && x <= n && y >= 1 && y <= m;
    };

    int lst = 0;

    DSU dsu(n * m);
    auto &mx = dsu.mx;
    auto &siz = dsu.siz;
    vector<int> a(n * m + 5);

    while (q--) {
        int op, x, y, v;
        cin >> op >> x >> y;
        x ^= lst;
        y ^= lst;
        int id = getid(x, y);

        // cerr << "x == " << x << "\n";
        // cerr << "y == " << y << "\n";
        // cerr << "lst == " << lst << "\n";
        if (op == 1) {
            cin >> v;
            siz[id] = 1;
            a[id] = v;
            
            for (int i = 0; i < 4; i++) {
                int tx = x + dx[i];
                int ty = y + dy[i];
                if (!check(tx, ty)) continue;
                int son = getid(tx, ty);
                son = dsu.find(son);
                if (a[son] && id != son) {
                    dsu.merge(id, son);
                    mx[son] = max(mx[son], v + 1 - siz[son]);
                }   
            }
            lst = siz[id] - 1;
        } else {
            dsu.find(id);
            lst = mx[id] - a[id];
            lst = max(lst, 0ll);
        }
        cout << lst << "\n";
    }
}

/*
2 3 9
1 1 2 1
1 2 1 1
1 2 2 2
2 3 0
1 0 2 8
2 1 2
1 4 4 9
2 6 6
2 5 7
*/