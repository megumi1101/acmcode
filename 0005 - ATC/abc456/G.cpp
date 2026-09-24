#include <bits/stdc++.h>

using namespace std;

#define int long long
const int mod = 998244353, inf = 1e9;
vector<int> fac, ifac, inv, p2;

void init(int n) {
    fac.assign(n + 1, 1);
    ifac.assign(n + 1, 1);
    inv.assign(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
        ifac[i] = ifac[i - 1] * inv[i] % mod;
    }

    p2.resize(n + 1);
    p2[0] = 1;
    for (int i = 1; i <= n; i++) {
        p2[i] = p2[i - 1] * 2 % mod;
    }
}

int C(int n, int m) {
    if (n < 0 || m < 0 || n < m) return 0;
    return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

void norm(int &x) {
    x %= mod;
    if (x < 0) x += mod;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    init(2 * N);

    string s;
    cin >> s;
    int cnt = 0;
    vector<int> a;
    for (auto c : s) {
        if (c == '.') cnt++;
        else {
            a.push_back(cnt);
            cnt = 0;
        }
    }
    if (cnt) a.push_back(cnt);

    vector<vector<pair<int, int>>> v;
    sort(a.rbegin(), a.rend());
    auto suf = a;
    for (int i = (int)suf.size() - 2; i >= 0; i--) {
        suf[i] += suf[i + 1];
    }

    for (auto n : a) {
        int siz = v.size();
        v.emplace_back();
        v[siz].push_back({0, 1});
        for (int k = 1; k + 1 <= n; k++) {
            int op = 1;
            int res = 0;
            for (int i = 0; i * (k + 2) <= n + 1; i++) {
                int t = (n + 1) - (k + 2) * i;
                res += op * p2[t] * C(i + t, i) % mod;
                norm(res);
                op *= -1;
            }

            op = -1;
            for (int i = 0; i * (k + 2) <= n; i++) {
                int t = n - (k + 2) * i;
                res += op * p2[t] * C(i + t, i) % mod;
                norm(res);
                op *= -1;
            }
            v[siz].push_back({k, res});
        }
    }
    
    int siz = a.size();
    vector<int> f(N + 1, 1);
    f[0] = 1;
    for (int k = 1; k <= N; k++) {
        for (int i = 0; i < siz; i++) {
            if (k > (int)v[i].size() - 1) {
                f[k] = f[k] * p2[suf[i]] % mod;
                break;
            }
            f[k] = f[k] * v[i][k].second % mod;
        }
    }
    for (int i = 1; i <= N; i++) {
        int ans = f[i] - f[i - 1];
        norm(ans);
        cout << ans << "\n";
    }
}