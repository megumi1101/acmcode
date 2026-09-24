#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int cnt = 0;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n - 2; i++) {
        if (a[i + 1] > a[i] && a[i + 1] > a[i + 2]) {
            cnt++;
        }
    }
    cout << cnt << "\n";
}