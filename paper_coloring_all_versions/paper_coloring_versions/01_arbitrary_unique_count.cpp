// Version 1: operations L R, unique color=i; queries l r; count colors.
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
    for (int i = 1; i <= m; i++) cin >> op[i][0] >> op[i][1];
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

    vector<i64> remain(m + 1);
    auto split = [&](int x) {
        if (x > n) return seg.end();
        auto it = prev(seg.upper_bound(x));
        if (it->first == x) return it;
        auto [r, id] = it->second;
        it->second.r = x - 1;
        return seg.emplace(x, Node{r, id}).first;
    };

    for (int i = 1; i <= m; i++) {
        auto [L, R] = op[i];
        auto right = split(R + 1), left = split(L);
        for (auto it = left; it != right; ++it) {
            int id = it->second.id;
            if (!id) continue;
            remain[id] -= it->second.r - it->first + 1;
            if (remain[id] == 0) bit.add(id, -1);
        }
        seg.erase(left, right);
        seg.emplace(L, Node{R, i});
        remain[i] = R - L + 1;
        bit.add(i, 1);

        for (auto [l, id] : ask[i])
            ans[id] = bit.sum(i) - bit.sum(l - 1);
    }
    for (i64 x : ans) cout << x << '\n';
}

