// AtCoder user: lnxbb
// Contest: agc003
// Problem: agc003_b
// Submission: https://atcoder.jp/contests/agc003/submissions/75401378
// Language: C++23 (GCC 15.2.0)

#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n + 5);
    int res = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        res += a[i];
        if (a[i] == 0) {
            ans += res / 2;
            res = 0;
        }
    }
    ans += res / 2;

    cout << ans << "\n";
}

/*
4
4
0
3
2

*/