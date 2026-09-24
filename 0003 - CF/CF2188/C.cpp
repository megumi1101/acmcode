#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
const int inf = 1e18;
 
 
void sol() {
    int n;
    cin >> n;
    vector <int> a(n);
    int mn = inf;
    int mx = -inf;
    for (int i = 0; i < n; i++) cin >> a[i], mn = min(mn, a[i]), mx = max(mx, a[i]);
    auto b = a;
    sort(b.begin(), b.end());
    int k = inf;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        if (a[i] != b[i]) {
            k = min(k, max({x - mn, mx - x}));
        }
    }
 
    if (k == inf) k = -1;
    cout << k << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int T;
    cin >> T;
    while (T--) sol();
}
