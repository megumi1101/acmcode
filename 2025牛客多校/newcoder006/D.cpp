#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
const int inf = 1e9;
const int mod = 998244353;
    int fap(int a, int b) {
        int res = 1;
        while (b) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod; b >>= 1;
        }
        return res;
    }
    void sol() { 
        int x, y;
        cin >> x >> y;
        int n = x * (x - 1);
        int res = 1;
        for (int i = 1; i <= y; i++) {
            res *= (n + i) % mod;
            res %= mod;
            res *= fap(i, mod - 2);
            res %= mod;
        }
        // if (n + y >= mod) res = 0;
        cout << res << "\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
#undef int
}


int main() {
    return Xbbbz::main(), 0;
}