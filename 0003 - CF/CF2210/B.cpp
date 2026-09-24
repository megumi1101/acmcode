#include <bits/stdc++.h>
 
using namespace std;
 
template <typename T>
struct Fenwick {
    int n;
    vector<T> a;
    
    Fenwick(int n_ = 0) {
        init(n_);
    }
    
    void init(int n_) {
        n = n_;
        a.assign(n + 5, T{});
    }
    
    void add(int x, const T &v) {
        for (int i = x; i <= n; i += i & -i) {
            a[i] = a[i] + v;
        }
    }
    
    T sum(int x) {
        T ans{};
        for (int i = x; i; i -= i & -i) {
            ans = ans + a[i];
        }
        return ans;
    }
    
    T getsum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    //查找满足前缀和 <= k 的最大位置
    int select(const T &k) {
        int x = 0;
        T cur{};
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i] <= k) {
                x += i;
                cur = cur + a[x];
            }
        }
        return x;
    }
};
 
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> d(n + 1), c(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] <= i) d[i] = 1;
        d[i] += d[i - 1];
    }
    
    Fenwick<int> fen(n);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i && a[i] > i) {
            fen.add(a[i], 1);
        }
        ans = max(ans, d[i] + fen.getsum(i + 1, n));
    }
    cout << ans << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
