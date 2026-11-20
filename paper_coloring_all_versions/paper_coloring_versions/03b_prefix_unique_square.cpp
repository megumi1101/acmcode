// Prefix/suffix version: operations o x; queries l r; squared run lengths.
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

struct Node { int r, id; };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;
    vector<array<int, 2>> op(m + 1);
    for (int i = 1; i <= m; i++) {
        int o, x;
        cin >> o >> x;
        op[i] = (o == 0 ? array<int, 2>{1, x} : array<int, 2>{x, n});
    }
    vector<vector<pair<int, int>>> ask(m + 1);
    for (int id = 0; id < q; id++) {
        int l, r;
        cin >> l >> r;
        ask[r].push_back({l, id});
    }
    vector<i64> ans(q);
    Fenwick bit(m);
    map<int, Node> seg;
    seg[1] = {n, 0};  // owner=0: blank

    auto split = [&](int x) {
        if (x > n) return seg.end();
        auto it = prev(seg.upper_bound(x));
        if (it->first == x) return it;
        auto [r, id] = it->second;
        i64 a = x - it->first, b = r - x + 1;
        if (id) bit.add(id, -2 * a * b);  // a^2+b^2-(a+b)^2
        it->second.r = x - 1;
        return seg.emplace(x, Node{r, id}).first;
    };

    for (int i = 1; i <= m; i++) {
        auto [L, R] = op[i];
        auto right = split(R + 1), left = split(L);
        for (auto it = left; it != right; ++it) {
            int id = it->second.id;
            i64 len = it->second.r - it->first + 1;
            if (id) bit.add(id, -len * len);
        }
        seg.erase(left, right);
        seg.emplace(L, Node{R, i});
        i64 len = R - L + 1;
        bit.add(i, len * len);

        for (auto [l, id] : ask[i])
            ans[id] = bit.sum(i) - bit.sum(l - 1);
    }
    for (i64 x : ans) cout << x << '\n';
}

