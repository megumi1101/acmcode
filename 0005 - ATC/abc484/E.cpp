#include <bits/stdc++.h>

using namespace std;

#define int long long

#define debug(x) cerr << #x << " == " << x << "\n"; 
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
        x++;
        for (int i = x; i <= n; i += i & -i) {
            a[i] = a[i] + v;
        }
    }
    
    T sum(int x) {
        x++;
        T ans{};
        for (int i = x; i; i -= i & -i) {
            ans = ans + a[i];
        }
        return ans;
    }
    
    T getsum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, L, R;
    cin >> n >> L >> R;
    
    Fenwick<int> fen(n + 5);
    vector<int> pre(n + 1);
    vector<pair<int, int>> np(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pre[i] = pre[i - 1] + x;
        np[i] = {pre[i], i};
    }

    sort(np.begin(), np.end());
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (i) {
            int posL = lower_bound(np.begin(), np.end(), pair<int, int>{pre[i] - R, 0}) - np.begin(); 
            int posR = lower_bound(np.begin(), np.end(), pair<int, int>{pre[i] - L, (int)1e9}) - np.begin() - 1;
            if (posL <= posR) ans += fen.getsum(posL, posR); 
        }

        int pos = lower_bound(np.begin(), np.end(), pair<int, int>{pre[i], i}) - np.begin();
        fen.add(pos, 1);
    }
    cout << ans << "\n";
}

/*
5 -2 3
3 -1 -4 -1 5

*/