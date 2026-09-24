#include <bits/stdc++.h>
 
using namespace std;
 
 
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int mx = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == mx) cnt++;
    }
    cout << cnt << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
