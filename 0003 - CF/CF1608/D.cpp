#include <bits/stdc++.h>
using namespace std;
 
namespace Xbbbz {
#define int long long
const int mod = 998244353;
vector<int> jc, jn, inv;
int fap(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod; b >>= 1;
    }
    return res;
}
void init() {
    int n = 1e6;
    jc.assign(n + 5, 0);
    jn.assign(n + 5, 0);
    inv.assign(n + 5, 0);
    jc[0] = jc[1] = jn[0] = jn[1] = inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        jc[i] = jc[i - 1] * i % mod;
        inv[i] = inv[mod % i] * (mod - mod / i) % mod;
        jn[i] = jn[i - 1] * inv[i] % mod;
    }
}
int C(int i, int j) {
    if (j < 0) return 0;
    if (i < j) return 0;
    return jc[i] * jn[j] % mod * jn[i - j] % mod;
}
    void sol() {
        int n, q;
        cin >> n;
        int iswb = 1, isbw = 1, nowwbb = 1;
        int cntb = 0, cntw = 0, cntq = 0, cntqq = 0;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            if (s[0] == 'W') cntw++;
            if (s[1] == 'W') cntw++;
            if (s[0] == 'B') cntb++;
            if (s[1] == 'B') cntb++;
            if (s[0] == '?') cntq++;
            if (s[1] == '?') cntq++;
            if (s[0] == '?' && s[1] == '?') cntqq++;
 
            if (s[0] == 'B' || s[1] == 'W') iswb = 0;
            if (s[0] == 'W' || s[1] == 'B') isbw = 0;
            if (s[0] == 'W' && s[1] == 'W') nowwbb = 0;
            if (s[0] == 'B' && s[1] == 'B') nowwbb = 0;
        }
        int ans = C(cntq, n - cntb);
        if (ans == 0) {
            cout << "0\n";
            return;
        }
        if (nowwbb == 0) {
            cout << ans << "\n";
            return;
        }
        ans += mod - fap(2, cntqq) + iswb + isbw;
        ans %= mod;
        cout << ans << "\n";
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
