#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
const int inf = 1e9;
void sol() {
    int l, a, b;
    cin >> l >> a >> b;
    int ans = a;
    for (int i = 0; i < l; i++) {
        a = (a + b) % l;
        ans = max(ans, a);
    }
    cout << ans << "\n";
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
 
    int T;
    cin >> T;
    while (T--) {
        sol();
    }
    
}
