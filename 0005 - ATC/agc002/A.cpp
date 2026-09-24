// AtCoder user: lnxbb
// Contest: agc002
// Problem: agc002_a
// Submission: https://atcoder.jp/contests/agc002/submissions/75208366
// Language: C++23 (GCC 15.2.0)

#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int a, b;
    cin >> a >> b;
    if (a <= 0 && b >= 0) {
        cout << "Zero\n";
    } else if (b < 0) {
        if ((b - a + 1) & 1) {
            cout << "Negative\n";
        } else {
            cout << "Positive\n";
        }
    } else {
        cout << "Positive\n";
    }
}