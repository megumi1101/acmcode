#include <bits/stdc++.h>
 
using namespace std;
 
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    vector<int> posa(n + 1), posb(n + 1), posc(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i], posa[a[i]] = i;
    for (int i = 1; i <= n; i++) cin >> b[i], posb[b[i]] = i;
    for (int i = 1; i <= n; i++) cin >> c[i], posc[c[i]] = i;
    vector<pair<int, char>> lst(n + 1);
    vector<int> vis(n + 1);
    vis[1] = 1;
    int mxa = 0, mxb = 0, mxc = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) continue;
        for (int j = a[i] - 1; j > mxa; j--) {
            if (posa[j] < i) continue;
            vis[posa[j]] = 1;
            lst[posa[j]] = {i, 'q'};
        }
        for (int j = b[i] - 1; j > mxb; j--) {
            if (posb[j] < i) continue;
            vis[posb[j]] = 1;
            lst[posb[j]] = {i, 'k'};
 
        }
        for (int j = c[i] - 1; j > mxc; j--) {
            if (posc[j] < i) continue;
            vis[posc[j]] = 1;
            lst[posc[j]] = {i, 'j'};
 
        }
        mxa = max(a[i], mxa);
        mxb = max(b[i], mxb);
        mxc = max(c[i], mxc);
    }
    if (!vis[n]) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        vector<pair<char, int>> ans;
        int u = n;
        while (1) {
            ans.push_back({lst[u].second, u});
            u = lst[u].first;
            if (u == 1) break;
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for (auto[x, c] : ans) {
            cout << x << " " << c << "\n";
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
