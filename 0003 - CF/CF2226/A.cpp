#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > 1) ans += a[i];
    }
 
    for (int i = n; i >= 1; i--) {
        if (a[i] > 1) {
            break;
        } else {
            ans++;
            break;
        }
    }
 
    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
 
/*
6
0 0
3 0
6 0
6 3
6 6
1 1
*/
