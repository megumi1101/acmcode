#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;

const int inf = 1e18;
void sol() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), siz(n + 1);
    vector<char> vis(n + 1);

    for (int i = 1; i <= n; i++) cin >> a[i];
    int sum_a = accumulate(a.begin(), a.end(), 0ll);
    int nowV;

    vector<vector<int>> ed(n + 1);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ed[x].push_back(y);
        ed[y].push_back(x);
    }

    vector<int> fa(n + 1), sub(n + 1);

    [&](this auto &&init, int u, int fat) -> void {
        fa[u] = fat;
        sub[u] = a[u];
        for (auto v : ed[u]) {
            if (v == fat) continue;
            init(v, u);
            sub[u] += sub[v];
        }
    }(1, 0);

    auto getSum = [&](int u, int v) -> int {
        if (fa[v] == u) return sub[v];
        return sum_a - sub[u];
    };

    int root = 0, mxt = inf;
    auto getrt = [&](auto &&self, int u, int fat, int n) -> void {
        siz[u] = 1;
        int tmp = 0;
        for (auto v : ed[u]) {
            if (v == fat || vis[v]) continue;
            self(self, v, u, n);
            siz[u] += siz[v];
            tmp = max(siz[v], tmp);
        }
        tmp = max(tmp, n - siz[u]);
        if (tmp < mxt) {
            mxt = tmp;
            root = u;
        }
    };

    auto calc = [&](int u) -> bool {
        vector<pair<int, int>> p;
        p.reserve(ed[u].size());
        for (auto v : ed[u]) {
            if (vis[v]) continue;
            int s = getSum(u, v);
            if (s < nowV || sum_a - s < nowV) continue;
            int len = ([&](this auto &&dfs, int u, int fat, int deep, int up) -> int {
                if (deep >= k) return k;
                int res = deep;
                for (auto v : ed[u]) {
                    if (v == fat || vis[v]) continue;
                    int s = getSum(u, v);
                    if (s < nowV || up - s < nowV) continue;
                    res = max(res, dfs(v, u, deep + 1, s));
                }
                return res;
            } (v, u, 1, s));
            if (len >= k) {
                return 1;
            }
            // cerr << "\n";
            // cerr << v << " " <<  len << " " << sum[v] << "\n";
            p.push_back({len, s});
        }

        vector<int> sufmn(p.size() + 2, inf);
        sort(p.begin(), p.end());
        int r = p.size();
        int siz_p = p.size();
        for (int i = 0; i < siz_p; i++) {
            // cerr << "\n";
            // cerr << p[i].first << " " << p[i].second << "\n";
            r = max(i + 1, r);
            while ( r - 1 >= i + 1 && p[i].first + p[r - 1].first >= k) {
                r--;
                sufmn[r] = min(p[r].second, sufmn[r + 1]);
            }
            if (p[i].second + sufmn[r] <= sum_a - nowV) {
                // cerr << p[i].second + sufmn[r] << "\n";
                return 1;
            }
        }
        return 0;
    };

    auto dfz = [&](auto &&self, int u, int fat) -> bool {
        vis[u] = 1;
        if (calc(u)) {
            return 1;
        }
        for (auto v : ed[u]) {
            if (v == fat || vis[v]) continue;
            mxt = inf;
            getrt(getrt, v, u, siz[v]);
            if (self(self, root, 0)) return 1;;
        }
        return 0;
    };


    auto check = [&](int mid) -> bool {
        nowV = mid;
        fill(vis.begin(), vis.end(), 0);
        root = 0;
        mxt = inf;
        getrt(getrt, 1, 0, n);
        return dfz(dfz, root, 0);
    };


    int l = 1, r = sum_a / (k + 1);
    int ans = -1;
    
    // if (check(7)) {
    //     cout << "Yes\n";
    // }
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}

/*
1
7 2
7 1 3 2 2 4 3
1 2
2 3
2 4
2 5
5 6
5 7
*/