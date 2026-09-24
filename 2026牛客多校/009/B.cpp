#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int ans = n;
    vector<int> visx(n + 1, n), visy(n + 1, n);
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        visx[x]--;
        visy[y]--;
        ans = min(ans, visx[x]);
        ans = min(ans, visy[y]);
    }

    cout << ans << "\n";
}

/*
4 5
1 1
1 3
2 2
3 2
4 2
*/