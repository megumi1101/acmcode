#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int mod = 998244353;
 
 
int fap(int a, int b) {
    a %= mod;
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        b /= 2;
        a = a * a % mod;
    }
    return res;
}
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
 
    int select(const T &k) {
        int x = 0;
        T cur{};
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i] < k) {
                x += i;
                cur = cur + a[x];
            }
        }
        return x + 1;
    }
};
void sol() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    auto all = a;
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
 
    auto p = a;
    for (int &x : p) {
        x = lower_bound(all.begin(), all.end(), x) - all.begin() + 1;
    }
    Fenwick<int> fen(n + 5);
    Fenwick<int> fen2(n + 5);
    int tsum = 0;
 
    auto get = [&](int k, int sz) -> pair<int, int> {
        int R = 0, L = 0;
        
        if (k + 1 <= sz) {
            int pos = fen2.select(k + 1);
            int val = all[pos - 1];
            int sum = tsum - fen.sum(pos);
            int cnt = sz - (k + 1);
            R = sum - cnt * val;
        }
        
        if (k - 1 >= 1) {
            int pos = fen2.select(k - 1);
            int val = all[pos - 1];
            int sum = fen.sum(pos - 1);
            int cnt = k - 2;
            L = cnt * val - sum;
        }
        return {L, R}; 
    };
    for (int i = 0; i < n; i++) {
        fen.add(p[i], a[i]);
        fen2.add(p[i], 1);
        tsum += a[i];
        if (i < 2) continue;
        int r = i + 1;
        int l = 1;
        int ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            auto[L, R] = get(mid, i + 1);
            if (L >= R) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
 
        auto [L1, R1] = get(ans, i + 1);
        int res = max(R1, L1);
        if (ans > 1) {
            auto [L2, R2] = get(ans - 1, i + 1);
            res = min(res, max(R2, L2));
        }
 
        res = (res % mod) * fap(i - 1, mod - 2) % mod;
        cout << res << "\n";
    }
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) sol();
}
