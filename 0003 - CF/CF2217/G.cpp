#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
const int mod = 1e9 + 7, inf = 1e9;
vector<int> fac, facn, inv, p2;
void init(int n) {
    fac.assign(n + 1, 0);
    facn.assign(n + 1, 0);
    inv.assign(n + 1, 0);
    p2.assign(n + 1, 0);
    fac[0] = fac[1] = facn[0] = facn[1] = inv[1] = p2[0] = 1;
    p2[1] = 2;
    for (int i = 2; i <= n; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
        facn[i] = facn[i - 1] * inv[i] % mod;
        p2[i] = p2[i - 1] * 2 % mod;
    }
}
 
int C (int i, int j) {
    return fac[i] * facn[j] % mod * facn[i - j] % mod;
}
 
int Ctl(int n) {
    return fac[2 * n] * facn[n] % mod * facn[n + 1] % mod;
}
 
void sol() {
    int n, k;
    cin >> n >> k;
    
    if (k == 0) {
        cout << Ctl(n) << "\n";
        return;
    }
 
    
    vector sumk0(n + 1, 0ll);
    vector sumk1(n + 1, 0ll);
    
    auto qm = [&](int &x) -> void {
        x %= mod; x += mod; x %= mod;
    };
    for (int i = 0; i < n; i++) {
        if (i <= k - 1) {
            sumk1[i] = p2[i];
            continue;
        }
        sumk1[i] = 2 * sumk1[i - 1] - C(i - 1, k - 1);
        qm(sumk1[i]);
    }
 
    for (int i = 0; i < n; i++) {
        if (i <= k) {
            sumk0[i] = p2[i];
            continue;
        }
        sumk0[i] = 2 * sumk0[i - 1] - C(i - 1, k);
        qm(sumk0[i]);
    }
 
    int ans = 0;
    for (int lf = k - 1; lf <= n; lf++) {
        int rt = n - 1 - lf;
        ans += 2 * Ctl(lf) * Ctl(rt) % mod * C(lf, k - 1) % mod * sumk1[rt] % mod;
        ans %= mod;
        if (rt >= k - 1) {
            ans -= Ctl(lf) * Ctl(rt) % mod * C(lf, k - 1) % mod * C(rt, k - 1) % mod;   
        }
        qm(ans);
    }
 
    for (int lf = k; lf <= n; lf++) {
        int rt = n - 1 - lf;
        ans += 2 * Ctl(lf) * Ctl(rt) % mod * C(lf, k) % mod * sumk0[rt] % mod;
        if (rt >= k) {
            ans -= Ctl(lf) * Ctl(rt) % mod * C(lf, k) % mod * C(rt, k) % mod;    
        }
        qm(ans);
    }
 
    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init(2e6);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
 
/*
6
0 0
3 0
6 0
6 3
6 6
1 1
*/
