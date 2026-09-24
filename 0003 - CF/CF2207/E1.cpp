#include<bits/stdc++.h>
 
using namespace std;
 
const int inf = 1e9;
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> vis(n + 1);
    vector<int> p;
    bool fg = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] <= n) vis[a[i]] = 1;
        else fg = 1;
 
        if (a[i] <= n - i - 1) fg = 1;
        if (i > 1 && a[i] > a[i - 1]) {
            fg = 1;
        }
    }
 
    if ((a[1] != n) && (a[1] != n - 1)) fg = 1;
    if (fg) {
        cout << "NO\n";
        return;
    }
    for (int i = 0; i <= n; i++) {
        if (!vis[i]) p.push_back(i);
    }
 
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        if (i > 1 && a[i] == a[i - 1]) {
            p.pop_back();
        }
        ans[i] = p.back();
    }
 
    cout << "YES\n";
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
