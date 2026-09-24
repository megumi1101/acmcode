#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
void sol() {
    int n;
    cin >> n;
 
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    int op = 0;
    vector<int> ans;
    for (int i = n; i >= 1; i--) {
        int t;
        if (a[i] > 0) t = 0;
        else t = 1;
        t ^= op;
        if (t == 0) {
            op ^= 1;
            ans.push_back(i);
        }
    }
 
    cout << ans.size() << "\n";
    for (auto x : ans) cout << x << " ";
    cout << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
