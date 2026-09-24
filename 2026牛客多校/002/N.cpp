#include <bits/stdc++.h>

using namespace std;

#define int long long

void sol() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }
    int sum = pre[n];
    int ans = 0;

    if (k & 1) {
        int m = k / 2;
        for (int i = m + 1; i + m <= n; i++) {
            int old = pre[m] + pre[i + m] - pre[i - 1];
            int now = k * a[i];
            ans = max(ans, sum - old + now);
        }
    } else {
        int m = k / 2;
        for (int i = m; i + m <= n; i++) {
            int old = pre[m - 1] + pre[i + m] - pre[i - 1];
            int now = m * (a[i] + a[i + 1]);
            ans = max(ans, sum - old + now);
        }
    }

    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        sol();
    }
}

/*
2
6 3
1 1 4 5 1 4
4 2
1 3 6 10
*/