#include <bits/stdc++.h>
#include <bit>
using namespace std;

#define int long long

vector<int> vis, pr;
void init(int n) {
    vis.assign(n + 5, 0);
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) pr.push_back(i);
        for (int j : pr) {
            int m = i * j;
            if (m > n) break;
            vis[m] = 1;
            if (i % j == 0) {
                break;
            }
        }
    }
}


void sol() {
    int l, r, n;
    cin >> l >> r >> n;

    vector<int> fac;

    int tmp = n;
    for (int i = 2; i * i <= tmp; i++) {
        if (tmp % i == 0) {
            fac.push_back(i);
            while (tmp % i == 0) tmp /= i;
        }            
    }
    if (tmp != 1) fac.push_back(tmp);

    auto get = [&](int x) -> int {
        if (x <= 0) return 0;
        int siz = fac.size();
        int sum = 0;
        for (int i = 0; i < (1ll << siz); i++) {
            int c = popcount((unsigned long long)i);
            int res = 1;
            int op = 1;
            if (c & 1) op = -1;
            for (int bit = 0; bit < siz; bit++) {
                if ((i >> bit) & 1) {
                    res *= fac[bit];
                }
            }
            sum += op * (x / res);
        }
        return sum;
    };

    auto getrng = [&](int l, int r) -> int {
        if (l > r) return 0;
        else return get(r) - get(l - 1);
    };

    int mxp = *(--upper_bound(pr.begin(), pr.end(), n));
    int tr = min(r, mxp);
    
    int ans = 0;
    if (l <= tr) {
        int cnt = tr - l + 1;
        int tmp = getrng(l, tr);
        ans += tmp;
        ans += 2 * (cnt - tmp);
    }
    

    int tl = max(mxp + 1, l);
    if (tl <= r) {
        int siz = n - tl + 1;
        auto id = [&](int x) -> int {
            return x - tl;
        };
        vector<vector<pair<int, int>>> ed(siz);

        vector<int> dis(siz, 1e18);
        dis[id(n)] = 0;

        for (int u = n - 1; u >= tl; u--) {
            for (int v = u + 1; v <= n; v++) {
                dis[id(u)] = min(dis[id(u)], gcd(u, v) + dis[id(v)]);
            }
        }
        for (int i = tl; i <= r; i++) {
            ans += dis[id(i)];
        }
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    init(1e7);

    int t;
    cin >> t;
    while (t--) {
        sol();
    }
}

/*
3
1 5 6
2 33 36
1 99 100
*/