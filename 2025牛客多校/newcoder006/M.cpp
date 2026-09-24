#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

pair<long long, long long> get_max_min(const vector<int>& g, int m) {
    int t = g.size();
    if (t == 0) return {0, 0};
    
    vector<long long> pow_m(t);
    pow_m[0] = 1;
    for (int i = 1; i < t; ++i) {
        pow_m[i] = (pow_m[i-1] * m) % MOD;
    }
    
    // 计算最大数：降序排列，第i个元素乘m^(t-1 - i)
    vector<int> temp = g;
    sort(temp.rbegin(), temp.rend());
    long long max_val = 0;
    for (int i = 0; i < t; ++i) {
        max_val = (max_val + 1LL * temp[i] * pow_m[t-1 - i]) % MOD;
    }
    
    // 计算最小数：升序排列，第i个元素乘m^(t-1 - i)
    sort(temp.begin(), temp.end());
    long long min_val = 0;
    for (int i = 0; i < t; ++i) {
        min_val = (min_val + 1LL * temp[i] * pow_m[t-1 - i]) % MOD;
    }
    
    return {max_val, min_val};
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        sort(a.begin(), a.end());
        
        vector<pair<vector<int>, vector<int>>> groups;
        if (n % 2 == 0) {
            vector<int> g1, g2;
            for (int i = 0; i < n; ++i) {
                if (i % 2 == 0) g1.push_back(a[i]);
                else g2.push_back(a[i]);
            }
            groups.emplace_back(g1, g2);
        } else {
            // 分法1: 多的元素给g1（索引0,2,4...）
            vector<int> g1, g2;
            for (int i = 0; i < n; ++i) {
                if (i % 2 == 0) g1.push_back(a[i]);
                else g2.push_back(a[i]);
            }
            groups.emplace_back(g1, g2);
            
            // 分法2: 多的元素给g2（索引1,3,5...）
            g1.clear(); g2.clear();
            for (int i = 0; i < n; ++i) {
                if (i % 2 == 1) g1.push_back(a[i]);
                else g2.push_back(a[i]);
            }
            groups.emplace_back(g1, g2);
        }
        
        long long ans = LLONG_MAX;
        for (auto& [g1, g2] : groups) {
            auto [g1_max, g1_min] = get_max_min(g1, m);
            auto [g2_max, g2_min] = get_max_min(g2, m);
            
            long long diff1 = abs(g1_max - g2_min);
            long long diff2 = abs(g1_min - g2_max);
            long long current_min = min(diff1, diff2) % MOD;
            
            ans = min(ans, current_min);
        }
        
        printf("%lld\n", ans % MOD);
    }
    return 0;
}