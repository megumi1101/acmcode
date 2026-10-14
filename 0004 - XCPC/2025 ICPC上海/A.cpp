#include <bits/stdc++.h>

using namespace std;

#define int long long

int ask(int u, int k) {
    cout << "? " << u << " " << k << endl;
    int op;
    cin >> op;
    return op;
}
void sol() {
    int n;
    cin >> n;
    vector<int> fa(n + 1);
    vector<vector<int>> ed(n + 1);
    for (int i = 2; i <= n; i++) {
        cin >> fa[i];
        ed[fa[i]].push_back(i);
    }

    vector<int> dep(n + 1), dfn(n + 1);
    int ct = 0;
    auto dfs = [&](auto &&self, int u) -> void {
        dfn[u] = ct++;
        for (auto v : ed[u]) {
            dep[v] = dep[u] + 1;
            self(self, v);
        }
    };

    dfs(dfs, 1);

    int l = 0, r = n - 1;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (ask(1, mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    vector<int> p;
    vector<int> vis(n + 1, -1);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (dep[i] == ans) {
            p.push_back(i);
        }
    }

    sort(p.begin(), p.end(), [&](int i, int j) {
        return dfn[i] < dfn[j];
    });
    for (int i = 0; i < p.size(); i++) {
        vis[p[i]] = cnt++;
    }

    vector<int> siz(n + 1);
    siz[0] = n;

    l = 0, r = (int)p.size() - 1;
    auto upd = [&](auto &&self, int u) -> void {
        if (vis[u] >= l && vis[u] <= r) {
            siz[u] = 1;
        }
        for (auto v : ed[u]) {
            self(self, v);
            siz[u] += siz[v];
        }
    };

    while (l != r) {
        int now = (r - l + 1);
        fill(siz.begin(), siz.end(), 0);
        siz[0] = n;
        upd(upd, 1);

        int u = p[l];
        while (1) {
            if (siz[fa[u]] * 2 > now) break;
            u = fa[u];
        }

        int v = p[r];
        while (1) {
            if (siz[fa[v]] * 2 > now) break;
            v = fa[v];
        }
        
        if (2 * siz[u] > 2 * siz[v]) {
            if (ask(u, ans - dep[u])) {
                r = l + siz[u] - 1;
            } else {
                l += siz[u];
            }
        } else {
            if (ask(v, ans - dep[v])) {
                l = r - siz[v] + 1;
            } else {
                r -= siz[v];
            }
        }
        
    }

    cout << "! " << p[l] << endl;

}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
}

/*
1
7
1 1 2 2 3 3
*/