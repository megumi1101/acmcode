#include <bits/stdc++.h>
 
using namespace std;
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
 
void sol() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), len_cnt(n + 1, 0);
    vector<set<int>> s(n + 1);
    vector<SegSet> s2(n + 1);
    set<int> valid_lens;
 
    auto del_val = [&](int v) {
        if (s[v].empty()) return;
        int len = *s[v].rbegin() - *s[v].begin();
        int st = *s[v].begin();
        if (--len_cnt[len] == 0) {
            valid_lens.erase(len);
        }
        s2[len].del(st);
    };
 
    auto add_val = [&](int v) {
        if (s[v].empty()) return;
        int len = *s[v].rbegin() - *s[v].begin();
        int st = *s[v].begin();
        if (len_cnt[len]++ == 0) {
            valid_lens.insert(len);
        }
        s2[len].add(st);
    };
 
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[a[i]].insert(i);
    }
 
    for (int i = 1; i <= n; i++) {
        add_val(i);
    }
 
    while (q--) {
        int i, x;
        cin >> i >> x;
        
        if (a[i] != x) {
            del_val(a[i]);
            del_val(x);
            s[a[i]].erase(i); 
            s[x].insert(i);
            add_val(a[i]);
            add_val(x);
            a[i] = x;
        }
 
        int k = valid_lens.empty() ? 0 : *valid_lens.rbegin();
        long long cnt = (k == 0) ? 0 : s2[k].sum;
        cout << k << " " << cnt << "\n";
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
