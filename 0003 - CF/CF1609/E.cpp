#include <bits/stdc++.h>
using namespace std;
 
namespace Xbbbz {
// #define int long long
const int inf = 1e9;
struct Mat {
    int a[3][3];
    Mat () {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                a[i][j] = inf;
    }
    Mat (char c) {
        int b[3][3] = {{c == 'a', c != 'a', inf}, {inf, c == 'b', c != 'b'}, {inf, inf, c == 'c'}};
        for (int i = 0; i < 3; i++) 
            for (int j = 0; j < 3; j++)
                a[i][j] = b[i][j];
    }
    friend Mat operator *(const Mat &m1, const Mat &m2) {
        Mat m3;
        for (int k = 0; k < 3; k++) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    m3.a[i][j] = min(m3.a[i][j], m1.a[i][k] + m2.a[k][j]);
                }
            }
        }
        return m3;
    }
};
 
 
#define ls (u << 1)
#define rs (u << 1 | 1)
    template<typename Info>
    struct SegmentTree {
        int n;
        vector<Info> info;
        string s;
        SegmentTree(int n_, string s_) {
            n = n_;
            s = s_;
            info.assign(4 << __lg(n_), Info{});
            build(1, 1, n);
        }
        void build (int u, int l, int r) {
            if (l == r) {
                info[u] = Info(s[l]);
                return;
            }
            int m = (l + r) >> 1;
            build(ls, l, m);
            build(rs, m + 1, r);
            pull(u);
        }
        void pull(int u) {
            info[u] = info[ls] * info[rs];
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
                return query(L, R, ls, l, m) * query(L, R, rs, m + 1, r);
            }
        }
        Info query(int l, int r) {
            assert(l <= r);
            return query(l, r, 1, 1, n);
        }
    };
#undef ls
#undef rs
 
 
    void sol() {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        s = " " + s;
        SegmentTree<Mat> seg(n, s);
        while (q--) {
            int x;
            char c;
            cin >> x >> c;
            seg.modify(x, Mat(c));
            
            Mat m1 = seg.info[1];
            Mat m2;
            m2.a[0][0] = 0;
            m1 = m2 * m1;
            int ans = min({m1.a[0][0], m1.a[0][1], m1.a[0][2]});
            cout << ans << "\n";
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
