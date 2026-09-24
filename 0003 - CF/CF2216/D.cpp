#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
vector<int> f(1e6 + 1);
void sol() {
    int n;
    cin >> n;
    int m = sqrt(n);
    int ans = 0;
    for (int p = 2; p <= m; p++) {
        // int r = n % p;
        // if (r != (n / p) % p) continue;
 
        int x = n;
        int lst = -1;
        int d = 0, now = 0;
        bool fg = 0;
        while (x) {
            if (d == 1) {
                fg = 1;
                break;
            }
            int tmp = x % p;
            
            if (tmp != lst || lst == -1) {
                if (now) d = gcd(d, now);
                now = 1;
            } else {
                now++;
            }
            lst = tmp;
            x /= p;
        }
        if (fg) continue;
        d = gcd(d, now);
        ans += f[d];
    }
    vector<int> a;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0 && (i - 1) > m) a.push_back(i - 1);
        if (i * i != n && (n / i - 1) > m) a.push_back(n / i - 1);
    }
    for (auto p : a) {
        int r = n % p;
        if (r != (n / p) % p) continue;
        ans += f[2];
    }
    
    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    for (int i = 2; i <= 1e6; i++) {
        for (int j = i; j <= 1e6; j += i) {
            f[j]++;
        }
    }
 
    int t;
    cin >> t;
    while (t--) sol();
}
