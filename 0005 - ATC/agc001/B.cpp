// AtCoder user: lnxbb
// Contest: agc001
// Problem: agc001_b
// Submission: https://atcoder.jp/contests/agc001/submissions/74750474
// Language: C++23 (GCC 15.2.0)

#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    cout << (n - gcd(n, x)) * 3ll << "\n";
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