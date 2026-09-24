#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int mod = 1e9 + 7;
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
        cout << "0\n";
        return;
    }
    vector<int> ans(n + 1);
 
    for (int i = 0; i <= n; i++) {
        if (!vis[i]) p.push_back(i);
    }
    int res = 1;
 
    int pos = 0;
    int cnt = 0;
    for (int i = n; i >= 2; i--) {
        while (pos < p.size() && a[i] > p[pos]) pos++;
        if (a[i] == a[i - 1]) {
            res = res * (pos - cnt) % mod;
            cnt++;    
        } else {
            res = res * i % mod;
        }
    }
 
    cout << res << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
