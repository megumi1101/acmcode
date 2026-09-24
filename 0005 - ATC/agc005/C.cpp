// AtCoder user: lnxbb
// Contest: agc005
// Problem: agc005_c
// Submission: https://atcoder.jp/contests/agc005/submissions/75675822
// Language: C++23 (GCC 15.2.0)

#include <bits/stdc++.h>

using namespace std;

#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    sort(a.rbegin(), a.rend());

    if (n == 2) {
        if (a[0] == a[1] && a[0] == 1) {
            cout << "Possible\n";
        } else {
            cout << "Impossible\n";
        }
        return 0;
    }

    int mx = a[0];
    int mn = (mx + 1) / 2;

    if (a.back() < mn) {
        cout << "Impossible\n";
        return 0;
    }

    vector<int> cnt(mx - mn + 1, 2);
    if (mx % 2 == 0) cnt[0] = 1;
    for (auto i : a) {
        cnt[i - mn]--;
    }

    bool fg = 1;
    if (cnt[0] != 0) {
        fg = 0;
    }
    for (int i = 1; i < cnt.size(); i++) {
        if (cnt[i] > 0) fg = 0;
    }
    
    if (fg) {
        cout << "Possible\n";
    } else {
        cout << "Impossible\n";
    }
}