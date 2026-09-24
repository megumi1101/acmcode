#include <bits/stdc++.h>
using namespace std;

namespace Xbbbz {
#define int long long
const int mod = 20100403;
vector<int> jc, jn, inv;
    void init() {
        int n = 2e6;
        jc.assign(n + 5, 0);
        jn.assign(n + 5, 0);
        inv.assign(n + 5, 0);
        inv[1] = jc[0] = jc[1] = jn[0] = jn[1] = 1;
        for (int i = 2; i <= n; i++) {
            jc[i] = jc[i - 1] * i % mod;
            inv[i] = inv[mod % i] * (mod - mod / i) % mod;
            jn[i] = jn[i - 1] * inv[i] % mod;
        }
    }
    int C (int i, int j) {
        return jc[i] * jn[j] % mod * jn[i - j] % mod;
    }
    void sol() {
        int n, m;
        cin >> n >> m;
        cout << (C(n + m, m) - C(n + m, m - 1) + mod) % mod;
    }

    void main() {
        ios::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
        int T = 1;
        init();
        // cin >> T;
        while (T--) sol();
    }
#undef int
}

int main() {
    return Xbbbz::main(), 0;
}
