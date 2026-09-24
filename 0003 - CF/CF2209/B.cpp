#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        int x = 0, y = 0;
        for (int j = i + 1; j <= n; j++) {
            if (a[i] > a[j]) x++;
            if (a[i] < a[j]) y++;
        }
        cout << max(x, y) << " ";
    }
    cout << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) sol();
}
