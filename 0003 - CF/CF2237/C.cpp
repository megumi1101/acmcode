#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    auto b = a;
    for (int i = 1; i + 1 <= n; i++) {
        if (a[i] > a[i + 1]) {
            a[i + 1] += a[i];
        }
    }
    cout << a[n] << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
