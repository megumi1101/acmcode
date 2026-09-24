// QOJ user: xbbbz
// Contest: 2022 �?7届ICPC南京�?// Problem: #5417. Chat Program (5417)
// Submission: https://qoj.ac/submission/1518039
// Language: C++23

#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
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
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i];
        }
        return ans;
    }
    
    T getsum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    //查找满足前缀�?<= k 的最大位�?    int select(const T &k) {
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
        int n, k, m, C, D;
        cin >> n >> k >> m >> C >> D;
        vector<int> a(n);
        for (auto &i : a) cin >> i;
        vector<int> c(n);
        for (int i = 0; i < n; i++) c[i] = a[i] + D * i + C;
        auto all = c;
        sort (all.begin(), all.end());
        all.erase(unique(all.begin(), all.end()), all.end());
        for (auto &x : c) x = (lower_bound(all.begin(), all.end(), x) - all.begin()) + 1;

        Fenwick<int> fen(n);
        
        auto isok = [&](int mid) -> bool {
            fen.init(n);
            int cnt = 0;
            for (int i = n - 1; i >= m; i--) if (a[i] >= mid) cnt++;
            for (int i = 0; i < m; i++) fen.add(c[i], 1);
            int x = (lower_bound(all.begin(), all.end(), mid) - all.begin());
            int rk = fen.sum(x);
            int mx = cnt + m - rk;
            // tr.insert({c[i], i});
            // auto it = tr.upper_bound({mid, -1});
            // int rk;
            // if (it == tr.end()) rk = m; 
            // else rk = tr.order_of_key(*it);
            // int mx = cnt + m - rk;
            for (int i = m; i < n; i++) {
                int res = mid + (i - m + 1) * D;
                fen.add(c[i], 1);
                fen.add(c[i - m], -1);
                // tr.erase({c[i - m], i - m});
                // tr.insert({c[i], i});
                if (a[i - m] >= mid) cnt++;
                if (a[i] >= mid) cnt--;
                x = (lower_bound(all.begin(), all.end(), res) - all.begin());
                rk = fen.sum(x);
                mx = max(mx, cnt + m - rk);
            }
            return mx >= k;
        };

        int l = 0, r = 1e15;
        int ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (isok(mid)) ans = mid, l = mid + 1;
            else r = mid - 1;
        }

        cout << ans << "\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
#undef int
}

int main() {
    return Xbbbz::main(), 0;
}
</code>