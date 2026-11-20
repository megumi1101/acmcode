// 任意区间染色；每种颜色最多出现两次；询问操作区间内的连续色段平方和。
// 输入：n m q；m 行 L R c；q 行 l r。空白不计入答案。
// 时间 O((m + q) log m)，空间 O(m + q)。C++17。
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct Fenwick {
    int n;
    vector<i64> tr;
    Fenwick(int size) : n(size), tr(size + 1) {}
    void add(int x, i64 v) {
        for (; x <= n; x += x & -x) tr[x] += v;
    }
    i64 sum(int x) const {
        i64 res = 0;
        for (; x; x -= x & -x) res += tr[x];
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n;
    int m, q;
    cin >> n >> m >> q;
    vector<i64> L(m + 1), R(m + 1), raw(m + 1), values;
    for (int i = 1; i <= m; i++) {
        cin >> L[i] >> R[i] >> raw[i];
        values.push_back(raw[i]);
    }
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    vector<int> color(m + 1), pre(m + 1), last(values.size() + 1);
    for (int i = 1; i <= m; i++) {
        color[i] = lower_bound(values.begin(), values.end(), raw[i]) - values.begin() + 1;
        pre[i] = last[color[i]];
        last[color[i]] = i;
    }

    vector<vector<pair<int, int>>> ask(m + 1);
    for (int id = 0; id < q; id++) {
        int l, r;
        cin >> l >> r;
        ask[r].push_back({l, id});
    }
    vector<i64> ans(q);
    Fenwick bit(m);

    // 每个节点是一个真实同色段；tag 表示它采用的颜色版本。
    // tag 的第二次染色范围内属于 tag，范围外属于 pre[tag]。
    struct Node { i64 r; int tag; };
    map<i64, Node> seg;
    seg[1] = {n, 0};

    auto change = [&](auto it, int sign) {
        auto [l, node] = *it;
        auto [r, t] = node;
        if (!t) return; // 空白
        i64 len = r - l + 1;
        if (!pre[t]) {
            bit.add(t, sign * len * len);
        } else {
            i64 b = max(0LL, min(r, R[t]) - max(l, L[t]) + 1);
            bit.add(pre[t], sign * (len * len - b * b));
            bit.add(t, sign * b * b);
        }
    };

    auto split = [&](i64 x) {
        if (x > n) return seg.end();
        auto it = prev(seg.upper_bound(x));
        if (it->first == x) return it;
        Node node = it->second;
        change(it, -1);
        it->second.r = x - 1;
        change(it, 1);
        auto rt = seg.emplace(x, node).first;
        change(rt, 1);
        return rt;
    };

    auto join = [&](auto a, auto b) {
        change(a, -1);
        change(b, -1);
        a->second.r = b->second.r;
        a->second.tag = max(a->second.tag, b->second.tag);
        seg.erase(b);
        change(a, 1);
        return a;
    };

    for (int i = 1; i <= m; i++) {
        auto rt = split(R[i] + 1);
        auto it = split(L[i]);
        while (it != rt) {
            change(it, -1);
            it = seg.erase(it);
        }
        it = seg.emplace(L[i], Node{R[i], i}).first;
        change(it, 1);

        if (it != seg.begin()) {
            auto lt = prev(it);
            if (color[lt->second.tag] == color[i]) it = join(lt, it);
        }
        rt = next(it);
        if (rt != seg.end() && color[rt->second.tag] == color[i]) join(it, rt);

        for (auto [l, id] : ask[i]) ans[id] = bit.sum(i) - bit.sum(l - 1);
    }
    for (i64 x : ans) cout << x << '\n';
}
