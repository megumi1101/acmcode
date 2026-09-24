// AtCoder user: lnxbb
// Contest: agc003
// Problem: agc003_a
// Submission: https://atcoder.jp/contests/agc003/submissions/75388417
// Language: C++23 (GCC 15.2.0)

#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    

    string s;
    cin >> s;
    int N = 0, S = 0, W = 0, E = 0;
    for (auto c : s) {
        if (c == 'N') {
            N = 1;
        } else if (c == 'S') {
            S = 1;
        } else if (c == 'W') {
            W = 1;
        } else {
            E = 1;
        }
    }

    if (N ^ S == 0 && W ^ E == 0) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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