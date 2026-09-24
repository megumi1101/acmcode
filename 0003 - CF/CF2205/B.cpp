#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
 
vector<int> pr, vis;
 
void init() {
    int n = 1e5;
    vis.assign(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) pr.push_back(i);
        for (int j : pr) {
            int m = i * j;
            if (m > n) break;
            vis[m] = 1;
            if (i % j == 0) {
                break;
            }
        }
    }
}
 
 
const int mod = 998244353;
void sol() {
    int n;
    cin >> n;
    int ans = 1;
    for (auto x : pr) {
        if (n % x == 0) {
            ans *= x;
        }
        while (n % x == 0) {
            n /= x;
        }
    }
 
    if (n > 1) ans *= n;
    cout << ans << "\n";
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    init();
    cin >> t;
    while (t--) sol();
}
