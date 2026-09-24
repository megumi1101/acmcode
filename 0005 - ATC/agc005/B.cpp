// AtCoder user: lnxbb
// Contest: agc005
// Problem: agc005_b
// Submission: https://atcoder.jp/contests/agc005/submissions/75673419
// Language: C++23 (GCC 15.2.0)

#include <bits/stdc++.h>

using namespace std;

#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> stk, L(n + 1), R(n + 1);
    for (int i = 1; i <= n; i++) {
        int lst = 0;
        while (!stk.empty() && a[i] < a[stk.back()]) {
            lst = stk.back();
            stk.pop_back();
        }

        L[i] = lst;
        if (!stk.empty()) {
            R[stk.back()] = i;
        }
        stk.push_back(i);
    }
    int rt = stk[0];

    int ans = 0;
    [&](this auto &&dfs, int u, int l, int r) -> void {
        ans += a[u] * (u - l + 1) * (r - u + 1);
        if (L[u]) dfs(L[u], l, u - 1);
        if (R[u]) dfs(R[u], u + 1, r);
    } (rt, 1, n);

    cout << ans << "\n";
}