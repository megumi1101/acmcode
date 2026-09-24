#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
void sol() {
    int n;
    cin >> n;
    int mx = -1;
    int mn = 1e9;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        mx = max(x, mx);
        mn = min(x, mn);
    }
 
    cout << (mx - mn + 1) / 2 << "\n";
    
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
