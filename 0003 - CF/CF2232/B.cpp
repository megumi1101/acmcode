#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int mn = 1e18;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
        mn = min(sum / i, mn);
        cout << mn << " ";
    }
    cout << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
