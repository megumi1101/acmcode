// AtCoder user: lnxbb
// Contest: agc002
// Problem: agc002_b
// Submission: https://atcoder.jp/contests/agc002/submissions/75209305
// Language: C++23 (GCC 15.2.0)

#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ed(n + 1);
    vector<int> has(n + 1, 1);
    vector<int> vis(n + 1);
    vis[1] = 1;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        has[x]--;
        has[y]++;
        if (vis[x]) {
            vis[y] = 1;
            if (has[x] == 0) vis[x] = 0;
        }
    }
    
    
    
    int ans = 0;
    for (int i = 1; i <= n; i++) if (vis[i]) ans++;
    cout << ans << "\n";
}