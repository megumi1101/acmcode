// 前缀/后缀染色，颜色可以重复；查询操作子区间后的可见颜色数。
// 输入：n m q；m 行 o x c；q 行 l r。o=0 染 [1,x]，o=1 染 [x,n]。
// 时间 O((m + q) log m)，空间 O(m + q)。C++17。
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct Fenwick {
    int n;
    vector<int> tr;
    Fenwick(int size) : n(size), tr(size + 1) {}
    void add(int x, int v) {
        for (; x <= n; x += x & -x) tr[x] += v;
    }
    int sum(int x) const {
        int res = 0;
        for (; x; x -= x & -x) res += tr[x];
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;
    vector<int> L(m + 1), R(m + 1), color(m + 1);
    vector<i64> raw(m + 1), values;
    for (int i = 1; i <= m; i++) {
        int o, x;
        cin >> o >> x >> raw[i];
        L[i] = (o == 0 ? 1 : x);
        R[i] = (o == 0 ? x : n);
        values.push_back(raw[i]);
    }
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    for (int i = 1; i <= m; i++)
        color[i] = lower_bound(values.begin(), values.end(), raw[i]) - values.begin();

    vector<vector<pair<int, int>>> queries(m + 1);
    for (int id = 0; id < q; id++) {
        int l, r;
        cin >> l >> r;
        queries[r].push_back({l, id});
    }
    vector<int> ans(q);
    vector<i64> alive(m + 1); // 各操作目前剩余的格子总数。
    vector<vector<int>> stk(values.size());
    Fenwick bit(m);

    struct Node { int r, id; };
    map<int, Node> seg; // 左端点 -> {右端点，最后染色操作编号}。
    seg[1] = {n, 0};
    auto split = [&](int x) {
        if (x > n) return seg.end();
        auto it = prev(seg.upper_bound(x));
        if (it->first == x) return it;
        auto [r, id] = it->second;
        it->second.r = x - 1;
        return seg.emplace(x, Node{r, id}).first;
    };

    auto expire = [&](int id) {
        auto &s = stk[color[id]];
        int old = s.back();
        while (!s.empty() && alive[s.back()] == 0) s.pop_back();
        int now = s.empty() ? 0 : s.back();
        if (old != now) {
            bit.add(old, -1);
            if (now) bit.add(now, 1);
        }
    };

    for (int i = 1; i <= m; i++) {
        auto right = split(R[i] + 1), left = split(L[i]);
        for (auto it = left; it != right; ++it) {
            int id = it->second.id;
            if (!id) continue; // 空白不对应任何真实颜色。
            alive[id] -= i64(it->second.r) - it->first + 1;
            if (alive[id] == 0) expire(id);
        }
        seg.erase(left, right);
        seg[L[i]] = {R[i], i};

        alive[i] = i64(R[i]) - L[i] + 1;
        auto &s = stk[color[i]];
        if (!s.empty()) bit.add(s.back(), -1);
        s.push_back(i);
        bit.add(i, 1);

        for (auto [l, id] : queries[i])
            ans[id] = bit.sum(i) - bit.sum(l - 1);
    }
    for (int x : ans) cout << x << '\n';
}
