#include <bits/stdc++.h>

using namespace std;

#define int long long

using Point = complex<int>;
using Vector = Point;

int cross(Vector a, Vector b) { return imag(conj(a) * b); }
int Cross(Point a, Point b, Point c) { return cross(b - a, c - a); }
bool cmp (Point a, Point b) {
    if (real(a) != real(b)) return real(a) < real(b);
    return imag(a) < imag(b);
}

bool ok(Point pa, Point pb) {
    return imag(pa) * real(pb) >= imag(pb) * real(pa);
}
vector<Point> up_h(vector<Point> p) {
    sort(p.rbegin(), p.rend(), cmp);
    vector<Point> h;
    for (auto x : p) {
        while (h.size() > 1 && Cross(h[h.size() - 2], h.back(), x) <= 0)
            h.pop_back();
        h.push_back(x);
    }
    return h;
}

Point getans(Point p, const vector<Point> &h) {
    int l = 0, r = (int)h.size() - 2, ans = (int)h.size() - 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        Point pa = p + h[mid];
        Point pb = p + h[mid + 1];
        if (ok(pa, pb)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return h[ans] + p;
};

signed main() {
    int n, q;
    cin >> n >> q;

    int B = sqrt((double)n / 2.2) + 1;
    int cnt = (n + B - 1) / B;
    vector<int> bel(n + 1, 0), L(cnt + 1, 0), R(cnt + 1, 0);
    vector<int> mxpos(cnt + 1, 0);
    vector h (cnt + 1, vector<Point>{});
    vector<int> a(n + 1), b(n + 1);

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    vector<Point> pba(n + 1);
    for (int i = 1; i <= n; i++) {
        pba[i] = {b[i], a[i]};
    }

    auto getpos = [&] (int l, int r) -> int {
        int pos = l;
        for (int i = l + 1; i <= r; i++) {
            if (ok(pba[i], pba[pos])) {
                pos = i;   
            }
        }
        return pos;
    };

    auto upd = [&](int blk) {
        vector<Point> pts(pba.begin() + L[blk], pba.begin() + R[blk] + 1);
        h[blk] = up_h(pts);
        mxpos[blk] = getpos(L[blk], R[blk]);
    };

    for (int blk = 1; blk <= cnt; blk++) {
        L[blk] = (blk - 1) * B + 1;
        R[blk] = min(n, blk * B);
        for (int i = L[blk]; i <= R[blk]; i++) {
            bel[i] = blk;
        }
        upd(blk);
    }

    // n / B ((1 + logB)/2),  B (2 + logB)
    //  ((1 + logB) / 2 + (2 + logB))
    // query n / 2 / B * (1 + logB) + B(2 + logB)
    // BlogB 
    while (q--) {
        int op;
        cin >> op;
        int l, r;
        cin >> l >> r;
        if (op == 1) {
            a[l] = r;
            pba[l] = {b[l], a[l]};
            upd(bel[l]);
        } else if (op == 2) {
            b[l] = r;
            pba[l] = {b[l], a[l]};
            upd(bel[l]);
        } else {
            int x = bel[l], y = bel[r];
            Point ans{1, 0};
            if (x == y) {
                int pos = getpos(l, r);
                Point pmx = pba[pos];
                for (int i = l; i <= r; i++) if (i != pos) {
                    if (ok(pmx + pba[i], ans)) {
                        ans = pmx + pba[i];
                    }
                }
            } else {
                int pos = getpos(l, R[x]);
                int post = getpos(L[y], r);
                if (ok(pba[post], pba[pos])) pos = post;
                for (int blk = x + 1; blk < y; blk++) {
                    post = mxpos[blk];
                    if (ok(pba[post], pba[pos])) pos = post;
                }

                Point pmx = pba[pos];

                for (int i = l; i <= R[x]; i++) if (i != pos) {
                    if (ok(pmx + pba[i], ans)) {
                        ans = pmx + pba[i];
                    }
                }

                for (int i = L[y]; i <= r; i++) if (i != pos) {
                    if (ok(pmx + pba[i], ans)) {
                        ans = pmx + pba[i];
                    }
                }

                if (bel[pos] >= x + 1 && bel[pos] < y) {
                    int blk = bel[pos];
                    for (int i = L[blk]; i <= R[blk]; i++) if (i != pos) {
                        if (ok(pmx + pba[i], ans)) {
                            ans = pmx + pba[i];
                        }
                    }
                }

                for (int blk = x + 1; blk < y; blk++) if (blk != bel[pos]) {
                    auto tmp = getans(pmx, h[blk]);
                    if (ok(tmp, ans)) {
                        ans = tmp;
                    }
                }
            }
            x = imag(ans);
            y = real(ans);
            int d = gcd(x, y);
            x /= d;
            y /= d;
            cout << x << " " << y << "\n";
        }
    }
}