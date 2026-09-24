#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
const int mod = 998244353;
 
vector<int> fac, facn, inv;
void init() {
    int n = 1e5;
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
    int n, k;
    cin >> n >> k;
    int x = n / k;
    int y = x + 1;
    int num1 = n - n / k * k;
    int num2 = k - num1;
    if (x & 1) swap(x, y), swap(num1, num2);
 
    int tx = x / 2, ty = y / 2;
    
    int num0 = 0;
    int ans = 0;
    int sum = tx * (tx - 1) * num2  + ty * ty  * num1;
    while (num1 >= 0) {
        if (y - 1 > 1 && num0 >= 1) {
            ans +=  fac[k - 1] % mod * facn[num0 - 1] % mod * facn[num1] % mod * facn[num2] % mod; 
        }
 
        if (y > 1 && num1 >= 1) {
            ans += 2 * fac[k - 1] % mod * facn[num0] % mod * facn[num1 - 1] % mod * facn[num2] % mod; 
        }
 
        if (x > 1 && num2 >= 1) {
            ans += fac[k - 1] % mod * facn[num0] % mod * facn[num1] % mod * facn[num2 - 1] % mod; 
        }
        
        if (y == 1) break;
        ans %= mod;
        num1 -= 2;
        num0 += 1;
        num2 += 1;
    }
    cout << sum << " " << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int t;
    cin >> t;
    while (t--) sol();
}
