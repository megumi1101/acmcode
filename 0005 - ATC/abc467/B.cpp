#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    vector<string> s(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> s[i];
        if (s[i] == "keep") {
            ans += b[i] - a[i];
        }
    }
    cout << ans << "\n";
}