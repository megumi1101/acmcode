#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> f(n + 1);
    for (int i = n; i >= 1; i--) {
        cin >> a[i];
        int k;
        cin >> k;
        
        int d = 1;
        vector<int> v;
        for (int j = 1; j <= k; j++) {
            int x;
            cin >> x;
            v.push_back(gcd(a[x], a[i]));
            f[i] += f[x];
        }
        for (auto x : v) d = lcm(d, x);
        if (d == 1) {
            f[i]++;
        } else {
            a[i] = d;
        }
        cout << f[i] << endl;
        
 
    }
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
