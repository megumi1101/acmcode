#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
void sol() {
    int n, m;
    cin >> n >> m;
    vector<int> odds, evens;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        ans += x;
        if (i & 1) odds.push_back(x); 
        else evens.push_back(x); 
    }
    sort(odds.rbegin(), odds.rend());
    sort(evens.rbegin(), evens.rend());
 
    int c0 = 0, c1 = 0;
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        if (x & 1) {
            if (c1 < odds.size() && (odds[c1] > 0 || c1 == 0)) {
                ans -= odds[c1];
                c1++;
            }
        }
        else {
            if (c0 < evens.size() && (evens[c0] > 0 || c0 == 0)) {
                ans -= evens[c0];
                c0++;
            }
        }
    }
 
    // int ans = 0;
    // for (int i = 0; i < (n + 1) / 2 - c1; i++) ans += odds[i];
    // for (int i = 0; i < n / 2 - c0; i++) ans += evens[i];
 
    cout << ans << "\n";
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
