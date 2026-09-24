#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];
    vector<int> pre(n);
    bool has = false;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (p[i] > p[j]) {
                has = true;
                pre[p[j] - 1] |= 1LL << (p[i] - 1);
            }
        }
    }
    int all = 1LL << n;
    vector<int> f(all);
    f[0] = 1;
    for (int s = 0; s < all; s++) {
        for (int bit = 0; bit < n; bit++) {
            if (s >> bit & 1) continue;
            if ((s & pre[bit]) == pre[bit]) {
                (f[s | (1LL << bit)] += f[s]) %= mod;
            }
        }
    }
    int ans = f[all - 1];
    if (has) ans = ans * 2 % mod;

    cout << ans << '\n';
}