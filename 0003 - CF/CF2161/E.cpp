#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
const int inf = 1e9 + 10;
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
    if (i < 0 || j < 0 || i < j) return 0;
    return fac[i] * facn[j] % mod * facn[i - j] % mod;
}
 
void sol() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    vector<int> sufhas0(n + 1), sufhas1(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        sufhas0[i] = sufhas0[i + 1] | (s[i] == '0');
        sufhas1[i] = sufhas1[i + 1] | (s[i] == '1');
    }
    
    int m = k - 1;
    vector<int> f(m);
    int c0 = 0, c1 = 0, c2 = 0;
    for (int i = 0; i < m; i++) {
        if (s[i] == '0') c0++;
        else if (s[i] == '1') c1++;
        else c2++;
    }
 
    int ans = 0;
    if (!sufhas0[m]) {
        for (int i = c0; i <= m / 2 - 1; i++) {
            ans = (ans + C(c2, i - c0)) % mod;
        }
    }
    if (!sufhas1[m]) {
        for (int i = c1; i <= m / 2 - 1; i++) {
            ans = (ans + C(c2, i - c1)) % mod;
        }
    }
 
    vector<int> has0(m), has1(m);
    int ones = 0, zrs = 0, cons = 0; 
   
    auto update = [&](int i, int v, int op) -> void {
        if (has0[i] && has1[i]) cons--;
        else if (has0[i]) zrs--;
        else if (has1[i]) ones--;
 
        if (v == 0) has0[i] += op;
        else has1[i] += op;
 
        if (has0[i] && has1[i]) cons++;
        else if (has0[i]) zrs++;
        else if (has1[i]) ones++;
    };
    
    for (int i = 0; i < n; i++) if (s[i] != '?') update(i % m, s[i] - '0', 1);
    if (!cons && zrs <= m / 2 && ones <= m / 2) {
        ans = (ans + C(m - ones - zrs, m / 2 - zrs)) % mod;
    }
 
    for (int i = n - 1; i >= m; i--) {
        if (s[i] != '?') update(i % m, s[i] - '0', -1);
        for (int v = 0; v < 2; v++) {
            if (v == 0 && sufhas1[i]) continue;
            if (v == 1 && sufhas0[i]) continue;
            update(i % m, v ^ 1, 1);
            if (!cons && zrs <= m / 2 && ones <= m / 2) {
                ans = (ans + C(m - ones - zrs, m / 2 - zrs)) % mod;
            }
            update(i % m, v ^ 1, -1);
        }
    }
    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init(1e5);
    int t;
    cin >> t;
    while (t--) sol();
}
