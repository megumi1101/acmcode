#include <bits/stdc++.h>
 
using namespace std;
 
namespace xbbbz {
    #define int long long
    const int mod = 1e9 + 7;
    int fap(int a, int b) {
        int res = 1;
        while (b) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod; b /= 2;
        }
        return res;
    }
    void sol() {
        int n;
        cin >> n;
        int ans = 6 * fap(4, (1LL << n) - 2) % mod;
        cout << ans << "\n";
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        // cin >> T;
        while (T--) {
            sol();
        }
    }
 
    #undef int
}
 
int main() {
    return xbbbz::main(), 0;
}
