#include <bits/stdc++.h>

using namespace std;

#define int long long

void sol() {
    int n;
    cin >> n;
    vector<int> a(n);
    array<int, 2> ans{};
    for (auto &i : a) {
        cin >> i;
        ans[popcount((uint64_t)i) & 1] += i;
    }
    cout << ranges::max(ans) << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) sol();
}