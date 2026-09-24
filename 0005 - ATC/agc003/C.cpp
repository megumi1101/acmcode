// AtCoder user: lnxbb
// Contest: agc003
// Problem: agc003_c
// Submission: https://atcoder.jp/contests/agc003/submissions/75393077
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
    vector<int> all;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        all.push_back(a[i]);
    }
    
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    for (int i = 1; i <= n; i++) a[i] = lower_bound(all.begin(), all.end(), a[i]) - all.begin() + 1;
    
    for (int i = 1; i <= n; i += 2) {
        if (a[i] % 2 == 0) ans++;
    }

    cout << ans << "\n";
}

/*
4
4
0
3
2

*/