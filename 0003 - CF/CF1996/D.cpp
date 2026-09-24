#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
 
    void sol() {
        int n, k;
        cin >> n >> k;
        int ans = 0;
        for (int a = 1; a <= min(k, n); a++) {
            for (int b = 1; a * b <= n && a + b <= k; b++) {
                ans += min(k - a - b, (n - a * b) / (a + b));
            }
        }
        cout << ans <<"\n";
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
    return Xbbbz::main(), 0;
}
