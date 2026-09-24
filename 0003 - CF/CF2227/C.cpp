#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> b;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] % 6 == 0) {
            b.push_back(a[i]);
        }
    }
 
    for (int i = 1; i <= n; i++) {
        if (a[i] % 6 != 0 && a[i] % 2 == 0) {
            b.push_back(a[i]);
        }
    }
 
    for (int i = 1; i <= n; i++) {
        if (a[i] % 6 != 0 && a[i] % 2 != 0 && a[i] % 3 != 0) {
            b.push_back(a[i]);
        }
    }
 
    for (int i = 1; i <= n; i++) {
        if (a[i] % 6 != 0 && a[i] % 2 != 0 && a[i] % 3 == 0) {
            b.push_back(a[i]);
        }
    }
 
    for (auto x : b) cout << x << " ";
    cout << "\n";
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
