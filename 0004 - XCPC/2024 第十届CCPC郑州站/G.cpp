// QOJ user: xbbbz
// Contest: 2024 第十届CCPC邀请赛郑州�?// Problem: #9774. Same Sum (9774)
// Submission: https://qoj.ac/submission/1436901
// Language: C++23

#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
const int mod = 998244353;
const int B = 241;
vector<int> fac, ifac;
int fap(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod; b >>= 1;
    }
    return res;
}
const int iB = fap(241, mod - 2);
void init() {
    int n = 2e5;
    fac.assign(n + 5, 0);
    ifac.assign(n + 5, 0);
    fac[0] = ifac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * B % mod;
    for (int i = 1; i <= n; i++) ifac[i] = ifac[i - 1] * iB % mod;
}


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
#undef ls
#undef rs

struct Tagadd {
    int add;
    Tagadd (int x = 0) {
        add = x;
    }
    void apply(const Tagadd &v) {
        add += v.add;
    }
};

struct Tagmul {
    int mul;
    Tagmul(int x = 1) {
        mul = x;
    }
    void apply(const Tagmul &v) {
        (mul *= v.mul) %= mod;
    }
};

struct Info1 {
    int sum, siz;
    Info1 (int x = 0) {
        sum = x; siz = 1;
    }
    Info1 (int x, int y) {
        sum = x; siz = y;
    }
    void apply(const Tagadd &v) {
        sum += siz * v.add;
    }
};

Info1 operator+(const Info1& x, const Info1& y) {
    return {x.sum + y.sum, x.siz + y.siz};
}

struct Info2 {
    int sum, siz;
    Info2(int x = 0) {
        sum = x; siz = 1;
    }
    Info2 (int x, int y) {
        sum = x; siz = y;
    }
    void apply(const Tagmul &v) {
        (sum *= v.mul) %= mod;
    }
};

Info2 operator+(const Info2& x, const Info2& y) {
    return {(x.sum + y.sum) % mod, x.siz + y.siz};
}
    void sol() {
        int n, q;
        cin >> n >> q;
        vector<int> a(n + 1), fa(n + 1), ia(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        SegmentTree<Info1, Tagadd> seg(a.begin() + 1, a.end());

        for (int i = 1; i <= n; i++) {
            fa[i] = fac[a[i]];
            ia[i] = ifac[a[i]];
        }
        SegmentTree<Info2, Tagmul> fseg(fa.begin() + 1, fa.end());
        SegmentTree<Info2, Tagmul> iseg(ia.begin() + 1, ia.end());
        
        while (q--) {
            int op, l, r;
            cin >> op >> l >> r;
            if (op == 2) {
                auto[sum, _] = seg.query(l, r);
                int m = r - l + 1;
                if (m & 1) {
                    cout << "NO\n";
                    continue;
                }
                if (sum * 2 % m != 0) {
                    cout << "NO\n";
                    continue;
                }
                int S = sum * 2 / (r - l + 1);
                auto[H, _] = fseg.query(l, r);
                auto[RH, _] = iseg.query(l, r);
                int bS = fap(B, S);
                if (bS * RH % mod == H) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
            } else if (op == 1) {
                int v;
                cin >> v;
                seg.modify(l, r, {v});
                fseg.modify(l, r, {fac[v]});
                iseg.modify(l, r, {ifac[v]});
            }
        }
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        init();
        while (T--) sol();
    }
#undef int
}

int main() {
    return Xbbbz::main(),0;
}
</code>