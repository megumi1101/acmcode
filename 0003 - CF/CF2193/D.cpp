#include <bits/stdc++.h>
 
using namespace std;
#define int long long
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> sumb(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> sumb[i], sumb[i] += sumb[i - 1];
    sort(a.rbegin(), a.rend());
 
    int y = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (y != n) {
            if (sumb[y + 1] <= i) y++;
        }
        ans = max(ans, y * a[i - 1]);
    }
    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
