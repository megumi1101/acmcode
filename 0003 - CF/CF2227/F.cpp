#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
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
    void modify(int L, int R, int u, int l, int r, const Tag& v) {
        if (L <= l && r <= R) {
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
 
struct Tag {
    int add;
    Tag (int x = 0) {
        add = x;
    }
    void apply(const Tag &v) {
        add += v.add;
    }
};
 
struct Info {
    int sum, siz;
    Info (int x = 0) {
        sum = x; siz = 1;
    }
    Info (int x, int y) {
        sum = x; siz = y;
    }
    void apply(const Tag &v) {
        sum += siz * v.add;
    }
};
 
Info operator+(const Info& x, const Info& y) {
    return {x.sum + y.sum, x.siz + y.siz};
}
 
void sol() {
    int n;
    cin >> n;
    
    vector<int> a(n + 5, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    auto b = a;
    
    b[n + 1] = n + 5;
    for (int i = n; i >= 1; i--) {
        b[i] = min(b[i], b[i + 1]);
    }
 
    SegmentTree<Info, Tag> segcnt(n + 5), segx(n + 5), seg(n + 5);
 
    int now = 1;
    int sum = 0;
    int res = 0;
    for (int i = 1; i <= n + 1; i++) {
        if (i != n + 1) {
            res = max(res, seg.query(b[i], b[i]).sum);
        }
        if (b[i] < a[i]) {
            segcnt.modify(b[i] + 1, a[i], 1);
            segx.modify(b[i] + 1, a[i], i);
        }
 
        while (now <= b[i] && now <= n) {
            int s0 = segcnt.query(now, now).sum;
            int s1 = segx.query(now, now).sum;
            sum += s0 * (i - 1 + i - s0) / 2 - s1;
            now++;
        }
 
        if (i != n + 1) seg.modify(1, a[i], 1);
    }
 
    // cerr << sum << "\n";
    cout << sum + res << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
 
/*
6
0 0
3 0
6 0
6 3
6 6
1 1
*/
