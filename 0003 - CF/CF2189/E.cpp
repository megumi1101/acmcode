#include <bits/stdc++.h>
 
using namespace std;
 
const int inf = 1e9;
 
void sol() {
    int n;
    string s;
    cin >> n >> s;
    s = " " + s;
 
 
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') {
            break;
        }
        if (i == n) {
            cout << "-1\n";
            return;
        }
    }
 
    if (n == 1) {
        cout << "0\n";
        return;
    }
 
    int cnt1 = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') cnt1++;
    }
    int cnt0 = n - cnt1;
    if (cnt1 >= cnt0) {
        cout << n << "\n";
        return;
    }
 
    vector<int> f(n + 1, inf);
    vector<int> pre(n + 1, 0);
    vector<int> vis(2 * n + 1, 0);
    f[0] = 0;
    int mn = inf;
    for (int i = 1; i <= n; i++) {
        int x = 1;
        if (s[i] == '0') x = -1;
        f[i] = min(f[i - 1] + x, x);
        pre[i] = pre[i - 1] + x;
    }
    for (int i = 0; i <= n; i++) {
        if (vis[n + pre[i]]) f[i] = min(f[i], -2);
        vis[n + pre[i]] = 1;
        mn = min(mn, f[i]);
    }
    if (cnt1 - cnt0 + (-1 - mn) >= 0) {
        cout << n + 1 << "\n";
        return;
    }
 
    vector<int> g(n + 2, inf);
    vector<int> suf(n + 2, 0);
    fill(vis.begin(), vis.end(), 0);
    g[n + 1] = 0;
    mn = inf;
    for (int i = n; i >= 1; i--) {
        int x = 1;
        if (s[i] == '0') x = -1;
        g[i] = min(g[i + 1] + x, x);
        suf[i] = suf[i + 1] + x;
    }
    for (int i = n + 1; i >= 1; i--) {
        if (vis[n + suf[i]]) g[i] = min(g[i], -2);
        vis[n + suf[i]] = 1;
        mn = min(mn, g[i]);
        if (cnt1 - cnt0 + (-2 - mn - f[i - 1]) >= 0) {
            cout << n + 2 << "\n";
            return;
        }
    }
 
    cout << n + 3 << "\n";
}
 
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
 
    int T = 1;
    cin >> T;
    while (T--) sol();
}
