#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> f(n + 1), a(n + 1), b(n + 1), prea(n + 1), preb(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        prea[i] = prea[i - 1] + a[i];
        preb[i] = preb[i - 1] + b[i];
    }
    
    int suma = accumulate(a.begin(), a.end(), 0ll);
    int ans = 0;
    for (int t = 1; t <= k; t++) {
        int mn = 0;
        vector<int> nf(n + 1);
        for (int i = 1; i <= n; i++) {
            nf[i] = preb[i] - prea[i] - mn;
            mn = min(preb[i] - prea[i] - f[i], mn);
            nf[i] = max(nf[i], nf[i - 1]);
        }
        ans = max(ans, nf[n]);
        f = move(nf);
    }
    cout << ans + suma << "\n";
}