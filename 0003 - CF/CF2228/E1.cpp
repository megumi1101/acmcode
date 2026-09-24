#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int mod = 998244353;
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
    if (i < 0 || j < 0 || i - j < 0) return 0; 
    return fac[i] * facn[j] % mod * facn[i - j] % mod;
}
 
void sol() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
 
    int op, l, r, m;
    cin >> op >> l >> r >> m;
    int N = m;
    int K = 0;
 
    
    for (int i = l; i <= r; i++) {
        if (a[i] != -1) N -= a[i];
        else K++;
    }
    int C0 = C(N + K - 1, K - 1);
    int C1 = C(N + K - 1, K);
    int C2 = C(N + K - 1, K + 1);
 
    int k1 = 0;
    int sumA2 = 0;
    int sumA = 0;
 
    int ans = 0;
    if (K == 0 && N == 0) C0 = 1;
    for (int i = l; i <= r; i++) {
        if (a[i] == -1) {
            k1++;
        } else {
            sumA += a[i];
            sumA %= mod;
            sumA2 = sumA * sumA % mod;
        }
 
        ans += C0 * sumA2 % mod;
        ans += 2ll * C1 * sumA % mod * k1 % mod;
        ans += k1 * (k1 + 1) % mod * C2 % mod + k1 * C1 % mod;
        ans %= mod;
    }
    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    init(1e6);
    while (t--) sol();
}
 
/*
10
5 1
4 -1 7 6 -1
2 2 2 2
5 1
4 -1 8 6 -1
2 3 3 0
5 1
4 -1 8 6 -1
2 4 5 8
5 1
4 -1 8 6 7
2 3 5 21
5 1
4 -1 8 6 7
2 3 5 22
4 1
-1 -1 -1 -1
2 1 1 4
4 1
-1 -1 -1 -1
2 1 2 5
4 1
-1 -1 -1 -1
2 1 3 6
4 1
-1 -1 -1 -1
2 1 4 7
4 1
-1 -1 3 -1
2 1 4 5
 
*/
