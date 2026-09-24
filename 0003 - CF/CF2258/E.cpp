#include <bits/stdc++.h>

using namespace std;

#define ls (u << 1)
#define rs (u << 1 | 1)

template<typename Info>
struct SegmentTree {
    int n;
    vector<Info> info;

    SegmentTree(int n = -1) : n(n), info(n >= 0 ? 4 * (n + 1) + 5 : 0) {}

    void pull(int u) {
        info[u] = info[ls] + info[rs];
    }

    void modify(int u, int l, int r, int x, const Info &v) {
        if (l == r) return void(info[u] = v);
        int m = (l + r) >> 1;
        x <= m ? modify(ls, l, m, x, v) : modify(rs, m + 1, r, x, v);
        pull(u);
    }

    void modify(int x, const Info &v) {
        assert(0 <= x && x <= n);
        modify(1, 0, n, x, v);
    }

    Info query(int L, int R, int u, int l, int r) {
        if (L <= l && r <= R) return info[u];
        int m = (l + r) >> 1;
        if (R <= m) return query(L, R, ls, l, m);
        if (L > m) return query(L, R, rs, m + 1, r);
        return query(L, R, ls, l, m) + query(L, R, rs, m + 1, r);
    }

    Info query(int l, int r) {
        assert(0 <= l && l <= r && r <= n);
        return query(l, r, 1, 0, n);
    }
};

struct Info {
    int mn = -1;
};

Info operator+(const Info &a, const Info &b) {
    return {min(a.mn, b.mn)};
}

vector<int> pr, minp, all, to;
using ll = long long;

void init(int n) {
    minp.assign(n + 1, 0);
    to.assign(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        if (!minp[i]) {
            pr.push_back(i);
            minp[i] = i;
        }
        for (int j : pr) {
            if (i > n / j) break;
            if (minp[i] < j) break;
            minp[i * j] = j;
        }
    }

    for (auto x : pr) {
        ll t = x;
        for (; t <= n; t *= x) {
            all.push_back(t);
        }
    }
    sort(all.begin(), all.end());
    to.assign(n + 1, -1);
    for (int i = 0; i < all.size(); i++) {
        to[all[i]] = i;
    }
}

struct node {
    int l, r, c;
    friend bool operator < (const node &a, const node &b) {
        if (a.r ^ b.r) return a.r < b.r;
        if (a.c ^ b.c) return a.c > b.c;
        return 0;
    } 
};
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    int siz = upper_bound(all.begin(), all.end(), mx) - all.begin();
    SegmentTree<Info> seg(siz + 5);

    vector<vector<int>> p(siz + 1, {0});
    for (int i = 1; i <= n; i++) {
        for (int x = 1; x * x <= a[i]; x++) {
            if (a[i] % x == 0) {
                if (to[x] != -1) p[to[x]].push_back(i);
                if (1LL * x * x != a[i]) {
                    if (to[a[i] / x] != -1) {
                        p[to[a[i] / x]].push_back(i);
                    }
                }
            }
        }
    }
    for (auto &v : p) v.push_back(n + 1);
    
    vector<node> qrys;
    
    qrys.push_back({1, n, siz});
    for (int i = 0; i < siz; i++) {
        auto &v = p[i];
        for (int j = 0; j + 1 < v.size(); j++) {
            int l = v[j] + 1, r = v[j + 1] - 1;
            qrys.push_back({l, r, i});
        }
    }
    sort(qrys.begin(), qrys.end());

    vector<int> vis(siz + 5);
    for (auto[l, r, c] : qrys) {
        seg.modify(c, {r + 1});
        if (l > r) continue;
        if (c == 0) vis[c] = 1;
        if (vis[c]) continue;
        if (seg.query(0, c - 1).mn >= l) {
            vis[c] = 1;
        }
        
    }

    vector<int> ans;
    for (int i = 0; i < vis.size(); i++) {
        if (vis[i]) ans.push_back(all[i]);
    }
    cout << ans.size() << "\n";
    for (auto x : ans) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    init(2e5 + 100);
    int t;
    cin >> t;
    while (t--) sol();
}