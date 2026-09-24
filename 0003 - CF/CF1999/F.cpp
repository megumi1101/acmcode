#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
 
    const int N = 2e5 + 10;
    const int mod = 1e9 + 7;
 
    int fac[N], inv[N], faci[N];
 
    void init() {
        int n = 2e5;
        fac[0] = faci[0] = inv[1] = fac[1] = faci[1] = 1;
        for (int i = 2; i <= n; i++) {
            fac[i] = fac[i - 1] * i % mod;
            inv[i] = inv[mod % i] * (mod - mod / i) % mod;
            faci[i] = faci[i - 1] * inv[i] % mod;
        }
    }
 
    int C(int i, int j) {
        return fac[i] * faci[j] % mod * faci[i - j] % mod;
    }
 
    void sol() {
        int n, k;
        cin >> n >> k;
        int a = 0, b = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if (x) a++;
            else b++;
        }
        int ans = 0;
        for (int i = k / 2 + 1; i <= min(k, a); i++) {
            int j = k - i;
            if (j <= b) {
                ans += C(a, i) * C(b, j) % mod;
                ans %= mod;
            } 
        }
        cout << ans <<"\n";
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        init();
        int T;
        cin >> T;
        while (T--) {
            sol();
        }
    }
 
    #undef int 
}
 
int main() {
    return Xbbbz::main(), 0;
}
