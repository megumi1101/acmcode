// AtCoder user: lnxbb
// Contest: agc004
// Problem: agc004_d
// Submission: https://atcoder.jp/contests/agc004/submissions/75505552
// Language: C++23 (GCC 15.2.0)

#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, K;
    cin >> n >> K;
    vector<int> a(n + 1);
    // vector<int> rd(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        // rd[a[i]]++;
    }

    // int ans1 = 0;
    // for (int i = 1; i <= n; i++) if (!rd[i]) ans1++;
    int ans0 = 0;
    if (a[1] != 1) ans0++;
    vector<vector<int>> ed(n + 1);
    for (int i = 2; i <= n; i++) {
        ed[a[i]].push_back(i);
    }

    vector<int> f(n + 1);
    [&](this auto &&dfs, int u, int fat) -> void {
        for (auto v : ed[u]) {
            dfs(v, u);
            f[u] = max(f[u], f[v]);
        }
        f[u]++;

        if (f[u] == K && fat > 1) {
            ans0++;
            f[u] = 0;
        }
    } (1, 0);

    // int d = 1;
    // for (int i = 1; i <= n; i++) {
    //     d = lcm(i, d);
    //     if (d > K) break;
    // }
    // if (K % d == 0) {
    //     ans0 = min(ans0, ans1);
    // }
    cout << ans0 << "\n";
    
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