#include <bits/stdc++.h>
using namespace std;
 
namespace Xbbbz {
const int inf = 1e9;
#define ls (u << 1)
#define rs (u << 1 | 1)
template <typename Info>
struct Smt {
    int n;
    vector<Info> info;
    Smt(int n) {
        this->n = n;
        info.assign(4 << __lg(n), Info{});
    }
    void pull(int u) {
        info[u] = info[ls] + info[rs];
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
    void modify(int u, const Info &v) {
        modify(1, 1, n, u, v);
    }
    Info query(int L, int R, int u, int l, int r) {
        if (L <= l && r <= R) {
            return info[u];
        }
        int m = (l + r) >> 1;
        if (R <= m) return query(L, R, ls, l, m);
        else if (L > m) return query(L, R, rs, m + 1, r);
        else return query(L, R, ls, l, m) + query(L, R, rs, m + 1, r);
    }
    Info query(int l, int r) {
        assert(l <= r);
        return query(l, r, 1, 1, n);
    }
};
#undef ls
#undef rs
struct Info {
    int mn;
    Info(int mn_ = inf) {
        mn = mn_;
    }
};
Info operator+(const Info &x, const Info& y) {
    return Info(min(x.mn, y.mn));
}
    void sol() {
        set<int> s;
        int n, q;
        cin >> n >> q;
        for (int i = 0; i <= n + 1; i++) s.insert(i);
        vector<int> rmn(n + 1, inf);
        Smt<Info> seg(n);
        while (q--) {
            int op;
            cin >> op;
            if (op == 0) {
                int l, r, x;
                cin >> l >> r >> x;
                if (x == 0) {
                    while (1) {
                        auto it = s.lower_bound(l);
                        if (*it <= r) s.erase(it);
                        else break;
                    }
                } else {
                    if (r < rmn[l]) {
                        rmn[l] = r;
                        seg.modify(l, Info(r));
                    }
                }
            } else {
                int x;
                cin >> x;
                if (s.find(x) == s.end()) {
                    cout << "NO\n";
                    continue;
                }
                auto itr = s.upper_bound(x);
                auto itl = --s.lower_bound(x);
                int l = *itl;
                int r = *itr;
                l++, r--;
                if (l > r) {
                    cout << "N/A\n";
                    continue;
                }
                auto [t] = seg.query(l, r);
                if (t <= r) {
                    cout << "YES\n";
                } else {
                    cout << "N/A\n";
                }
            }
        }
    }
 
    void main() {
        ios::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
#undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
