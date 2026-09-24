#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
const int mod = 676767677, inf = 1e9;
vector<int> fac, facn, inv;
void init(int n) {
    fac.assign(n + 1, 0);
    facn.assign(n + 1, 0);
    inv.assign(n + 1, 0);
    fac[0] = fac[1] = facn[0] = facn[1] = inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
        facn[i] = facn[i - 1] * inv[i] % mod;
    }
}
 
int C (int i, int j) {
    return fac[i] * facn[j] % mod * facn[i - j] % mod;
}
 
void sol() {
    int n, m;
    cin >> n >> m;
    
    auto get = [&](int x) -> int  {
        return C(n - x + m - 1, m - 1);
    };
 
    int ans = 0;
    [&](this auto &&self, int l, int r, int dep) -> void {
        if (l > r) return;
        int mid = (l + r) / 2;
        int tmp = get(0);
        if (l - 1 >= 1) {
            tmp -= get(mid - (l - 1));
        }
        if (r + 1 <= n) {
            tmp -= get((r + 1) - mid);
        }
        if (l - 1 >= 1 && r + 1 <= n) {
            tmp += get(r - l + 2);
        }
        tmp %= mod; tmp += mod; tmp %= mod;
        ans += tmp * dep % mod; ans %= mod;
        self(l, mid - 1, dep + 1);
        self(mid + 1, r, dep + 1);
    }(1, n, 1);
 
    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init(2e6);
    int t;
    cin >> t;
    while (t--) sol();
}
/*
7
3 3
3 4
3 5
4 3
4 5
999967 99967
15 876543
*/
