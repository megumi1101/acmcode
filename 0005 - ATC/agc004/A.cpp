// AtCoder user: lnxbb
// Contest: agc004
// Problem: agc004_a
// Submission: https://atcoder.jp/contests/agc004/submissions/75482508
// Language: C++23 (GCC 15.2.0)

#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> v(3);
    for (auto &x : v) cin >> x;
    sort(v.begin(), v.end());
    if ((v[0] & 1) && (v[1] & 1) && (v[2] & 1)) {
        cout << v[0] * v[1] << '\n';
    } else {
        cout << "0\n";
    }
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