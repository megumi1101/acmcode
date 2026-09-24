#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
#define ls (u << 1)
#define rs (u << 1 | 1)
    template<typename Info, typename Tag>
    struct SegmentTree {
        int n;
        vector<Info> info;
        vector<Tag> tag;
        SegmentTree(auto l, auto r) {
            n = r - l;
            info.assign(4 << __lg(n), Info{});
            tag.assign(4 << __lg(n), Tag{});
            build(1, 1, n, l);
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

    constexpr int Mod = 998244353;

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
        int n, m;
        cin >> n >> m;
        vector<int> a(n + 5);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        SegmentTree<Info, Tag> seg(a.begin() + 1, a.end());
        while (m--) {
            int x, y, k, op;
            cin >> op;
            cin >> x >> y;
            if (op & 1) {
                cin >> k;
                seg.modify(x, y, {k});
            }
            else {
                cout << seg.query(x, y).sum << "\n";
            }
        }
    }
    void main() {
        ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }

#undef int
#undef ls
#undef rs
}

int main() {
    return Xbbbz::main(), 0;
}
