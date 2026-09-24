#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> p(n), q(n);
    for (auto &i : p) cin >> i;
    for (auto &i : q) cin >> i;
    int cnt = 0;
    next_permutation(p.begin(), p.end());
    while (p < q) {
        cnt++;
        next_permutation(p.begin(), p.end());
    }

    cout << cnt << "\n";
}