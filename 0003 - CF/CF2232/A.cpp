#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int ans = n + 1;
    for (int i = 1; i <= n; i++) {
        int x = 0, y = 0;
        for (int j = 1; j <= n; j++) {
            if (j != i) {
                if (a[j] > a[i]) x++;
                else if (a[j] < a[i]) y++;
            }
        }
        ans = min(ans, max(x, y));
    }
    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
