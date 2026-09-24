#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
const i64 i64_inf = 1e18;
const int inf = INT32_MAX;
struct Info {
    int mn;
    Info (int x = inf) {
        mn = x;
    }
};

Info operator+(const Info& x, const Info& y) {
    return {min(x.mn, y.mn)};
}

#define ls (u << 1)
#define rs (u << 1 | 1)
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

    void clear() {
        fill(info.begin(), info.end(), Info{});
    }
};
#undef ls
#undef rs

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    
    vector<i64> a(n + 1);
    vector<i64> all;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        all.push_back(a[i]);
    }

    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());

    int K = 62;
    int siz = all.size();
    auto getpos = [&](i64 x) -> int {
        return lower_bound(all.begin(), all.end(), x) - all.begin() + 1;
    };

    vector f(K, vector<int>(n + 1, inf));
    vector<array<int, 3>> pos(n + 1);
    for (int i = 1; i <= n; i++) {
        pos[i][0] = getpos(a[i]);
        pos[i][1] = getpos(a[i] + a[i]);
        pos[i][2] = upper_bound(all.begin(), all.end(), 3LL * a[i]) - all.begin();
    }


    for (int i = 1; i <= n; i++) f[1][i] = i;
    
    SegmentTree seg(siz + 5);
    for (int len = 2; len <= 60; len++) {
        auto &lst = f[len - 1];
        auto &nf = f[len];    
        for (int i = n; i >= 1; i--) {
            if (pos[i][2] >= pos[i][1]) nf[i] = min(nf[i], seg.query(pos[i][1], pos[i][2]).mn);
            seg.modify(pos[i][0], lst[i]);
        }
        seg.clear();
    }

    for (int len = 1; len <= 60; len++) {
        for (int i = n - 1; i >= 1; i--) {
            f[len][i] = min(f[len][i], f[len][i + 1]);
        }
    }
    

    vector<vector<pair<int, int>>> qrys(n + 1);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        qrys[l].push_back({r, i});
    }
    for (auto &v : qrys) 
        sort(v.begin(), v.end());

    vector<int> ans(q);

    for (int l = 1; l <= n; l++) {
        int len = 1;
        for (auto [r, id] : qrys[l]) {
            while (r >= f[len + 1][l]) {
                len++;
            }
            ans[id] = len;
        }
    }

    for (auto& i : ans) cout << i << '\n';
    
}

/*
5 4
1 2 4 6 17
1 3
2 4
1 5
1 4
*/