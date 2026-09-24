```cpp
struct SegSet {
    set<pair<int, int>> S;
    long long sum = 0;

    long long calc(long long len) {
        return len * (len + 1) / 2;
    }

    void add(int x) {
        auto it = S.upper_bound({x, 2e9});
        // 1. 如果 x 已经被左边的区间包含，直接返回
        if (it != S.begin() && prev(it)->second >= x) return;

        int l = x, r = x;

        // 2. 检查能否合并右侧 (刚好以 x+1 开头的区间)
        it = S.lower_bound({x + 1, 0});
        if (it != S.end() && it->first == x + 1) {
            r = it->second;
            sum -= calc(r - it->first + 1);
            S.erase(it);
        }

        // 3. 检查能否合并左侧 (刚好以 x-1 结尾的区间)
        it = S.upper_bound({x, 2e9});
        if (it != S.begin() && prev(it)->second == x - 1) {
            auto p = prev(it);
            l = p->first;
            sum -= calc(p->second - p->first + 1);
            S.erase(p);
        }

        // 4. 插入最终合并的区间
        S.insert({l, r});
        sum += calc(r - l + 1);
    }

    void del(int x) { 
        auto it = S.upper_bound({x, 2e9});
        if (it == S.begin()) return; 
        
        --it; // 退回到 x 可能在的区间
        if (it->second < x) return; // x 根本没被包含

        int l = it->first, r = it->second;
        sum -= calc(r - l + 1);
        S.erase(it);

        // 分裂区间（化简了长度计算式，手打极其清爽）
        if (l < x) {
            S.insert({l, x - 1});
            sum += calc(x - l); // 原本是 (x-1) - l + 1，化简后就是 x - l
        }
        if (r > x) {
            S.insert({x + 1, r});
            sum += calc(r - x); // 原本是 r - (x+1) + 1，化简后就是 r - x
        }
    }
};
```