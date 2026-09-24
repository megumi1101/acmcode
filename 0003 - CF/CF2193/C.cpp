#include <bits/stdc++.h>
 
using namespace std;
 
void sol() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i], a[i] = max(a[i], b[i]);
    for (int i = n - 1; i >= 1; i--) {
        a[i] = max(a[i], a[i + 1]);
    }
    vector<int> sum(n + 1);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }
 
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << " ";
    }
    cout << "\n";
}
 
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
