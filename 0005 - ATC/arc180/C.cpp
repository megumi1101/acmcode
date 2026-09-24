#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    int off = 10 * n;
    vector<int> f(2 * off + 1);
    vector<int> g(2 * off + 1);

    auto id = [off](int x) {
        return x + off;
    };

    f[id(0)] = 1;
    for (int i = 1; i <= n; i++) {
        auto nf = f;
        for (int j = -off; j <= off; j++) {
            if (j) {
                nf[id(j + a[i])] = (nf[id(j + a[i])] + f[id(j)] + g[id(j)]) % mod; 
            }
        }
        g[id(a[i])] = f[id(0)];
        f = move(nf);
    }

    int ans = 0;
    for (auto x : f) ans = (ans + x) % mod;
    cout << ans << "\n";
}