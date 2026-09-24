#include <bits/stdc++.h>
using namespace std;
 
namespace Xbbbz {
using i64 = long long;
const int inf = 1e9; 
    struct Fen {
        int n;
        vector<int> a;
        Fen(int n) {
            this->n = n;
            a.assign(n + 5, 0);
        }
        void add(int x, int v) {
            for (int i = x; i <= n; i += i & -i) {
                a[i] += v;
            }
        }
        int cx(int x) {
            int res = 0;
            for (int i = x; i; i -= i & -i) {
                res += a[i];
            }
            return res;
        }
        int sum(int l, int r) {
            return cx(r) - cx(l - 1);
        }
    };
 
#define ls (u << 1)
#define rs (u << 1 | 1)
    template<typename Info, typename Tag>
    struct SegmentTree {
        int n;
        vector<Info> info;
        vector<Tag> tag;
        SegmentTree(int n) {
            this->n = n;
            info.assign(4 << __lg(n), Info{});
            tag.assign(4 << __lg(n), Tag{});
            build(1, 1, n);
        }
        void build(int u, int l, int r) {
            if (l == r) {
                info[u] = {l - 1};
                return;
            }
            int m = (l + r) >> 1;
            build(ls, l, m);
            build(rs, m + 1, r);
            pull(u);
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
        int n, m;
        cin >> n >> m;
        vector<int> a(n + 1), b(m + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= m; i++) cin >> b[i];
        vector<int> c;
        c.reserve(n + m);
        for (int i = 1; i <= n; i++) c.push_back(a[i]);
        for (int i = 1; i <= m; i++) c.push_back(b[i]);
        sort(c.begin(), c.end());
        c.erase(unique(c.begin(), c.end()), c.end());
        for (int i = 1; i <= n; i++) a[i] = lower_bound(c.begin(), c.end(), a[i]) - c.begin() + 1;
        for (int i = 1; i <= m; i++) b[i] = lower_bound(c.begin(), c.end(), b[i]) - c.begin() + 1;
        
        Fen fen(n + m);
        i64 nia = 0;
        for (int i = 1; i <= n; i++) {
            nia += i - 1 - fen.cx(a[i]);
            fen.add(a[i], 1);
        }
        
        sort(b.begin() + 1, b.end());
        SegmentTree<Info, Tag> seg(n + 1);
        vector<vector<int>> pos(n + m + 5);
        for (int i = 1; i <= n; i++) {
            pos[a[i]].emplace_back(i);
        }
        int lst = 0;
        int lstmn = 0;
        for (int i = 1; i <= m; i++) {
            for (int p = lst + 1; p <= b[i]; p++) {
                for (int x : pos[p]) {
                    seg.modify(x + 1, n + 1, {-1});
                }
            }
            for (int p = lst; p < b[i]; p++) {
                for (int x : pos[p]) {
                    seg.modify(1, x, {1});
                }
            }
            if (b[i] == lst) {
                nia += lstmn;
                continue;
            }
            lst = b[i];
            lstmn = seg.query(1, n + 1).mn;
            nia += lstmn;
        }
        cout << nia << "\n";
    }
 
    void main() {
        ios::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
#undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
