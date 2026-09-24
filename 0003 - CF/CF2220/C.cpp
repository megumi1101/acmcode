#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
void sol() {
    int p, q;
    cin >> p >> q;
    int t = p + 2 * q;
    for (int n = 1; ; n++) {
        int m = (t - n) / (2 * n + 1);
        // cerr << m << "\n";
        if (m < n) break;
        if (2 * m * n + m + n == t && m - n >= 0 && m - n <= p) {
            cout << n << " " << m << "\n";
            return;
        }
    }
    cout << "-1\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
