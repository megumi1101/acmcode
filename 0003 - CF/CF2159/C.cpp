#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
const int inf = 1e9 + 10;
const int mod = 1e9 + 7;
 
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i <= n; i++) cin >> a[i];
    
    vector<int> f(n + 1), g(n + 1);
    g[0] = 1;
    f[1] = 1;
    g[1] = 2;
    for (int i = 2; i <= n; i++) {
        f[i] = g[i - 1];
        f[i] += (i - 1) * g[i - 2] % mod;
        f[i] %= mod;
        g[i] = f[i] + g[i - 1];
        g[i] %= mod;
    }
 
    vector<int> vis(n + 1);
    vector<pair<int, int>> p;
    for (int i = 1; i < n; i++) {
        int x = i, y = a[i];
        if (y == -1) {
            continue;
        } else if (y == 0 || x == y) {
            vis[i]++;
        } else {
            if (x > y) swap(x, y);
            p.push_back({x, y});
        }
    }
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    for (auto [x, y] : p) {
        if (x > n || y > n) {
            cout << "0\n";
            return;
        }
        vis[x]++;
        vis[y]++;
        if (vis[x] >= 2 || vis[y] >= 2) {
            cout << "0\n";
            return;
        }
    }
 
    int cnt = n;
    for (auto x : vis) if (x) cnt--;
    if (vis[n]) {
        cout << g[cnt] << "\n";
    } else {
        cout << f[cnt] << "\n";
    }
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
