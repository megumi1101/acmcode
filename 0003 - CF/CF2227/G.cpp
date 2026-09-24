#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
#define int long long
void sol() {
    int n;
    cin >> n;
    
    vector<int> a(n + 1);
    tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, 
        tree_order_statistics_node_update> tr0, tr1;
 
    const int inf = 1e18;
    tr0.insert({0, 0});
    tr0.insert({inf, 0});
    tr1.insert({inf, 0});
    int sum = 0;
 
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i & 1) {
            sum += a[i];
            tr1.insert({sum, i});
            auto it = tr0.lower_bound({sum, -inf});
            ans += tr0.order_of_key(*it);
        } else {
            sum -= a[i];
            tr0.insert({sum, i});
            auto it = tr1.upper_bound({sum, inf});
            ans += tr1.size() - tr1.order_of_key(*it) - 1;
        }
    }
 
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
