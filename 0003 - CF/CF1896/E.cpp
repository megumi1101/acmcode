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
    vector<int> a(2 * n + 1), lst(2 * n + 1);
    vector<int> to(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
        to[i] = (i <= a[i]) ? a[i] : a[i] + n;
        // cerr << i << ": " << to[i] << "\n";
        lst[to[i]] = i;
        if (to[i] <= n) lst[to[i] + n] = a[i] + n;
    }
    Fenwick<int> fen(2 * n);
    for (int i = 1; i <= 2 * n; i++) {
        if (lst[i]) fen.add(i, 1);
    }
    
    
    // for (int i = 1; i <= 2 * n; i++) {
    //     cerr << i << ": " << lst[i] << "\n";
    // }
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        fen.add(to[i], -1);
        ans[(to[i] - 1) % n + 1] = to[i] - i - fen.sum(to[i] - 1);
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}
 
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
 
    int T = 1;
    cin >> T;
    while (T--) sol();
}
