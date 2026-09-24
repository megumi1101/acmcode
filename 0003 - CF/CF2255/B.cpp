#include <bits/stdc++.h>

using namespace std;

#define int long long
const int mod = 998244353, inf = 1e9;
vector<int> fac, ifac, inv;

void init(int n) {
    fac.assign(n + 1, 1);
    ifac.assign(n + 1, 1);
    inv.assign(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
        ifac[i] = ifac[i - 1] * inv[i] % mod;
    }
}

int C(int n, int m) {
    if (n < 0 || m < 0 || n < m) return 1;
    return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

void sol() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> p;
    p.push_back(-1);
    
    array<int, 2> pos{};
    array<int, 2> cnt{};
    int op = 0;
    pos[op]++;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            op ^= 1;
            pos[op]++;
        } else {
            cnt[op]++;
        }
    }

    int ans = 1;
    for (int op = 0; op <= 1; op++)
        ans = ans * C(cnt[op] + pos[op] - 1, pos[op] - 1) % mod;
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init(2e6);
    int t;
    cin >> t;
    while (t--) sol();
}