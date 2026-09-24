#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
 
 
#define int long long
const int mod = 998244353, inf = 1e18;
vector<int> fac, facn, inv;
void init(int n) {
    fac.assign(n + 1, 0);
    facn.assign(n + 1, 0);
    inv.assign(n + 1, 0);
    fac[0] = fac[1] = facn[0] = facn[1] = inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
        facn[i] = facn[i - 1] * inv[i] % mod;
    }
}
 
int C (int i, int j) {
    return fac[i] * facn[j] % mod * facn[i - j] % mod;
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
    tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> tr;
    int n;
    cin >> n;
    vector<int> a(n + 1) , b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
 
 
    vector<int> nx(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (a[j] > a[i]) nx[i]++;
        }
    }
    
    vector<int> all;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            all.push_back(a[i] * b[j]);
        }
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    Fenwick<int> fen(all.size() + 5);
    vector t(n + 1, vector(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            t[i][j] = lower_bound(all.begin(), all.end(), a[i] * b[j]) - all.begin() + 1;
        }
    }
 
    int ans = 0;
    int siz = 0;
    for (int i = 1; i <= n; i++) {
        int res = 0;
        if (i >= 2) {
            for (int j = 1; j <= n; j++)
                res += siz - fen.sum(t[i][j]) - nx[i];
            res %= mod;
            // cerr << fac[n - 2] * res << "\n";
            ans += fac[n - 2] * res % mod;
            ans %= mod; 
        }
        
        for (int j = 1; j <= n; j++) {
            fen.add(t[i][j], 1);
        }
        siz += n;
    }
 
    ans = ans * facn[n] % mod;
    cout << ans << "\n";
 
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init(2005);
 
    int t;
    cin >> t;
    while (t--) sol();
}
