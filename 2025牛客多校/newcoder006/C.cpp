#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
const int mod = 998244353;
const int N = 5e5;
    vector<int> f(N + 10), g(N + 10), h(N + 10), fac(N + 10);
    void init() {
        f[1] = g[1] = h[1] = fac[0] = fac[1] = 1;
        for (int i = 2; i <= N; i++) {
            fac[i] = fac[i - 1] * i % mod;
            h[i] = (i - 1) * h[i - 1] % mod + h[i - 1] + fac[i - 1]; h[i] %= mod;
            g[i] = (i - 1) * g[i - 1] % mod + g[i - 1] + 2 * h[i - 1] % mod + fac[i - 1]; g[i] %= mod;
            f[i] = (i - 1) * f[i - 1] % mod + f[i - 1] + 3 * g[i - 1] % mod + 3 * h[i - 1] % mod + fac[i - 1]; f[i] %= mod;
        }
    }
    void sol() { 
        int n;
        cin >> n;
        cout << f[n] << endl;
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        init();
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
#undef int
}


int main() {
    return Xbbbz::main(), 0;
}