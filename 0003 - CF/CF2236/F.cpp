#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

vector<int> minp, prs;

void init(int n) {
    minp.assign(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        if (!minp[i]) {
            minp[i] = i;
            prs.push_back(i);
        }
        for (auto p : prs) {
            if (p > minp[i] || i * p > n) break;
            minp[i * p] = p;
        }
    }
}

int calc(const vector<int> &c, int cnt) {
    int up = 0;
    for (auto x : c) up = max(up, x);

    int W = cnt + 1;

    auto id = [&](int mx, int res) {
        return mx * W + res;
    };
    
    vector<int> f((up + 1) * W), nf((up + 1) * W);
    f[id(0, 0)] = 1;

    for (auto lim : c) {
        nf = f;
        for (int mx = 0; mx <= up; mx++) {
            for (int res = 0; res <= cnt; res++) {
                int val = f[id(mx, res)];
                if (!val) continue;

                for (int now = 1; now <= lim; now++) {
                    int nmx = max(mx, now);
                    int nres = res + min(mx, now);

                    if (nres <= cnt) {
                        int &to = nf[id(nmx, nres)];
                        to += val;
                        if (to >= mod) to -= mod;
                    }
                }
            }
        }

        f.swap(nf);
    }

    int res = 0;
    for (int mx = 0; mx <= up; mx++) {
        res += f[id(mx, cnt)];
        res %= mod;
    }

    return res;
}

void sol() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<pair<int, int>> v;
    map<int, int> vis;

    int tx = x;
    while (tx > 1) {
        int p = minp[tx], cnt = 0;
        vis[p] = 1;

        while (tx % p == 0) {
            tx /= p;
            cnt++;
        }

        v.push_back({p, cnt});
    }

    map<int, vector<int>> vec;
    map<int, int> cntp;

    for (int i = 1; i <= n; i++) {
        int y = a[i];
        while (y > 1) {
            int p = minp[y], cnt = 0;
            while (y % p == 0) {
                y /= p;
                cnt++;
            }
            if (vis[p]) {
                vec[p].push_back(cnt);
            } else {
                cntp[p] += cnt;
            }
        }
    }

    int ans = 1;

    for (auto [p, cnt] : v) {
        ans = ans * calc(vec[p], cnt) % mod;
    }
    for (auto [p, cnt] : cntp) {
        ans = ans * (cnt + 1) % mod;
    }

    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    init(5e5);
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
    
}
