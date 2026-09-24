#include <bits/stdc++.h>
using namespace std;
 
namespace Xbbbz {
#define int long long
const int mod = 1e9 + 7;
const int inf = 1e9;
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }
    int fap(int a, int b) {
        if (b < 0) return 0;
        int res = 1;
        while (b) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod; b >>= 1;
        }
        return res;
    }
    void sol() {
        int n, m;
        cin >> n >> m;
        vector<tuple<int, int, int>> a(m);
        for (int i = 0; i < m; i++) {
            int l, r, x;
            cin >> l >> r >> x;
            a[i] = {l, r, x};
        }
        int ans = 0;
        for (int j = 0; j < 30; j++) {
            vector<int> d(n + 5);
            for (auto[l, r, x] : a) {
                if ((x >> j) & 1) continue;
                d[l]++, d[r + 1]--;
            }
            int y = 0;
            for (int i = 1; i <= n; i++) d[i] += d[i - 1]; 
            for (int i = 1; i <= n; i++) if (d[i]) y++; 
            int x = n - y;
            // cerr << x << " " << y << "\n";
            // cerr << y << "\n";
            ans += fap(2, x - 1) * fap(2, y) % mod * fap(2, j) % mod;
            // cerr << ans << "\n";
            ((ans %= mod) += mod) %= mod;
        }
        cout << ans << "\n";
    }
    void main() {
        ios::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
#undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
/*
01101
00111
11001
10011
*/
