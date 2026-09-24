#include <bits/stdc++.h>
 
using namespace std;
#define int long long
 
vector<int> pr, mu, vis;
void init() {
    int n = 1e6;
    vis.assign(n + 5, 0);
    mu.assign(n + 5, 0);
    mu[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) {pr.push_back(i); mu[i] = -1;}
        for (auto x : pr) {
            int m = i * x;
            if (m > n) break;
            vis[i * x] = 1;
            if (i % x) {
                mu[m] = - mu[i]; 
            } else {
                break;
            }
        }
    }
}
 
vector <int> get_g (vector<int> &f) {
    vector<int> g = f;
    int n = f.size() - 1;
    for (auto p : pr) {
        if (p > n) break;
        for (int i = n / p; i >= 1; i--) {
            g[i * p] = (g[i * p] - g[i]);
        }
    }
    return g;
} 
 
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1), cnt(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i], cnt[a[i]]++;
    vector<int> f(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        if (cnt[i]) {
            for (int j = i; j <= n; j += i) {
                f[j] = 0;
            }
        }
    }
 
    auto g = get_g(f);
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            c[i] += cnt[j];
        }
        c[i] = c[i] * c[i];
    }
    
 
    int ans = 0;
    for (int d = 1; d <= n; d++) {
        ans += g[d] * c[d];
    }
    cout << ans / 2 << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int T = 1;
    init();
    cin >> T;
 
    while (T--) sol();
}
