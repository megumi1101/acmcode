```cpp
struct ChthollyTree {
    struct Node {
        int l, r;
        mutable long long v;
        Node(int l, int r = -1, long long v = 0) : l(l), r(r), v(v) {}
        bool operator<(const Node& o) const {
            return l < o.l;
        }
    };

    set<Node> odt;

    // 内部使用的快速幂辅助函数
    long long qpow(long long base, long long exp, long long mod) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return res;
    }

    // 提供给外部的初始化接口
    void insert(int l, int r, long long v) {
        odt.insert(Node(l, r, v));
    }

    // --- 核心操作：分裂 ---
    auto split(int pos) {
        auto it = odt.lower_bound(Node(pos));
        if (it != odt.end() && it->l == pos) return it;
        --it;
        int l = it->l, r = it->r;
        long long v = it->v;
        odt.erase(it);
        odt.insert(Node(l, pos - 1, v));
        return odt.insert(Node(pos, r, v)).first;
    }

    // --- 核心操作：推平 ---
    void assign(int l, int r, long long v) {
        auto itr = split(r + 1);
        auto itl = split(l);
        odt.erase(itl, itr);
        odt.insert(Node(l, r, v));
    }

    // --- 业务操作 1：区间加法 ---
    void add(int l, int r, long long val) {
        auto itr = split(r + 1);
        auto itl = split(l);
        for (auto it = itl; it != itr; ++it) {
            it->v += val;
        }
    }

    // --- 业务操作 2：区间第 K 小 ---
    long long kth(int l, int r, int k) {
        auto itr = split(r + 1);
        auto itl = split(l);
        vector<pair<long long, int>> vec;
        for (auto it = itl; it != itr; ++it) {
            vec.push_back({it->v, it->r - it->l + 1});
        }
        sort(vec.begin(), vec.end());
        for (auto p : vec) {
            k -= p.second;
            if (k <= 0) return p.first;
        }
        return -1LL;
    }

    // --- 业务操作 3：区间幂次和 ---
    long long sum_of_power(int l, int r, long long x, long long y) {
        auto itr = split(r + 1);
        auto itl = split(l);
        long long res = 0;
        for (auto it = itl; it != itr; ++it) {
            long long len = it->r - it->l + 1;
            long long val = qpow(it->v, x, y);
            res = (res + len * val) % y;
        }
        return res;
    }
};

#include <iostream>
#include <set>
#include <map>

struct ColorODT {
    struct Node {
        int l, r;
        mutable int v; 
        Node(int l, int r = -1, int v = 0) : l(l), r(r), v(v) {}
        bool operator<(const Node& o) const {
            return l < o.l;
        }
    };

    std::set<Node> odt;
    std::map<int, long long> color_ans; // 存储每种颜色对应的 len*(len-1)/2 之和

    // 计算单个连续区间的贡献
    inline long long calc(long long len) {
        return len * (len - 1) / 2;
    }

    // 初始化：将整个序列 [1, n] 设为 default_color
    void init(int n, int default_color = 0) {
        odt.insert(Node(1, n, default_color));
        color_ans[default_color] = calc(n);
    }

    auto split(int pos) {
        auto it = odt.lower_bound(Node(pos));
        if (it != odt.end() && it->l == pos) return it;
        --it;
        int l = it->l, r = it->r, v = it->v;
        
        // 【关键改动 1】：物理切开区间时，同时更新数学贡献
        color_ans[v] -= calc(r - l + 1);
        color_ans[v] += calc(pos - l);
        color_ans[v] += calc(r - pos + 1);
        
        odt.erase(it);
        odt.insert(Node(l, pos - 1, v));
        return odt.insert(Node(pos, r, v)).first;
    }

    void assign(int l, int r, int color) {
        auto itr = split(r + 1);
        auto itl = split(l);

        // 减去即将被覆盖的旧区间的贡献
        for (auto it = itl; it != itr; ++it) {
            color_ans[it->v] -= calc(it->r - it->l + 1);
        }
        
        // std::set 的 erase 返回的是被删区间之后的那个迭代器（即原本的 itr）
        auto next_it = odt.erase(itl, itr); 

        // 【关键改动 2】：向左合并相邻的同色区间
        if (next_it != odt.begin()) {
            auto prev_it = prev(next_it);
            if (prev_it->v == color) {
                l = prev_it->l; // 扩张左端点
                color_ans[color] -= calc(prev_it->r - prev_it->l + 1); // 扣除旧贡献
                odt.erase(prev_it); // 删掉左边的节点
            }
        }

        // 【关键改动 3】：向右合并相邻的同色区间
        // 注意：前面的 erase 操作不会让 next_it 失效
        if (next_it != odt.end() && next_it->v == color) {
            r = next_it->r; // 扩张右端点
            color_ans[color] -= calc(next_it->r - next_it->l + 1); // 扣除旧贡献
            odt.erase(next_it); // 删掉右边的节点
        }

        // 插入最终合并出来的超大区间，并加上新贡献
        odt.insert(Node(l, r, color));
        color_ans[color] += calc(r - l + 1);
    }

    // O(1) 或 O(log C) 的查询
    long long query(int color) {
        return color_ans[color];
    }
};
```