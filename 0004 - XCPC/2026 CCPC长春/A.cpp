#include <bits/stdc++.h>

using namespace std;

#define int long long

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
};


signed main() {
    int n, m;
    cin >> n >> m;

    vector a(n + 1, vector(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    Fenwick<int> f(n);
    int ans = 0;
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            if (a[i][j] == 0) continue;
            int s = f.sum(i);
            if (a[i][j] <= s) {
                f.add(i, -a[i][j]);
            } else {
                f.add(i, -s);
                ans += a[i][j] - s;
            }
        }

        f.init(n);
        for (int i = 1; i <= n; i++) {
            f.add(i, a[i][j]);
        }
    }

    cout << ans << "\n";
}

/*

*/