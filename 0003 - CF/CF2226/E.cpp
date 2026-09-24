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
    void build(int u, int l, int r, auto it) {
        if (l == r) {
            info[u] = *it;
            return;
        }
        int m = (l + r) >> 1;
        build(ls, l, m, it);
        build(rs, m + 1, r, it + m - l + 1);
        pull(u);
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
        modify(l + 1, r + 1, 1, 1, n, v);
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
        return query(l + 1, r + 1, 1, 1, n);
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
    int mn;
    Info (int x = 0) {
        mn = x;
    }
    void apply(const Tag &v) {
        mn += v.add;
    }
};
 
Info operator+(const Info& x, const Info& y) {
    return {min(x.mn, y.mn)};
}
 
void sol() {
    int n;
    cin >> n;
    int mex = 0;
 
    vector<int> a(n + 1);
    int V = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        V = max(V, a[i]);
    }
    
    vector<int> cnt(V + 5);
 
    SegmentTree<Info, Tag> seg(V + 5);
 
    for (int i = 1; i <= n; i++) {
        cnt[a[i]]++;
        if (a[i] < mex && cnt[a[i]] == 1) {
            seg.modify(0, a[i], 1);
        } else {
            seg.modify(0, (a[i] - 1) / 2, 1);
        }
 
        while (1) {
            if (cnt[mex]) {
                seg.modify(0, (mex - 1) / 2, -1);
            } else {
                seg.modify(0, mex, -1);
            }
            auto [res] = seg.query(0, mex);
            if (res >= 0) {
                mex++;
            } else {
                if (cnt[mex]) {
                    seg.modify(0, (mex - 1) / 2, 1);
                } else {
                    seg.modify(0, mex, 1);
                }
                break;
            }
        }
        cout << mex << " ";
    }
    cout << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
