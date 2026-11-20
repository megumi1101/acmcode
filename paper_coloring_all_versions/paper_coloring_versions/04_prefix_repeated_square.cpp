// 前缀/后缀染色，颜色可重复；询问操作区间 [l,r] 的连续色段长度平方和。
// 输入：n m q；m 行 o x c；q 行 l r。空白不计答案。
// 时间 O((m+q) log m)，空间 O(m+q)。C++17。
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

struct RangeEnds {
    int size = 1, inf;
    vector<pair<int, int>> tr;
    static pair<int, int> merge(pair<int, int> a, pair<int, int> b) {
        return {max(a.first, b.first), min(a.second, b.second)};
    }
    RangeEnds(int n, const vector<pair<int, int>> &v) : inf(n + 1) {
        while (size < (int)v.size()) size <<= 1;
        tr.assign(size * 2, {0, inf});
        copy(v.begin(), v.end(), tr.begin() + size);
        for (int p = size - 1; p; --p) tr[p] = merge(tr[p * 2], tr[p * 2 + 1]);
    }
    pair<int, int> query(int l, int r) const {  // 操作编号，闭区间，1-based
        pair<int, int> ans{0, inf};
        for (l += size - 1, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans = merge(ans, tr[l++]);
            if (r & 1) ans = merge(ans, tr[--r]);
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;
    struct Operation { int o, x, c, cut; };
    vector<Operation> op(m + 1);
    vector<i64> color(m + 1), values, coord{0, n};
    vector<pair<int, int>> ends;
    for (int i = 1; i <= m; ++i) {
        cin >> op[i].o >> op[i].x >> color[i];
        values.push_back(color[i]);
        coord.push_back(op[i].o == 0 ? op[i].x : op[i].x - 1);
        ends.push_back(op[i].o == 0 ? pair{op[i].x, n + 1} : pair{0, op[i].x});
    }
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    sort(coord.begin(), coord.end());
    coord.erase(unique(coord.begin(), coord.end()), coord.end());
    auto index = [&](i64 x) { return int(lower_bound(coord.begin(), coord.end(), x) - coord.begin()); };
    for (int i = 1; i <= m; ++i) {
        op[i].c = int(lower_bound(values.begin(), values.end(), color[i]) - values.begin()) + 1;
        op[i].cut = index(op[i].o == 0 ? op[i].x : op[i].x - 1);
    }
    vector<vector<pair<int, int>>> ask(m + 1);
    for (int id = 0, l, r; id < q; ++id) {
        cin >> l >> r;
        ask[r].push_back({l, id});
    }

    PaintTree tree(coord);
    RangeEnds rmq(n, ends);
    vector<i64> ans(q);
    for (int r = 1; r <= m; ++r) {
        auto [o, x, c, cut] = op[r];
        if (o == 0) tree.assign(0, cut - 1, c);
        else tree.assign(cut, tree.n - 1, c);
        for (auto [l, id] : ask[r]) {
            auto [A, B] = rmq.query(l, r);
            if (A + 1 >= B) ans[id] = tree.tr[1].sum;
            else ans[id] = tree.query(0, index(A) - 1).sum
                         + tree.query(index(B - 1), tree.n - 1).sum;
        }
    }
    for (i64 x : ans) cout << x << '\n';
}
