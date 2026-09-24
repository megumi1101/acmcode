#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
template <typename T, T (*comp)(T, T) = nullptr>
struct ST {
    vector<vector<T>> t;
    vector<int> lg;
 
    ST() {}
    
    ST(const vector<T>& data) {
        build(data);
    }
    
    void build(const vector<T>& data) {
        int n = data.size() - 1;  // 因为数据从1开始，size()包含0位置
        int logn = log2(n) + 1;
        t.assign(n + 1, vector<T>(logn));  // 调整为n+1
        
        // 从1开始填充数据
        for (int i = 1; i <= n; ++i) {
            t[i][0] = data[i];
        }
        
        for (int j = 1; (1 << j) <= n; ++j) {
            for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
                if constexpr (comp == nullptr) {
                    t[i][j] = min(t[i][j-1], t[i + (1 << (j-1))][j-1]);
                } else {
                    t[i][j] = comp(t[i][j-1], t[i + (1 << (j-1))][j-1]);
                }
            }
        }
        
        lg.resize(n + 2);  // 调整为n+2
        lg[0] = lg[1] = 0;
        for (int i = 2; i <= n + 1; ++i) {
            lg[i] = lg[i/2] + 1;
        }
    }
 
    T query(int l, int r) {
        int k = lg[r - l + 1];
        if constexpr (comp == nullptr) {
            return min(t[l][k], t[r - (1 << k) + 1][k]);
        } else {
            return comp(t[l][k], t[r - (1 << k) + 1][k]);
        }
    }
};
 
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1), d(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[i] = abs(a[i] - a[i - 1]);
    }
    
    vector<int> R(n + 1);
    ST<int, gcd> st(d);
    int r = 0;
    for (int i = 1; i <= n; i++) {
        r = max(i + 1, r);
        while (1 && r <= n) {
            int x = st.query(i + 1, r);
            if (x > 0 && (x & -x) == x) break;
            r++;
        }
        R[i] = r - 1;
    }
 
    int res = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == a[i - 1]) res++;
        else {
            ans += res * (res + 1) / 2;
            res = 1;
        }
    }
    ans += res * (res + 1) / 2;
 
    ans += n * (n + 1) / 2;
    for (int i = 1; i <= n; i++) {
        ans -= R[i] - i + 1;
    }
    cout << ans << "\n";
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
