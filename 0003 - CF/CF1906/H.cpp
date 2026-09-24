#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
const int mod = 998244353;
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;
 
    vector<int> jc(m + 1), jn(m + 1), inv(m + 1);
    jc[0] = jc[1] = jn[0] = jn[1] = inv[1] = 1;
    for (int i = 2; i <= m; i++) {
        jc[i] = jc[i - 1] * i % mod;
        inv[i] = inv[mod % i] * (mod - mod / i) % mod;
        jn[i] = jn[i - 1] * inv[i] % mod;
    }
    
    auto C = [&](int i, int j) -> int {
        return jc[i] * jn[j] % mod * jn[i - j] % mod;
    };
    vector<int> a(26), b(26);
    for (auto c : s) a[c - 'A']++;
    for (auto c : t) b[c - 'A']++;
    
    vector f(26, vector(m + 1, (int)0));
    auto sumf = f;
    for (int i = a[25]; i <= b[25]; i++) {
        sumf[25][i] = 1;
    }
    for (int i = 24; i >= 0; i--) {
        for (int j = 0; j <= b[i]; j++) {
            int x = a[i] - j;
            if (x < 0) continue;
            if (b[i + 1] - x >= 0) {
                f[i][j] += sumf[i + 1][b[i + 1] - x] * C(a[i], x);
                f[i][j] %= mod;
            }
        }
        sumf[i][0] = f[i][0];
        for (int j = 1; j <= b[i]; j++) {
            sumf[i][j] += sumf[i][j - 1] + f[i][j];
            sumf[i][j] %= mod;  
        }
    }
 
    int ans = sumf[0][b[0]];
 
    int res = jc[n];
    
    for (int i = 0; i < 26; i++) {
        res = res * jn[a[i]] % mod;
    }
    cout << ans * res % mod;
 
}
