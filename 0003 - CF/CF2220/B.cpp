#include <bits/stdc++.h>
 
using namespace std;
 
void sol() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    a[0] = n + 1;
    int cnt = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == a[i - 1]) cnt++;
        else cnt = 1;
        ans = max(ans, cnt);
    }
    ans = max(ans, cnt);
    if (ans >= m) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
