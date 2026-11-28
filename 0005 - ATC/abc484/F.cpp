#include <bits/stdc++.h>

using namespace std;

#define ls (u << 1)
#define rs (u << 1 | 1)
template<typename Info>
struct SegmentTree {
    int n;
    vector<Info> info;

    SegmentTree(int n = -1) : n(n), info(n >= 0 ? 4 * (n + 1) + 5 : 0) {}

    SegmentTree(const vector<Info> &a) : SegmentTree((int)a.size() - 1) {
        if (n >= 0) build(1, 0, n, a);
    }

    void pull(int u) {
        info[u] = info[ls] + info[rs];
    }

    void build(int u, int l, int r, const vector<Info> &a) {
        if (l == r) return void(info[u] = a[l]);
        int m = (l + r) >> 1;
        build(ls, l, m, a);
        build(rs, m + 1, r, a);
        pull(u);
    }

    void build(const vector<Info> &a) {
        n = (int)a.size() - 1;
        info.assign(n >= 0 ? 4 * (n + 1) + 5 : 0, Info{});
        if (n >= 0) build(1, 0, n, a);
    }

    void modify(int u, int l, int r, int x, const Info &v) {
        if (l == r) return void(info[u] = v);
        int m = (l + r) >> 1;
        x <= m ? modify(ls, l, m, x, v) : modify(rs, m + 1, r, x, v);
        pull(u);
    }

    void modify(int x, const Info &v) {
        // assert(0 <= x && x <= n);
        modify(1, 0, n, x, v);
    }

    Info query(int L, int R, int u, int l, int r) {
        if (L <= l && r <= R) return info[u];
        int m = (l + r) >> 1;
        if (R <= m) return query(L, R, ls, l, m);
        if (L > m) return query(L, R, rs, m + 1, r);
        return query(L, R, ls, l, m) + query(L, R, rs, m + 1, r);
    }

    Info query(int l, int r) {
        // assert(0 <= l && l <= r && r <= n);
        return query(l, r, 1, 0, n);
    }
};


struct Info {
    int mx = -1;
    int mn = 1e9;
};

Info operator+(const Info &a, const Info &b) {
    return {max(a.mx, b.mx), min(a.mn, b.mn)};
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<Info> a(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x != -1) a[i] = {x, x};
    }
    SegmentTree seg(a);

    while (q--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            a[x] = Info();
            if (y != -1) a[x] = {y, y};
            seg.modify(x, a[x]);
        } else {
            auto[mx, mn] = seg.query(x, y);
            if (mn == mx || mx == -1) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }
}

/*
8 9
5 -1 3 -1 2 3 4 5
2 3 6
1 5 -1
2 3 6
1 7 5
2 7 8
2 1 8
1 3 5
1 6 -1
2 1 8


*/