#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int mod = 998244353;
void sol() {
    int x, y;
    cin >> x >> y;
    if (y > 0) {
        int t = x - 2 * y;
        if (t >= 0 && t % 3 == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else if (y < 0) {
        int t = x + 4 * y;
        if (t >= 0 && t % 3 == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else {
        int t = x;
        if (t >= 0 && t % 3 == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
