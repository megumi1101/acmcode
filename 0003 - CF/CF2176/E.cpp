#include <bits/stdc++.h>
 
using namespace std;
 
 
#define int long long
const int inf = 1e9 + 10;
 
 
 
#define ls (u << 1)
#define rs (u << 1 | 1)
template<typename Info, typename Tag>
struct SegmentTree {
    int n;
    vector<Info> info;
    vector<Tag> tag;
    SegmentTree(int n_) {
        n = n_;
        info.assign(4 << __lg(n), Info{});
        tag.assign(4 << __lg(n), Tag{});
        build(1, 1, n);
    }
    void pull(int u) {
        info[u] = info[ls] + info[rs];
    }
    void apply(int u, const Tag& v) {
        info[u].apply(v);
        tag[u].apply(v);
    }
    void push(int u) {
        apply(ls, tag[u]), apply(rs, tag[u]);
        tag[u] = Tag{};
    }
    void build(int u, int l, int r) {
        if (l == r) {
            return;
        }
        int m = (l + r) >> 1;
        build(ls, l, m);
        build(rs, m + 1, r);
        pull(u);
    }
    void modify(int L, int R, int u, int l, int r, const Tag& v) {
        if (L <= l && r <= R  && v.add > info[u].mx2) {
            apply(u, v);
            return;
        }
        int m = (l + r) >> 1;
        push(u);
        if (L <= m) modify(L, R, ls, l, m, v);
        if (R > m) modify(L, R, rs, m + 1, r, v);
        pull(u);
    }
 
    void modify(int l, int r, const Tag& v) {
        assert(l <= r);
        modify(l, r, 1, 1, n, v);
    }
 
    Info query(int L, int R, int u, int l, int r) {
        if (L <= l && r <= R) {
            return info[u];
        }
        push(u);
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
constexpr int Mod = 998244353;
 
struct Tag {
    int add; 
    Tag(int x = inf) : add(x) {}
    void apply(const Tag &v) {
        add = min(add, v.add);
    }
};
 
struct Info {
    int sum;
    int mx1, mx2; 
    int cnt;            
    int siz;
 
    Info(int x = inf) {
        sum = x;
        mx1 = x;
        mx2 = -inf;
        cnt = 1;
        siz = 1;
    }
    Info(int _sum, int _siz, int _mx1, int _mx2, int _cnt) {
        sum = _sum; siz = _siz; mx1 = _mx1; mx2 = _mx2; cnt = _cnt;
    }
 
    friend Info operator + (const Info &L, const Info &R) {
        Info o;
        o.siz = L.siz + R.siz;
        o.sum = L.sum + R.sum;
 
        if (L.mx1 > R.mx1) {
            o.mx1 = L.mx1;
            o.cnt = L.cnt;
            o.mx2 = max(L.mx2, R.mx1);
        } else if (L.mx1 < R.mx1) {
            o.mx1 = R.mx1;
            o.cnt = R.cnt;
            o.mx2 = max(R.mx2, L.mx1);
        } else {
            o.mx1 = L.mx1;
            o.cnt = L.cnt + R.cnt;
            o.mx2 = max(L.mx2, R.mx2);
        }
        return o;
    }
 
    void apply(const Tag &v) {
        if (v.add >= mx1) return;
        sum -= (mx1 - v.add) * 1LL * cnt;
        mx1 = v.add;
    }
};
 
 
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 5), c(n + 5), p(n + 5);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) cin >> p[i];
 
    a[0] = inf; a[n + 1] = inf;
    vector<int> st, l(n + 5), r(n + 5);
    for (int i = 0; i <= n; i++) {
        while (!st.empty() && a[st.back()] <= a[i]) st.pop_back();
        if (!st.empty()) l[i] = st.back() + 1;
        st.push_back(i);
    }
 
    st.clear();
    for (int i = n + 1; i >= 1; i--) {
        while (!st.empty() && a[st.back()] <= a[i]) st.pop_back();
        if (!st.empty()) r[i] = st.back() - 1;
        st.push_back(i);
    }
    
    SegmentTree<Info, Tag> seg(n);
 
    for (int i = 1; i <= n; i++) {
        seg.modify(l[i], r[i], Tag(c[i]));
    
    }
    
    auto[sum, mx, _, __, ___] = seg.query(1, n);
    cout << sum - mx << " ";
 
    for (int i = 1; i <= n; i++) {
        seg.modify(l[p[i]], r[p[i]], Tag(0));
        auto[sum, mx, _, __, ___] = seg.query(1, n);
        cout << sum - mx << " ";
    }
    cout << "\n";
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
 
    int T;
    cin >> T;
    while (T--) {
        sol();
    }
    
}
