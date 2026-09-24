#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int mod = 998244353;
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
 
    int cnt = 0, mx = 0;
    int pos = -1;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, a[i]);
        if (mx == i) cnt++;
        if (a[i] == n) pos = i;
    }
    if (cnt >= 1) {
        swap(a[pos], a[1]);
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << "\n";
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
