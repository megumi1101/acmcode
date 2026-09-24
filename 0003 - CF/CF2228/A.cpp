#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
void sol() {
    int n;
    cin >> n;
    int ans = 0;
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0) ans++;
        else if (x == 1) {
            c1++;
        } else {
            c2++;
        }
    }
    int x = min(c1, c2);
    int y = max(c1, c2);
    ans += x + (y - x) / 3;
    
    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
