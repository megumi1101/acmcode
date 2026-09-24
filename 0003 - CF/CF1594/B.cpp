#include <bits/stdc++.h>
 
using namespace std;
 
namespace xbbbz {
    #define int long long
    const int mod = 1e9 + 7;
    void sol() {
        int n, k;
        cin >> n >> k;
        int cnt = 0;
        int a[40];
        while (k) {
            a[++cnt] = k % 2;
            k /= 2;
        }
        int ans = 0;
        for (int i = cnt; i >= 1; i--) {
            ans = (ans * n + a[i]) % mod;
        }
        cout << ans << "\n";
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T;
        cin >> T;
        while (T--) {
            sol();
        }
    }
 
    #undef int
}
 
int main() {
    return xbbbz::main(), 0;
}
