#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
const int inf = 1e18;
#define ls (u << 1)
#define rs (u << 1 | 1)
template<typename Info>
struct SegmentTree {
    int n;
    vector<Info> info;
    vector<int> a;
    SegmentTree(int n_, vector<int> &a_) {
        n = n_;
        a = a_;
        info.assign(4 << __lg(n_), Info{});
        build(1, 1, n);
    }
    void pull(int u) {
        info[u] = info[ls] + info[rs];
    }
    void build(int u, int l, int r) {
        if (l == r) {
            info[u] = {a[l], l};
            return;
        }
        int m = (l + r) >> 1;
        build(ls, l, m);
        build(rs, m + 1, r);
        pull(u);
    }
    Info query(int L, int R, int u, int l, int r) {
        if (L <= l && r <= R) {
            return info[u];
        }
        int m = (l + r) >> 1;
        if (R <= m) {
            return query(L, R, ls, l, m);
        } else if (L > m) {
            return query(L, R, rs, m + 1, r);
        } else {
            return query(L, R, ls, l, m) + query(L, R, rs, m + 1, r);
        }
    }
    Info query(int l, int r) {
        assert(l <= r);
        return query(l, r, 1, 1, n);
    }
    
};
#undef ls
#undef rs
struct Info {
    int mx, mxpos;
    Info (int x = -inf) {
        mx = x;
        mxpos = -1;
    }
    Info (int x, int y) {
        mx = x;
        mxpos = y;
    }
};
 
Info operator+(const Info& x, const Info& y) {
    if (x.mx > y.mx) return {x.mx, x.mxpos};
    else return {y.mx, y.mxpos};
}
 
void sol() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1), sum(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    SegmentTree<Info> seg(n, a);
    
    int ans = 0;
    auto get =[&] (auto&&get, int l, int r, int up) -> void {
        if (l <= r && l >= 1 && r <= n) {
            if (sum[r] - sum[l - 1] < up) return;
            auto[mx, pos] = seg.query(l, r);
            ans++;
            get(get, l, pos - 1, mx);
            get(get, pos + 1, r, mx);
        }
    };
    get(get, 1, n, 0);
    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
