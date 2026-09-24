#include <bits/stdc++.h>

using namespace std;

#define int long long

#define ls (u << 1)
#define rs (u << 1 | 1)

template<typename Info>
struct SegmentTree {
    int n;
    vector<Info> info;
    SegmentTree(auto l, auto r) {
        n = r - l;
        info.assign(4 << __lg(n), Info{});
        build(1, 1, n, l);
    }

    void pull(int u) {
        info[u] = info[ls] + info[rs];
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

    void modify(int p, int u, int l, int r, const Info &v) {
        if (l == r) {
            info[u] = v;
            return;
        }
        int m = (l + r) >> 1;
        if (p <= m) {
            modify(p, ls, l, m, v);
        } else {
            modify(p, rs, m + 1, r, v);
        }
        pull(u);
    }

    void modify(int p, const Info &v) {
        modify(p, 1, 1, n, v);
    }
};

#undef ls
#undef rs

struct Info {
    int sum;
    int mx;
    Info(int sum = 0, int mx = 0)
        : sum(sum), mx(mx) {}
};

Info operator+(const Info &x, const Info &y) {
    return {
        x.sum + y.sum,
        max(x.mx, x.sum + y.mx)
    };
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> all;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        all.push_back(b[i]);
    }

    vector<array<int, 3>> query(q + 1);

    for (int i = 1; i <= q; i++) {
        int op, pos, x;
        cin >> op >> pos >> x;
        query[i] = {op, pos, x};
        if (op == 2) {
            all.push_back(x);
        }
    }

    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());

    int siz = all.size();

    auto getid = [&](int x) {
        int t = lower_bound(all.begin(), all.end(), x) - all.begin();
        return siz - t;
    };

    vector<int> sum(siz + 1);
    vector<int> cnt(siz + 1);

    for (int i = 1; i <= n; i++) {
        int p = getid(b[i]);
        sum[p] += a[i];
        cnt[p]++;
    }

    vector<Info> init(siz);

    for (int p = 1; p <= siz; p++) {
        int bv = all[siz - p];
        init[p - 1] = {
            sum[p],
            cnt[p] ? sum[p] + bv : 0
        };
    }

    SegmentTree<Info> seg(init.begin(), init.end());
    auto refresh = [&](int p) {
        int bv = all[siz - p];

        seg.modify(p, {
            sum[p],
            cnt[p] ? sum[p] + bv : 0
        });
    };

    for (int k = 1; k <= q; k++) {
        auto [op, pos, x] = query[k];
        if (op == 1) {
            int p = getid(b[pos]);

            sum[p] += x - a[pos];
            a[pos] = x;

            refresh(p);
        } else {
            int oldp = getid(b[pos]);
            int newp = getid(x);

            if (oldp != newp) {
                sum[oldp] -= a[pos];
                cnt[oldp]--;
                refresh(oldp);
                sum[newp] += a[pos];
                cnt[newp]++;
                refresh(newp);

                b[pos] = x;
            }
        }
        cout << seg.info[1].mx << '\n';
    }
    return 0;
}