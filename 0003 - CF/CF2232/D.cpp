#include <bits/stdc++.h>

#define int long long

using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] >= i) {
            cout << "NO\n";
            return;
        }
    }
    
    vector<array<int, 3>> ans;
    [&](this auto &&dfs, int x, int frm, int to) -> void {
        if (x == 0) return;
        if (a[x] == 0) {
            dfs(x - 1, frm, frm ^ to);
            ans.push_back({x, frm, to});
            dfs(x - 1, frm ^ to, to);
        } else {
            dfs(x - a[x] - 1, frm, frm ^ to);
            ans.push_back({x, frm, to});
            dfs(x - a[x] - 1, frm ^ to, frm);
            dfs(x - 1, frm, to);
        }
    } (n, 1, 3);
    cout << "YES\n";
    cout << ans.size() << "\n";
    for (auto[x, y, z] : ans) cout << x << " " << y << " " << z << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}