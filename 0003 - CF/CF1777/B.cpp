#include <iostream>
#include <vector>
 
using namespace std;
 
namespace xbbbz {
    #define int long long
    const int MOD = 1e9 + 7;
    vector<long long> f(100005), fac(100005); 
 
    void init() {
        f[1] = 0;
        fac[0] = 1;
        for (int i = 1; i <= 100000; i++) {
            fac[i] = (fac[i - 1] * i) % MOD;
        }
        for (int i = 2; i <= 100000; i++) {
            f[i] = (f[i - 1] * i) % MOD + ((i * (i - 1) / 2) * fac[i - 1]) % MOD;
            f[i] %= MOD;
        }
    }
 
    void solve() {
        int n;
        cin >> n;
        cout << (2 * f[n] + fac[n] * ((n-1) * n / 2) % MOD ) % MOD << "\n";
    }
 
    void main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        init();
        int T = 1;
        cin >> T;
        while (T--) solve();
    }
    #undef int
}
 
int main() {
    return xbbbz::main(), 0;
}
