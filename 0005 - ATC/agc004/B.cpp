// AtCoder user: lnxbb
// Contest: agc004
// Problem: agc004_b
// Submission: https://atcoder.jp/contests/agc004/submissions/75499970
// Language: C++23 (GCC 15.2.0)

#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n, 1e18);
    for (auto &i : a) cin >> i;
    
    int ans = 1e18;
    for (int t = n; t >= 1; t--) {
        int res = 0;
        for (int i = 0; i < n; i++) {
            b[i] = min(b[i], a[(i + t) % n]);
            res += b[i];
        }
        ans = min(ans, res + (n - t) * x);
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