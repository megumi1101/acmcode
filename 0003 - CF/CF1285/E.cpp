#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    // #define int long long
    const int N = 2e5 + 10;
    struct Info {
        bool lf, rt;
        int cnt;
        friend Info operator + (const Info &a, const Info &b) {
            Info c;
            c.lf = a.lf;
            c.rt = b.rt;
            c.cnt = a.cnt + b.cnt - (a.rt & b.lf);
            return c;
        }
        Info (bool _lf, bool _rt, int _cnt) : lf(_lf), rt(_rt), cnt(_cnt) {}
        Info () {}
    };
    struct Smt {
        #define ls (u << 1)
        #define rs ((u << 1) | 1)
        #define mid ((l + r) >> 1)
        int n;
        vector<int> a;
        vector<Info> s;
        Smt (int _n, vector<int> _a) {  
            n = _n; a = _a; s.resize(n * 4 + 100);
        }
        void pushup(int u) {
            s[u] = s[ls] + s[rs];
        }
        void build (int u, int l, int r) {
            if (l == r) {
                s[u] = Info(a[l] >= 1, a[l] >= 1, a[l] >= 1);
                return;
            }
            build(ls, l, mid);
            build(rs, mid + 1, r);
            pushup(u);
        }
        Info cx (int u, int l, int r, int xl, int xr) {
            if (xl <= l && r <= xr) return s[u];
            if (xr <= mid) return cx(ls, l, mid, xl, xr);
            else if (xl > mid) return cx(rs, mid + 1, r, xl, xr);
            else return cx(ls, l, mid, xl, xr) + cx(rs, mid + 1, r, xl, xr);
        }
        #undef ls 
        #undef rs 
        #undef mid
    };
    void sol() {
        int n;
        cin >> n;
        vector<int> a(n + 5), b(n + 5), d(4 * n + 5, 0), tmp(2 * n + 5, 0);
 
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            cin >> b[i];
            tmp[i * 2 - 1] = a[i];
            tmp[i * 2] = b[i];
        }
 
        sort(tmp.begin() + 1, tmp.begin() + 1 + 2 * n);
        int cnt = unique(tmp.begin() + 1, tmp.begin() + 1 + 2 * n) - tmp.begin() - 1;
 
        for (int i = 1; i <= n; i++) {
            a[i] = lower_bound(tmp.begin() + 1, tmp.begin() + 1 + cnt, a[i]) - tmp.begin();
            b[i] = lower_bound(tmp.begin() + 1, tmp.begin() + 1 + cnt, b[i]) - tmp.begin();
            a[i] <<= 1;
            b[i] <<= 1;
            d[a[i]]++;
            d[b[i] + 1]--;
        }
        cnt <<= 1;
        cnt += 3;
        for (int i = 1; i <= cnt; i++) {
            d[i] += d[i - 1];
        }
        Smt t1(cnt, d);
        t1.build(1, 1, cnt);
        for (int i = 1; i <= cnt; i++) {
            d[i]--;
        }
        Smt t2(cnt, d);
        t2.build(1, 1, cnt);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int l = a[i], r = b[i];
            ans = max(ans, (t1.cx(1, 1, cnt, 1, l - 1) + t2.cx(1, 1, cnt, l, r) + t1.cx(1, 1, cnt, r + 1, cnt)).cnt);
        }
        cout << ans << "\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        cin >> T;
        while (T--) sol();
        cout.flush();
    }
    // #undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
