#include <bits/stdc++.h>
using namespace std;

namespace Xbbbz {

struct DSU {
    int n;
    vector<int> f, siz;
    DSU() {}
    DSU(int n) { this->n = n; init(n); }
    void init(int n) {
        f.resize(n + 5);
        iota(f.begin(), f.end(), 0);
        siz.assign(n + 5, 1);
    }
    int find(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) { return find(x) == find(y); }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) { return siz[find(x)]; }
};

#define ls (u << 1)
#define rs (u << 1 | 1)
struct Info {
    long long x; 
    int y;      
    Info(long long _x = -1, int _y = 1) : x(_x), y(_y) {}
};
static inline bool better(const Info& a, const Info& b) {
    __int128 lhs = (__int128)a.x * b.y;
    __int128 rhs = (__int128)b.x * a.y;
    if (lhs == rhs) return false; 
    return lhs > rhs;
}
static inline Info combine(const Info& L, const Info& R) {
    return better(L, R) ? L : R;
}

template<typename T>
struct SegmentTree {
    int n;
    vector<T> info;
    SegmentTree() {}
    SegmentTree(int n_){ init(n_); }
    void init(int n_) {
        n = n_;
        info.assign(4 << __lg(max(1, n)), T{});
    }
    void pull(int u){ info[u] = combine(info[ls], info[rs]); }
    void modify(int u, int l, int r, int x, const T &v){
        if (l == r){ info[u] = v; return; }
        int m = (l + r) >> 1;
        if (x <= m) modify(ls, l, m, x, v);
        else modify(rs, m + 1, r, x, v);
        pull(u);
    }
    void modify(int pos, const T &v){ modify(1, 1, n, pos, v); }
    T query(int L, int R, int u, int l, int r){
        if (L <= l && r <= R) return info[u];
        int m = (l + r) >> 1;
        if (R <= m) return query(L, R, ls, l, m);
        if (L >  m) return query(L, R, rs, m + 1, r);
        return combine(query(L, R, ls, l, m), query(L, R, rs, m + 1, r));
    }
    T query(int l, int r){
        assert(1 <= l && l <= r && r <= n);
        return query(l, r, 1, 1, n);
    }
};
#undef ls
#undef rs

void sol() {
    int n, Tq;
    cin >> n >> Tq;

    vector<vector<int>> p(1e6 + 5);
    vector<int> a(n + 5);
    for (int i = 1; i <= n; i++) { cin >> a[i]; p[a[i]].push_back(i); }

    SegmentTree<Info> seg(n / 2 + 5);
    vector<Info> best(n + 1, Info(-1, 1)); 

    DSU dsu(n + 1);       
    vector<bool> vis(n + 5, false);

    int duan = 0;
    long long sum = 0;

    for (int val = 1; val <= 1000000; val++) {
        for (int x : p[val]) {
            vis[x] = true;
            int sizL = dsu.size(x - 1);
            int sizR = dsu.size(x + 1);
            if (vis[x - 1] && vis[x + 1]) {
                sum -= 1LL * sizL * sizL;
                sum -= 1LL * sizR * sizR;
                sum += 1LL * (sizL + sizR + 1) * (sizL + sizR + 1);
                dsu.merge(x - 1, x);
                dsu.merge(x, x + 1);
                duan--;
            } else if (!vis[x - 1] && !vis[x + 1]) {
                duan++;
                sum += 1; 
            } else if (vis[x - 1]) {
                sum -= 1LL * sizL * sizL;
                sum += 1LL * (sizL + 1) * (sizL + 1);
                dsu.merge(x - 1, x);
            } else {
                sum -= 1LL * sizR * sizR;
                sum += 1LL * (sizR + 1) * (sizR + 1);
                dsu.merge(x, x + 1);
            }
        }
        
        Info cand(sum, val);
        if (!better(best[duan], cand)) { 
            best[duan] = cand;
            seg.modify(duan, cand);
        }
        
    }

    long long lastans = 0;
    while (Tq--) {
        int aa, bb, xx, yy;
        cin >> aa >> bb >> xx >> yy;
        int l = (int)((1LL * aa * lastans + xx - 1) % n) + 1;
        int r = (int)((1LL * bb * lastans + yy - 1) % n) + 1;
        if (l > r) swap(l, r);
        int tl = min(l, n / 2 + 1);
        int tr = min(r, n / 2 + 1);
        Info res = seg.query(tl, tr);
        if (res.x == -1) {
            cout << "-1 -1\n";
            cout << l << ' ' << r << ' ' << lastans % n << '\n';
            lastans = 1; 
        } else {
            cout << res.x << ' ' << res.y << '\n';
            cout << l << ' ' << r << ' ' << lastans % n << '\n';
            lastans = 1LL * res.x * res.y % n;
        }
    }
}

void main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) sol();
}

}

int main() { return Xbbbz::main(), 0; }
