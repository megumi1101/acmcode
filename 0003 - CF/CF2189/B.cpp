#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
void sol() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n), c(n);
    int sum = 0, mx = -1e18;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];
    for (int i = 0; i < n; i++) {
        sum += (b[i] - 1) * a[i];
        mx = max(mx, a[i] * b[i] - c[i]);
    }
    if (sum >= x) {
        cout << "0\n";
        return;
    }
 
    if (mx > 0) {
        cout << (x - sum - 1) / mx + 1 << "\n";
        return;
    } else {
        cout << "-1\n";
    }
    
}
 
signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
 
    int T;
    cin >> T;
    while (T--) sol();
}
