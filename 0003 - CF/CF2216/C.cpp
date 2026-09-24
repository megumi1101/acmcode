#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
void sol() {
    int n, k, p, q;
    cin >> n >> k >> p >> q;
    vector<int> a(n + 5), c(n + 5), d(n + 5), pre(n + 5), suf(n + 5), prec(n + 5), pred(n + 5);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        prec[i] = c[i] = a[i] % p;
        pred[i] = d[i] = a[i] % q % p;
        pre[i] = suf[i] = min(c[i], d[i]);
        pre[i] += pre[i - 1];
        prec[i] += prec[i - 1];
        pred[i] += pred[i - 1];
    }
    for (int i = n; i >= 1; i--) {
        suf[i] += suf[i + 1];
    }
    int ans = 1e18;
    for (int i = 0; i + k <= n; i++) {
        ans = min(ans, pre[i] + min(prec[i + k] - prec[i], pred[i + k] - pred[i]) + suf[i + k + 1]);
    }
    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t;
    cin >> t;
    while (t--) sol();
}
