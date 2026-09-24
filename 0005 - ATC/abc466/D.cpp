#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> r(m + 1), c(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> r[i] >> c[i];
    }

    vector<int> visr(n + 1), visc(n + 1);
    int ans = 0;
    for (int i = m; i >= 1; i--) {
        if (!visr[r[i]] && !visc[c[i]]) ans++;
        visr[r[i]] = 1;
        visc[c[i]] = 1;
    }
    cout << ans;
}