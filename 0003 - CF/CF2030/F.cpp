#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define ls (u << 1)
#define rs (u << 1 | 1)
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
                info[u] = v;
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
            modify(1, 1, n, u, v);
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
        int mn;
        Info(int mn = 1e9) : mn(mn) {}
    };
    Info operator+ (const Info &a, const Info &b) {
        return {min(a.mn, b.mn)};
    } 
 
    void sol() {
        int n, q;
        cin >> n >> q;
        vector<int> a(n + 1), mxr(n + 1, n);
        vector<deque<int>> dd(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        int l = 1, r = 1;
        SegmentTree<Info> seg(n);
        for (int i = 1; i <= n; i++) {
            while (r <= n) {
                int x = a[r];
                if (!dd[x].size()) {
                    dd[x].push_back(r);
                    r++;
                    continue;
                }
                else {
                    int lst = dd[x].back();
                    if (seg.query(lst + 1, r).mn < lst) break;
                    dd[x].push_back(r);
                    seg.modify(r, {lst});
                    r++;
                }
            }
            mxr[i] = r - 1;
            if (dd[a[i]].size() == 1) dd[a[i]].pop_back();
			else {
				dd[a[i]].pop_front();
				seg.modify(dd[a[i]].front(), {(int)1e9});
			}
        }
        while (q--) {
			int l, r;
			cin >> l >> r;
			if (mxr[l] >= r) cout << "YES\n";
			else cout << "NO\n";
		}
    }
 
    void main() {
        ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int T;
        cin >> T;
        while (T--) sol();
    }
}
 
int main() {
    return Xbbbz::main(), 0;
}
