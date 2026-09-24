#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int mod = 998244353;
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int l = a[1], r = a[1];
    int end = 0;
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] <= l || a[i] > r + 1) {
            ans++;
            l = a[i];
            r = a[i];
        } else {
            if (a[i] == r + 1 && a[i - 1] != r) {
                ans++;
            }
            r = a[i];
        }
        
    }
    
    cout << ans << "\n";
 
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
