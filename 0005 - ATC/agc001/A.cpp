// AtCoder user: lnxbb
// Contest: agc001
// Problem: agc001_a
// Submission: https://atcoder.jp/contests/agc001/submissions/74750234
// Language: C++23 (GCC 15.2.0)

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i << 1];
    }
    cout << ans << "\n";
}

/*
6
0 0
3 0
6 0
6 3
6 6
1 1
*/