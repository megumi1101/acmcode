#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
// #define int long long
    constexpr int N = 1e6 + 10;
    int ans = 0;
    
    void sol() {
        int n;
        cin >> n;
        int mx = 0;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            mx = max(x, mx);
            if (mx == i) ans++;
        }
        cout << ans << "\n";
        
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
#undef int
}
 
int main() {
    return Xbbbz ::main(), 0;
}
