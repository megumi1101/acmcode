#include <bits/stdc++.h>

using namespace std;

#define int long long

#define ls (u << 1)
#define rs (u << 1 | 1)

template<typename Info>
struct SegmentTree {
    int n;
    vector<Info> info;

    SegmentTree(int n_) : n(n_), info(4 << __lg(n), Info{}) {}

    void pull(int u) { info[u] = info[ls] + info[rs]; }

    void modify(int u, int l, int r, int x, const Info &v) {
        if (l == r) return void(info[u] = v);
        int m = (l + r) >> 1;
        x <= m ? modify(ls, l, m, x, v) : modify(rs, m + 1, r, x, v);
        pull(u);
    }

    void modify(int x, const Info &v) { modify(1, 0, n - 1, x, v); }


    Info query(int L, int R, int u, int l, int r) {
        if (L <= l && r <= R) return info[u];
        int m = (l + r) >> 1;
        if (R <= m) return query(L, R, ls, l, m);
        if (L > m) return query(L, R, rs, m + 1, r);
        return query(L, R, ls, l, m) + query(L, R, rs, m + 1, r);
    }

    Info query(int l, int r) {
        assert(l <= r);
        return query(l, r, 1, 0, n - 1);
    }


    template<class F>
    int findFirst(int L, int R, F check, int u, int l, int r) {
        if (r < L || R < l || !check(info[u])) return -1;
        if (l == r) return l;
        int m = (l + r) >> 1;
        int p = findFirst(L, R, check, ls, l, m);
        return p != -1 ? p : findFirst(L, R, check, rs, m + 1, r);
    }

    template<class F>
    int findFirst(int l, int r, F check) {
        if (l > r) return -1;
        return findFirst(l, r, check, 1, 0, n - 1);
    }

    template<class F>
    int findLast(int L, int R, F check, int u, int l, int r) {
        if (r < L || R < l || !check(info[u])) return -1;
        if (l == r) return l;
        int m = (l + r) >> 1;
        int p = findLast(L, R, check, rs, m + 1, r);
        return p != -1 ? p : findLast(L, R, check, ls, l, m);
    }

    template<class F>
    int findLast(int l, int r, F check) {
        if (l > r) return -1;
        l++; r++;
        return findLast(l, r, check, 1, 1, n);
    }
    
};

#undef ls
#undef rs

/*
 * 1. 单点修改 + 区间查询
 *
 * 要求 Info 支持：
 *   Info{}
 *   Info operator+(const Info&, const Info&)
 *
 * findFirst(l,r,check):
 *   找 [l,r] 内最靠左、满足 check 的位置
 *
 * findLast(l,r,check):
 *   找 [l,r] 内最靠右、满足 check 的位置
 *
 * check(info[u]) 的含义应为：
 *   “这个区间内是否可能存在答案”
 */

struct Info {
    int mn = -1;
};

Info operator+(const Info &a, const Info &b) {
    return {min(a.mn, b.mn)};
}

const int mod = 998244353;
const int inv2 = (mod + 1) / 2;
int fap(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod; b >>= 1;
    }
    return res;
}


void FWT(vector<int>& a, int f) {
    int n = a.size();
    for (int l = 2; l <= n; l <<= 1) {
        int m = l >> 1;
        for (int i = 0; i < n; i += l) for (int j = 0; j < m; j++) {
            int &x = a[i + j], &y = a[i + j + m], u, v;
            u = x, v = y;
            if (f == 1) x = (u + v) % mod, y = (u - v + mod) % mod;
            else x = (u + v) * inv2 % mod, y = (u - v + mod) * inv2 % mod;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, K, R;
    cin >> n >> K >> R;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];
    SegmentTree<Info> smt(n + 5);
    smt.modify(0, {0});

    vector<int> sg(n + 1);
    for (int i = 1; i <= n; i++) {
        sg[i] = smt.findFirst(0, n, [&](const Info &t) {return t.mn < i - p[i];});
        smt.modify(sg[i], {i});
    }

    vector<int> cnt(1 << 19, 0);
    for (auto x : sg) cnt[x]++;
    FWT(cnt, 1);
    for (auto &x : cnt) x = fap(x, R);
    FWT(cnt, -1);
    int ans = cnt[0];

    fill(cnt.begin(), cnt.end(), 0);

    for (int i = 0; i <= n; i ++) {
		if (i + K > n || sg[i] == sg[i + K]) {
			cnt[sg[i]] ++;
		}
	}
    FWT(cnt, 1);
    for (auto &x : cnt) x = fap(x, R);
    FWT(cnt, -1);
    ans -= cnt[0];

    if (ans < 0) ans += mod;
    cout << ans << "\n";
} 