#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
void sol() {
    int n, x, y, k;
    cin >> n >> x >> y >> k;
    if (n <= 3) {
        cout << "1\n";
        return;
    }
    x--;
    y--;
    int dis1 = (x - y + n) % n;
    int dis2 = (y - x + n) % n;
    int ans = 0;
 
    ans = min(dis1, dis2) + k;
    
    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
