#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int mod = 998244353;
 
void sol() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    vector<int> b(m);
    int mx = 0;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        if (b[i] > mx) mx = b[i];
    }
    
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int L = 1;
    for (int x : a) {
        L = (L / gcd(L, x)) * x;
        if (L > mx) {
            L = mx + 1; 
            break;
        }
    }
 
    vector<int> vis(mx + 1);
    for (int x : a) {
        if (x > mx || vis[x]) continue;
        for (int k = x; k <= mx; k += x) {
            vis[k] = 1;
        }
    }
 
    int ca = 0, cb = 0, cab = 0;
    for (int x : b) {
        int ac = vis[x];
        int bc = (x % L != 0);
        if (ac && bc) cab++;
        else if (ac) ca++;
        else if (bc) cb++;
    }
    if (cab % 2 == 1) {
       if (ca >= cb) cout << "Alice\n";
        else cout << "Bob\n";
    } else {
        if (ca > cb) cout << "Alice\n";
        else cout << "Bob\n";
    }
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
