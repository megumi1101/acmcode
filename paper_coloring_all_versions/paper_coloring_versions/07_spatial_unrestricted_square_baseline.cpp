// Unrestricted repeated colors + time and spatial query intervals.
// BASELINE ONLY: O((m^2+q) log m) time, O(m+q) space; not for m=500000.
// Input: n m q; m lines L R c; q lines l r x y.
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct Info {
    i64 len = 0, pre = 0, suf = 0, sum = 0;
    int lc = 0, rc = 0;
};

Info mergeInfo(const Info &a, const Info &b) {
    if (!a.len) return b;
    if (!b.len) return a;
    Info c{a.len + b.len, a.pre, b.suf, a.sum + b.sum, a.lc, b.rc};
    if (a.rc == b.lc) {
        if (a.rc != 0) c.sum += 2 * a.suf * b.pre;
        if (a.pre == a.len) c.pre += b.pre;
        if (b.suf == b.len) c.suf += a.suf;
    }
    return c;
}

struct PaintTree {
    int n;
    vector<Info> tr;
    vector<int> tag;

    explicit PaintTree(const vector<i64> &x) : n((int)x.size() - 1) {
        int size = 1;
        while (size < n) size <<= 1;
        tr.resize(size * 2);
        tag.assign(size * 2, -1);
        auto build = [&](auto &&self, int p, int l, int r) -> void {
            tr[p].len = tr[p].pre = tr[p].suf = x[r + 1] - x[l];
            if (l == r) return;
            int mid = (l + r) / 2;
            self(self, p * 2, l, mid);
            self(self, p * 2 + 1, mid + 1, r);
        };
        build(build, 1, 0, n - 1);
    }

    void apply(int p, int c) {
        tr[p].lc = tr[p].rc = c;
        tr[p].pre = tr[p].suf = tr[p].len;
        tr[p].sum = c ? tr[p].len * tr[p].len : 0;
        tag[p] = c;
    }
    void push(int p) {
        if (tag[p] == -1) return;
        apply(p * 2, tag[p]);
        apply(p * 2 + 1, tag[p]);
        tag[p] = -1;
    }
    void assign(int p, int l, int r, int ql, int qr, int c) {
        if (ql <= l && r <= qr) return apply(p, c);
        push(p);
        int mid = (l + r) / 2;
        if (ql <= mid) assign(p * 2, l, mid, ql, qr, c);
        if (qr > mid) assign(p * 2 + 1, mid + 1, r, ql, qr, c);
        tr[p] = mergeInfo(tr[p * 2], tr[p * 2 + 1]);
    }
    Info query(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return tr[p];
        push(p);
        int mid = (l + r) / 2;
        if (qr <= mid) return query(p * 2, l, mid, ql, qr);
        if (ql > mid) return query(p * 2 + 1, mid + 1, r, ql, qr);
        return mergeInfo(query(p * 2, l, mid, ql, qr),
                         query(p * 2 + 1, mid + 1, r, ql, qr));
    }
    void assign(int l, int r, int c) {
        if (l <= r) assign(1, 0, n - 1, l, r, c);
    }
    Info query(int l, int r) {
        return l <= r ? query(1, 0, n - 1, l, r) : Info{};
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;
    struct Operation { int L, R, c, a, b; };
    vector<Operation> op(m + 1);
    vector<i64> raw(m + 1), values, coord{0, n};
    for (int i = 1; i <= m; i++) {
        cin >> op[i].L >> op[i].R >> raw[i];
        values.push_back(raw[i]);
        coord.push_back(op[i].L - 1);
        coord.push_back(op[i].R);
    }
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    sort(coord.begin(), coord.end());
    coord.erase(unique(coord.begin(), coord.end()), coord.end());
    auto index = [&](i64 x) {
        return int(lower_bound(coord.begin(), coord.end(), x) - coord.begin());
    };
    for (int i = 1; i <= m; i++) {
        op[i].c = int(lower_bound(values.begin(), values.end(), raw[i]) - values.begin()) + 1;
        op[i].a = index(op[i].L - 1);
        op[i].b = index(op[i].R) - 1;
    }

    struct Query { int l, r, x, y, id; };
    vector<vector<Query>> byRight(m + 1), byLeft(m + 1);
    for (int id = 0; id < q; id++) {
        int l, r, x = 1, y = n;
        cin >> l >> r >> x >> y;
        byRight[r].push_back({l, r, x, y, id});
    }
    // Counting-sort the queries by r, then group by l.
    for (int r = 1; r <= m; r++)
        for (auto query : byRight[r]) byLeft[query.l].push_back(query);
    vector<vector<Query>>().swap(byRight);

    vector<i64> ans(q);
    for (int l = 1; l <= m; l++) {
        if (byLeft[l].empty()) continue;
        PaintTree tree(coord);  // Start from a blank tape for this l.
        int r = l - 1;
        auto cropLeaf = [&](int p, i64 len) {
            Info z = tree.query(p, p);
            z.len = z.pre = z.suf = len;
            z.sum = z.lc ? len * len : 0;
            return z;
        };
        auto querySpace = [&](int x, int y) {
            i64 left = x - 1, right = y;  // Physical half-open interval.
            int a = int(upper_bound(coord.begin(), coord.end(), left) - coord.begin()) - 1;
            int b = int(lower_bound(coord.begin(), coord.end(), right) - coord.begin()) - 1;
            if (a == b) return cropLeaf(a, right - left).sum;
            Info first = cropLeaf(a, coord[a + 1] - left);
            Info last = cropLeaf(b, right - coord[b]);
            return mergeInfo(mergeInfo(first, tree.query(a + 1, b - 1)), last).sum;
        };
        for (auto query : byLeft[l]) {
            while (r < query.r) {
                ++r;
                tree.assign(op[r].a, op[r].b, op[r].c);
            }
            ans[query.id] = querySpace(query.x, query.y);
        }
    }
    for (i64 x : ans) cout << x << '\n';
}
