#include <bits/stdc++.h>
 
using namespace std;
 
void sol() {
    int n, k;
    cin >> n >> k;
    vector<int> vis(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        vis[x] = 1;
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (!vis[i]) {
            ans = i;
            break;
        }
    }
    ans = min(ans, k - 1);
    cout << ans << "\n";
}
 
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
 
    int T;
    cin >> T;
    while (T--) sol();
}
