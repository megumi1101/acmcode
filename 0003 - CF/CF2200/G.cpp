#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int mod = 1e9 + 7;
 
int fap(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        b = b / 2; a = a * a % mod;
    }
    return res;
}
 
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
    int n, x;
    cin >> n >> x;
    int sum = 0;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int y = stoi(s.substr(1));
        if (s[0] == '+') {
            sum = (sum + y) % mod;
        } else if (s[0] == '-') {
            sum = (sum + mod - y) % mod;
        } else if (s[0] == 'x') {
            a.push_back(y);
        } else {
            a.push_back(fap(y, mod - 2));
        }
    }
 
    int n2 = a.size();
    vector<int> f(n2 + 1);
    f[0] = 1;
 
    
    for (int i = 0; i < a.size(); i++) {
        for (int j = n2; j >= 1; j--) {
            f[j] += f[j - 1] * a[i] % mod;
            f[j] %= mod;
        }
    }
    int ans = x * f[n2] % mod * fac[n] % mod;
    int sum2 = 0;
    for (int i = 0; i <= n2; i++) {
        sum2 += fac[i] * fac[n2 - i] % mod * fac[n] % mod * facn[n2 + 1] % mod * f[i] % mod;
        sum2 %= mod;
    }
    ans = ans + sum * sum2 % mod;
    ans %= mod;
    ans = ans * facn[n] % mod;
    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init(1e6);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
