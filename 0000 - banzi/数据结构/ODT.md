```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
// 使用 C++17，主函数写 signed main()。

// 普通 ODT：每个节点表示一段值相同的闭区间 [l, r]。
// 区间按左端点排序，操作耗时与覆盖的区间数量有关。
struct ODT {
    struct node {
        int l, r;
        mutable int v; // set 中的元素通常不能修改，mutable 允许直接修改段值。
        node(int l, int r = -1, int v = 0) : l(l), r(r), v(v) {}
        bool operator<(const node& o) const { return l < o.l; } // 只按左端点比较。
    };
    set<node> s;

    // 快速幂：b >= 0，p > 0，计算中的乘法需在 ll 范围内。
    int qpow(int a, int b, int p) {
        int ans = 1;
        a %= p;
        for (; b; b >>= 1, a = a * a % p)
            if (b & 1) ans = ans * a % p;
        return ans;
    }

    // 初始化：逐点 insert(i, i, a[i])，或插入若干连续且不重叠的段。
    // 所有段需完整覆盖 [1, n]；多组数据先调用 s.clear()。
    void insert(int l, int r, int v) { s.emplace(l, r, v); }

    // 将包含 p 的段 [l, r] 拆成 [l, p-1] 和 [p, r]，返回右段迭代器。
    // p 已是某段左端点时直接返回；调用位置应在 [1, n+1] 内。
    auto split(int p) {
        if (s.empty() || p > s.rbegin()->r) return s.end(); // p = n+1 时无需新增空段。
        auto it = s.lower_bound({p}); // 找第一个左端点 >= p 的段。
        if (it != s.end() && it->l == p) return it;
        --it; // 前一个段包含 p。
        int l = it->l, r = it->r, v = it->v;
        s.erase(it);
        s.emplace(l, p - 1, v);
        return s.emplace(p, r, v).first;
    }

    // 区间赋值：将 [l, r] 全部推平为 v。
    void assign(int l, int r, int v) {
        // 必须先 split(r+1)，否则后续分裂右端点可能使先取得的左端迭代器失效。
        auto ir = split(r + 1), il = split(l);
        s.erase(il, ir); // [il, ir) 恰好对应位置区间 [l, r]。
        s.emplace(l, r, v);
    }

    // 区间加：每个段的值整体增加 v，不改变段的左右端点。
    void add(int l, int r, int v) {
        auto ir = split(r + 1), il = split(l);
        for (auto it = il; it != ir; ++it) it->v += v;
    }

    // 查询 [l, r] 内第 k 小的值，k 从 1 开始。
    int kth(int l, int r, int k) {
        auto ir = split(r + 1), il = split(l);
        vector<pair<int, int>> a; // {段值, 段长度}，一段相当于 len 个相同的数。
        for (auto it = il; it != ir; ++it)
            a.push_back({it->v, it->r - it->l + 1});
        sort(a.begin(), a.end());
        for (auto [v, len] : a) {
            k -= len;
            if (k <= 0) return v;
        }
        return -1; // k 大于区间长度时返回 -1。
    }

    // 查询 [l, r] 的幂次和：sum(a[i]^x) % p。
    // 每段贡献为 len * v^x；要求 x >= 0、p > 0。
    int sum(int l, int r, int x, int p) {
        auto ir = split(r + 1), il = split(l);
        int ans = 0;
        for (auto it = il; it != ir; ++it)
            ans = (ans + (it->r - it->l + 1) * qpow(it->v, x, p)) % p;
        return ans;
    }
};

// 染色 ODT：区间染色后合并相邻同色段，并维护各颜色的连续段贡献。
// 贡献只统计同一连续段内的点对：每段 len * (len-1) / 2。
// 例如 [1,1,2,1,1,1] 中，颜色 1 的答案为 1 + 3 = 4。
struct ColorODT {
    struct node {
        int l, r, v; // [l, r] 的颜色为 v。
        node(int l, int r = -1, int v = 0) : l(l), r(r), v(v) {}
        bool operator<(const node& o) const { return l < o.l; }
    };
    set<node> s;
    map<int, int> ans; // ans[c]：颜色 c 的所有连续段贡献之和。

    int calc(int len) { return len * (len - 1) / 2; }

    // 清空旧数据，将整个 [1, n] 初始化为颜色 c。
    void init(int n, int c = 0) {
        s.clear();
        ans.clear();
        s.emplace(1, n, c);
        ans[c] = calc(n);
    }

    // 染色的内部辅助操作：分裂时同步扣除旧段贡献，加上两个新段贡献。
    // 单独 split 会拆开同色段；对外通过 assign 完成染色与重新合并。
    auto split(int p) {
        if (s.empty() || p > s.rbegin()->r) return s.end();
        auto it = s.lower_bound({p});
        if (it != s.end() && it->l == p) return it;
        --it;
        int l = it->l, r = it->r, v = it->v;
        ans[v] += calc(p - l) + calc(r - p + 1) - calc(r - l + 1);
        s.erase(it);
        s.emplace(l, p - 1, v);
        return s.emplace(p, r, v).first;
    }

    // 将 [l, r] 染成颜色 c；结束后每个节点都是一个极大的同色连续段。
    void assign(int l, int r, int c) {
        auto ir = split(r + 1), il = split(l); // 同样先分裂右端点。
        // 删除被覆盖的段之前，先从各自颜色的答案中扣除贡献。
        for (auto it = il; it != ir; ++it)
            ans[it->v] -= calc(it->r - it->l + 1);
        s.erase(il, ir); // ir 未被删除，仍指向右侧相邻段（或 end）。

        // 向左合并：扣除左段旧贡献，扩展新区间的左端点。
        if (ir != s.begin()) {
            auto it = prev(ir);
            if (it->v == c) {
                ans[c] -= calc(it->r - it->l + 1);
                l = it->l;
                s.erase(it);
            }
        }
        // 向右合并：扣除右段旧贡献，扩展新区间的右端点。
        if (ir != s.end() && ir->v == c) {
            ans[c] -= calc(ir->r - ir->l + 1);
            r = ir->r;
            s.erase(ir);
        }
        // 最后只插入一个合并后的段，并计入它的完整贡献。
        s.emplace(l, r, c);
        ans[c] += calc(r - l + 1);
    }

    // 查询颜色 c 的贡献之和；不存在的颜色返回 0。
    int query(int c) { return ans[c]; }
};
```
