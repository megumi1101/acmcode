#include <bits/stdc++.h>
 
using namespace std;
 
 
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) {
        int d1 = 1;
        int d2 = 1;
        if (i != 1) d1 = gcd(a[i], a[i - 1]);
        if (i != n) d2 = gcd(a[i], a[i + 1]);
        int lc = lcm(d1, d2);
        if (lc < a[i]) {
            a[i] = lc;
            ans++;
        }
    }
    cout << ans << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
