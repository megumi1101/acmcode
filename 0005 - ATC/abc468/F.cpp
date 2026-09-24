#include <bits/stdc++.h>

using namespace std;

#define int long long

map<int, int> mp;

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
            a[i] = max(a[i], v);
        }
    }
    
    T sum(int x) {
        T ans{};
        for (int i = x; i; i -= i & -i) {
            ans = max(ans, a[i]);
        }
        return ans;
    }
};

signed main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int ans = 1;
    int mx = a[1];
    int t = 0;
    Fenwick<int> fen(n);
    for (int i = 2; i <= n; i++) {
        if (a[i] < mx) {
            int x = fen.sum(a[i] - 1);
            t = max(x + 1, t);
            fen.add(a[i], x + 1);
        } else {
            ans++;
            mx = a[i];
        }
    }
    
    cout << ans + t << "\n";
}