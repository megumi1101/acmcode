#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
 
    vector<int> p;
    int mx = 0;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] < mx) {
            p.push_back(i);
            res = max(res, mx - a[i]);
        } else {
            mx = a[i];
        }
    }
 
    int lst = -4e18;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= lst) {
            lst = a[i];
        } else if (a[i] + res >= lst) {
            lst = a[i] + res;
        } else {
            cout << "NO\n";
            return;
        }
    }
 
    cout << "YES\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
