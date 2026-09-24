#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;
const int inv2 = (mod + 1) / 2;
void sol() {
    int n;
    cin >> n;

    // op = 0, a | c = 0;
    // op = 1, a ^ c = 1;
    // op = 2, a & c = 1;
    vector f(63, array<int, 3>{-1, -1, -1});
    auto dfs = [&](this auto &&dfs, int bit, int op, int lima, int limc) -> int {
        if (bit < 0) {
            if (op != 1) {
                return 1;
            } else {
                return 0;
            }
        }
        if (!lima && !limc && f[bit][op] != -1) {
            return f[bit][op];
        }

        int upc = limc ? ((n >> bit) & 1) : 1;
        int upa = lima ? ((n >> bit) & 1) : 1;
        int res = 0;
        int ic ;
        for (int ia = 0; ia <= upa; ia++) {
            int nlima = lima && (ia == upa);
            if (op == 0 || op == 2) {
                if (ia == 0) {
                    ic = 0;
                    res += dfs(bit - 1, 0, nlima, limc && ic == upc);
                }
                ic = ia ^ 1;
                if (ic <= upc) res += dfs(bit - 1, 1, nlima, limc && ic == upc);
                
            } else if (op == 1) {
                if (ia == 1) {
                    ic = 1;
                    if (ic <= upc) res += dfs(bit - 1, 2, nlima, limc && ic == upc);
                }
            }
        }
            res %= mod;
        if (lima || limc) return res;
        else return f[bit][op] = res;
    };

    int ans = dfs(59, 0, 1, 1);
    ans = ans + mod - 1;
    ans %= mod;
    ans = ans * inv2 % mod;
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) sol();
} 

/*
5
4
0101
3
111
6
100110
6
100010
6
011110
*/