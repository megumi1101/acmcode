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
    int ans = 0;

    vector<vector<int>> ed(n + 1);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ed[x].push_back(y);
        ed[y].push_back(x);
    }

    vector<int> fa(n + 1), sub(n + 1);
    vector<vector<pair<int, int>>> vec(n + 1);
    [&](this auto &&init, int u, int fat) -> void {
        fa[u] = fat;
        sub[u] = a[u];
        for (auto v : ed[u]) {
            if (v == fat) continue;
            init(v, u);
            vec[u].push_back({sub[v], v});
            vec[v].push_back({sum_a - sub[v], u});
            sub[u] += sub[v];
        }
    }(1, 0);

    for (auto &v : vec) ranges::sort(v, greater<>());

    int root = 0, mxt = inf;
    auto getrt = [&](this auto &&self, int u, int fat, int n) -> void {
        siz[u] = 1;
        int tmp = 0;
        for (auto v : ed[u]) {
            if (v == fat || vis[v]) continue;
            self(v, u, n);
            siz[u] += siz[v];
            tmp = max(siz[v], tmp);
        }
        tmp = max(tmp, n - siz[u]);
        if (tmp < mxt) {
            mxt = tmp;
            root = u;
        }
    };

    auto collect = [&](this auto &&self, int u, int fat, int len, int now, int mn, vector<int> &used) -> void {
        if (len > k) return;
        if (used.size() <= len) used.resize(len + 1, 0);
        used[len] = max(used[len], min(now, mn));
        for (auto [w, v] : vec[u]) {
            if (v == fat || vis[v]) continue;
            self(v, u, len + 1, w, min(mn, now - w), used);
        }
    };

    auto calc = [&](int u) -> void {
        int cnt = vec[u].size();
        vector<vector<int>> used(cnt);

        int mxlen = 0;
        for (int i = 0; i < cnt; i++) {
            auto[w, v] = vec[u][i];
            used[i].push_back(0);
            if (!vis[v]) {
                collect(v, u, 1, w, inf, used[i]);
                mxlen = max(mxlen, (int)used[i].size() - 1);
            }
        }

        vector<int> opt(mxlen + 1, 0);
        for (int i = 1; i < cnt; i++) {
            int w = vec[u][i].first;
            for (int len = 1; len < used[i].size(); len++) {
                int op = used[i][len];
                if (!op) continue;
                if (len == k) {
                    ans = max(ans, op);
                }
                int need = k - len;
                if (need >= 1 && need <= mxlen && opt[need]) {
                    ans = max(ans, min(op, opt[need]));
                }
            }
            for (int len = 1; len < used[i].size(); len++) {
                opt[len] = max(opt[len], used[i][len]);
            }
        }

        int big = vec[u][0].first;
        fill(opt.begin(), opt.end(), 0);
        opt[0] = sum_a - big;

        for (int i = 1; i < cnt; i++) {
            int w = vec[u][i].first;
            for (int len = 1; len < used[i].size(); len++) {
                int op = used[i][len];
                if (!op) continue;
                opt[len] = max(opt[len], min(op, sum_a - big - w));
            }
        }

        for (int len = 1; len < used[0].size(); len++) {
            int op = used[0][len];
            if (!op) continue;
            int need = k - len;
            if (need < 0 || need >= opt.size()) continue;
            if (!opt[need]) continue;
            ans = max(ans, min(op, opt[need]));
        }
    };

    getrt(1, 0, n);
    [&](this auto &&self, int u, int fat) -> void {
        vis[u] = 1;
        calc(u);
        for (auto v : ed[u]) {
            if (v == fat || vis[v]) continue;
            mxt = inf;
            getrt(v, u, siz[v]);
            self(root, 0);
        }
    } (root, 0);

    if (ans == 0) ans = -1;
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