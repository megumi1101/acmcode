// AtCoder user: lnxbb
// Contest: agc002
// Problem: agc002_c
// Submission: https://atcoder.jp/contests/agc002/submissions/75209446
// Language: C++23 (GCC 15.2.0)

#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int n, L;
    cin >> n >> L;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        if (a[i] + a[i + 1] >= L) {
            cout << "Possible\n";
            for (int j = 1; j < i; j++) {
                cout << j << "\n";
            }
            for (int j = n - 1; j > i; j--) {
                cout << j << "\n";
            }
            cout << i << "\n";
            return 0;
        }
    }
    cout << "Impossible\n";
}