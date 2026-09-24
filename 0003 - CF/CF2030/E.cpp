#include <bits/stdc++.h>
 
using namespace std;
#define int long long
const int mod = 998244353, inf = 1e9;
vector<int> fac, facn, inv;
void init() {
    int n = 2e5;
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
    int n;
    cin >> n;
    vector<int> a(n + 5), p2(n + 5, 1);
    int lft = n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[x]++;
        p2[i] = p2[i - 1] * 2 % mod;
    }
 
    int ans = 0;
    vector<int> f, g;
    vector<int> suf, sufg;
    int mn = inf;
    for (int i = 0; i <= n; i++) {
        mn = min(mn, a[i]);
        lft -= a[i];
        for (auto x : g) {
            ans += p2[lft] * x % mod;
            ans %= mod;
        }
        
        if (a[i] == 0) break;
        auto nf = f;
        auto ng = g;
        nf.resize(mn + 1);
        ng.resize(mn + 1);
        if (i == 0) {    
            for (int j = 1; j <= a[i]; j++) {
                nf[j] = C(a[i], j);
                ng[j] = C(a[i], j) * j % mod;
            }
            sufg = ng;
            suf = nf;
            for (int j = a[i] - 1; j >= 0; j--) {
                suf[j] = (nf[j] + suf[j + 1]) % mod;
                sufg[j] = (ng[j] + sufg[j + 1]) % mod;
            }
            f = nf;
            g = ng;
            continue;
        }
 
 
        int res = 0;
        for (int j = mn + 1; j <= a[i]; j++) {
            res += C(a[i], j);
            res %= mod;
        }
        for (int j = mn; j >= 1; j--) {
            nf[j] = f[j] * res % mod;
            // if (i == 1 && j == 1) cerr << nf[j] << "  df\n";
            ng[j] = nf[j] * j % mod + g[j] * res % mod;
            // if (i == 1 && j == 1) cerr << ng[j] << "  dg\n";
 
            res = (res + C(a[i], j)) % mod;
            // if (i == 1) {
            //     cerr << suf[j] << " ?  \n";
            // }
            nf[j] += suf[j] * C(a[i], j) % mod;
            nf[j] %= mod;
            ng[j] += C(a[i], j) * j % mod * suf[j] % mod + sufg[j] * C(a[i], j) % mod;
            ng[j] %= mod;
        }
        sufg = ng;
        suf = nf;
        for (int j = mn - 1; j >= 0; j--) {
            suf[j] = (nf[j] + suf[j + 1]) % mod;
            sufg[j] = (ng[j] + sufg[j + 1]) % mod;
        }
        f = nf;
        g = ng;
    }
    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    init();
    int t;
    cin >> t;
    while (t--) sol();
}
