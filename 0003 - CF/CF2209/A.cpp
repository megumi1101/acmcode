#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
void sol() {
    int n, c, k;
    cin >> n >> c >> k;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (c >= a[i]) {
            int up = min(c - a[i], k);
            k -= up;
            a[i] += up;
            c += a[i];
        } else {
            break;
        }
    }
    cout << c << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) sol();
}
