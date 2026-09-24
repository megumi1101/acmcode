#include <bits/stdc++.h>
 
using namespace std;
 
void sol() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    sort(a.begin(), a.end());
    vector<int> vis(n + 1), pre(n + 1), suf(n + 1);
    
    for (int i = 0; i < n; i++) {
        vis[a[i]] = 1;
        for (int j = 0; j <= n; j++) {
            if (!vis[j]) {
                pre[i] = j;
                break;
            }
        }
    
    }
 
    fill(vis.begin(), vis.end(), 0);
 
    for (int i = n - 1; i >= 0; i--) {
        vis[a[i]] = 1;
        for (int j = 0; j <= n; j++) {
            if (!vis[j]) {
                suf[i] = j;
                break;
            }
        }
    }
 
    for (int i = 0; i < n - 1; i++) {
        if (pre[i] == suf[i + 1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
 
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
 
    int T;
    cin >> T;
    while (T--) sol();
}
