#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e18;
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
        assert(0 <= x && x <= n);
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
        assert(0 <= l && l <= r && r <= n);
        return query(l, r, 1, 0, n);
    }
};


struct Info {
    int mn, pos;
};

Info operator+(const Info &a, const Info &b) {
    if (a.mn <= b.mn) {
        return a;
    } else {
        return b;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> t(n + 1);
    vector<vector<int>> fr(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        fr[t[i]].push_back(i);
    }
    
    vector<int> a(n + 1), di(n + 1), time(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        if (a[t[i]] > a[i]) {
            di[i] = 1;
        } else {
            di[i] = -1;
        }
    }
    
    vector<Info> ifoo(n + 1);
    ifoo[0] = {inf + 100, 0};
    for (int i = 1; i <= n; i++) {
        if (di[i] == di[t[i]]) {
            time[i] = inf;
        } else {
            time[i] = abs(a[i] - a[t[i]]);
        }
        ifoo[i] = {time[i], i};
    }
    SegmentTree<Info> seg(ifoo);
    vector<int> vis(n + 1);
    for (int c = 1; c <= n; c++) {
        auto[tim, pos] = seg.query(1, n);
        vis[pos] = 1;
        for (auto x : fr[pos]) {
            if (vis[x]) continue;
            if (di[x] == di[pos]) {
                time[x] = abs(a[x] - a[pos]) * 2 + tim;
            } else {
                time[x] = tim + (time[x] - tim) * 2;
            }
            seg.modify(x, {time[x], x});
        }
        seg.modify(pos, {inf + 100, pos});
    }

    for (int i = 1; i <= n; i++) {
        cout << time[i] << " ";
    }
    cout << "\n";
}