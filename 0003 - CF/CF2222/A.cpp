#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
 
    bitset<1005> f;
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < a[i]; j++)
            f |= f << (100 / a[i]);
    }
    for (int i = 0; i <= 100 * n; i++) {
        if (f[i] == 0) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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
