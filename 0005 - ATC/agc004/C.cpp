// AtCoder user: lnxbb
// Contest: agc004
// Problem: agc004_c
// Submission: https://atcoder.jp/contests/agc004/submissions/75500861
// Language: C++23 (GCC 15.2.0)

#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    array<array<int, 4>, 4> col{{{0, 0, 1, 1}, {0, 1, 1, 0}, {1, 1, 0, 0}, {1, 0, 0, 1}}};
    for (auto &i : s) cin >> i;

    vector a(n, vector(m, 0ll));
    for (int i = 1; i + 1 < n; i++) {
        for (int j = 1; j + 1 < m; j++) {
            a[i][j] = col[(i - 1) % 4][(j - 1) % 4];
        }
    }
    fill(a[0].begin(), a[0].end(), 1);
    for (int i = 0; i + 1 < n; i++) a[i][m - 1] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1 || s[i][j] == '#') {
                cout << '#';
            } else {
                cout << '.';
            }
        }
        cout << "\n";
    }
    cout << "\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0 || s[i][j] == '#') {
                cout << '#';
            } else {
                cout << '.';
            }
        }
        cout << "\n";
    }
    cout << "\n";
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