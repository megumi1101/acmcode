#include <bits/stdc++.h>

using namespace std;

#define int long long

void sol() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> pre(n + 1);
    vector<map<int, int>> mp(2);
    int ans = 0;
    mp[0][0]++;

    vector<int> suf(n + 2);
    int sum = 0;
    for (int i = n; i >= 1; i--) {
        int op = (i & 1) ? 1 : -1;
        suf[i] = suf[i + 1] + op * a[i];
        sum += op * a[i];
    }

    for (int i = 1; i <= n; i++) {
        int op = (i & 1) ? 1 : -1;
        pre[i] += pre[i - 1] + op * a[i];
        ans += mp[i & 1][k - suf[i + 1]];
        ans += mp[(i & 1) ^ 1][k + suf[i + 1]];
        mp[i & 1][pre[i]]++;
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