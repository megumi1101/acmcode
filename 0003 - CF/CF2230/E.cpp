#include <bits/stdc++.h>
 
using namespace std;
 
#define ls (u << 1)
#define rs (u << 1 | 1)
const int inf = 1e9;
const int mxV = 1e6;
template<typename Info>
struct SegmentTree {
    int n;
    vector<Info> info;
    SegmentTree(int n_) {
        n = n_;
        info.assign(4 << __lg(n_), Info{});
    }
    void pull(int u) {
        info[u] = info[ls] + info[rs];
    }
    void modify(int u, int l, int r, int x, const Info &v) {
        if (r == l) {
            info[u] = info[u] + v;
            return;
        }
        int m = (l + r) >> 1;
        if (x <= m) {
            modify(ls, l, m, x, v);
        } else {
            modify(rs, m + 1, r, x, v);
        }
        pull(u);
    }
    void modify(int u, const Info &v) {
        modify(1, 1, n, u + 1, v);
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
        return query(l + 1, r + 1, 1, 1, n);
    }
};
struct Info {
    int mn;
    Info (int x = inf) {
        mn = x;
    }
};
 
Info operator+(const Info& x, const Info& y) {
    return {min(x.mn, y.mn)};
}
#undef ls
#undef rs
 
int get(int x, int t, int d) {
    if (x == inf) return inf;
    if (x < t) return 0;
    if (x >= t + d) return t + d;
    return x;
}
 
int ask(SegmentTree<Info> &seg, int l, int r) {
    l = max(l, 0);
    r = min(r, mxV);
    if (l > r) return inf;
    return seg.query(l, r).mn;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> p(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
 
    
    SegmentTree<Info> segp(1e6 + 5), segc(1e6 + 5), segpc(1e6 + 5);
    for (int i = 1; i <= n; i++) {
        segp.modify(p[i], c[i]);
        segc.modify(c[i], p[i]);
        segpc.modify(p[i], p[i] + c[i]);
    }
 
 
 
 
 
    int m;
    cin >> m;
    vector<int> tp(m + 1), tc(m + 1), d(m + 1);
    for (int i = 1; i <= m; i++) cin >> tp[i];
    for (int i = 1; i <= m; i++) cin >> tc[i];
    for (int i = 1; i <= m; i++) cin >> d[i];
 
    for (int i = 1; i <= m; i++) {
        int ans = inf;
        int x = tp[i];
        int y = tc[i];
        int xr = x + d[i];
        int yr = y + d[i];
 
        {
            int mny = ask(segp, 0, x - 1);
            ans = min(ans, get(mny, y, d[i]));
        }
 
        {
            int mny = ask(segp, xr, mxV);
            int t = get(mny, y, d[i]);
            if (t != inf) {
                ans = min(ans, xr + t);
            }
        }
 
        {
            int mnx = ask(segc, 0, y - 1);
            ans = min(ans, get(mnx, x, d[i]));
        }
 
        {
            int mnx = ask(segc, yr, mxV);
            int t = get(mnx, x, d[i]);
 
            if (t != inf) {
                ans = min(ans, yr + t);
            }
        }
 
        {
            int t = ask(segpc, x, xr - 1);
            ans = min(ans, t);
        }
        cout << ans << "\n";
    }
}
