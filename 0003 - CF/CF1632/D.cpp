#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
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
 
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }
 
    void sol() {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        ST<int, gcd> st(a);
        int lst = 0;
        vector<int> ans(n + 1);
        for (int i = 1; i <= n; i++) {
            int l = lst + 1;
            int r = i;
            int res = 0;
            while (l <= r) {
                int mid = (l + r) >> 1;
                int x = st.query(mid, i);
                if (x > i - mid + 1) r = mid - 1;
                else if (x < i - mid + 1) l = mid + 1;
                else {
                    res = 1;break;
                }
            }
            if (res) {
                lst = i;
            }
            ans[i] = ans[i - 1] + (res & 1);
        }
        for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
}
 
int main() {
    return Xbbbz :: main(), 0;
}
