#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
const int mod = 998244353;
 
int norm(int x) {
    x %= mod;
    if (x < 0) x += mod;
    return x;
}
 
vector<int> fac, ifac, inv;
 
void init(int n) {
    fac.assign(n + 1, 1);
    ifac.assign(n + 1, 1);
    inv.assign(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
        ifac[i] = ifac[i - 1] * inv[i] % mod;
    }
}
 
int C(int n, int m) {
    if (n < 0 || m < 0 || n < m) return 0;
    return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}
 
#define ls (u << 1)
#define rs (u << 1 | 1)
 
template<typename Info>
struct SegmentTree {
    int n;
    vector<int> a;
    vector<Info> info;
 
    SegmentTree(int n_, vector<int> &v) {
        n = n_;
        a = v;
        info.assign(4 * n + 5, Info{});
        build(1, 1, n);
    }
 
    void pull(int u) {
        info[u] = info[ls] + info[rs];
    }
 
    void build(int u, int l, int r) {
        if (l == r) {
            info[u] = Info(a[l]);
            return;
        }
        int m = (l + r) >> 1;
        build(ls, l, m);
        build(rs, m + 1, r);
        pull(u);
    }
 
    void modify(int u, int l, int r, int x, const Info &v) {
        if (l == r) {
            info[u] = v;
            return;
        }
        int m = (l + r) >> 1;
        if (x <= m) modify(ls, l, m, x, v);
        else modify(rs, m + 1, r, x, v);
        pull(u);
    }
 
    void modify(int x, const Info &v) {
        modify(1, 1, n, x, v);
    }
 
    Info query(int L, int R, int u, int l, int r) {
        if (L <= l && r <= R) return info[u];
        int m = (l + r) >> 1;
        if (R <= m) return query(L, R, ls, l, m);
        if (L > m) return query(L, R, rs, m + 1, r);
        return query(L, R, ls, l, m) + query(L, R, rs, m + 1, r);
    }
 
    Info query(int l, int r) {
        return query(l, r, 1, 1, n);
    }
};
 
#undef ls
#undef rs
 
struct Info {
    int siz = 0;
 
    int real_A = 0;
    int real_K = 0;
 
    int sum_A = 0, sum_K = 0;
    int pre_sum_A = 0, pre_sum_K = 0;
    int pre2_sum_A = 0, pre2_sum_K = 0;
    int preAK_sum = 0;
 
    Info() {}
 
    Info(int x) {
        siz = 1;
        int A = 0, K = 0;
        if (x == -1) {
            K = 1;
        } else {
            A = norm(x);
        }
        real_A = (x == -1 ? 0 : x); 
        sum_A = pre_sum_A = A;
        pre2_sum_A = A * A % mod;
        
        real_K = (x == -1 ? 1 : 0);
        sum_K = pre_sum_K = K;        
        pre2_sum_K = K * K % mod;
 
        preAK_sum = A * K % mod;
    }
};
 
Info operator + (const Info &L, const Info &R) {
    Info res;
    res.siz = L.siz + R.siz;
    res.real_A = L.real_A + R.real_A;
    res.real_K = L.real_K + R.real_K;
 
    res.sum_A = (L.sum_A + R.sum_A) % mod;
    res.sum_K = (L.sum_K + R.sum_K) % mod;
 
    res.pre_sum_A = (L.pre_sum_A + R.pre_sum_A + L.sum_A * R.siz % mod) % mod;
    res.pre_sum_K = (L.pre_sum_K + R.pre_sum_K + L.sum_K * R.siz % mod) % mod;
 
    res.pre2_sum_A = (
        L.pre2_sum_A
        + R.pre2_sum_A
        + 2 * L.sum_A % mod * R.pre_sum_A % mod
        + L.sum_A * L.sum_A % mod * R.siz % mod
    ) % mod;
 
    res.pre2_sum_K = (
        L.pre2_sum_K
        + R.pre2_sum_K
        + 2 * L.sum_K % mod * R.pre_sum_K % mod
        + L.sum_K * L.sum_K % mod * R.siz % mod
    ) % mod;
 
    res.preAK_sum = (
        L.preAK_sum
        + R.preAK_sum
        + L.sum_A * R.pre_sum_K % mod
        + L.sum_K * R.pre_sum_A % mod
        + L.sum_A * L.sum_K % mod * R.siz % mod
    ) % mod;
 
    return res;
}
 
void sol() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
 
    SegmentTree<Info> seg(n, a);
 
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int p, v;
            cin >> p >> v;
            seg.modify(p, Info(v));
        } else {
            int l, r, m;
            cin >> l >> r >> m;
            Info res = seg.query(l, r);
 
            int N = m - res.real_A;
            int K = res.real_K;
            if (N < 0) {
                cout << 0 << '\n';
                continue;
            }
 
            int C0 = C(N + K - 1, K - 1);
            int C1 = C(N + K - 1, K);
            int C2 = C(N + K - 1, K + 1);
            if (K == 0 && N == 0) C0 = 1;
 
            int ans = 0;
            ans = (ans + C0 * res.pre2_sum_A) % mod;
            ans = (ans + 2 * C1 % mod * res.preAK_sum) % mod;
            ans = (ans + C2 * ((res.pre2_sum_K + res.pre_sum_K) % mod)) % mod;
            ans = (ans + C1 * res.pre_sum_K) % mod;
            cout << ans << '\n';
        }
    }
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    init(1300005);
 
    int t;
    cin >> t;
    while (t--) sol();
    return 0;
}
