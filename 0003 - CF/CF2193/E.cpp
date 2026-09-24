#include <bits/stdc++.h>
 
using namespace std;
#define int long long
const int inf = 1e18;
void sol() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    vector<int> f(n + 1, inf);
    f[1] = 0;
    for (auto x : a) {
        int res = 1;
        if (x == 1) continue;
        for (int res = x, i = 1; res <= n; res = res * x, i++) {
            for (int j = 1; j * res <= n; j++) {
                f[j * res] = min(f[j * res], f[j] + i);
            }
        }
    }
    if (a[0] != 1) f[1] = -1;
    else f[1] = 1;
    for (int i = 2; i <= n; i++) if (f[i] >= inf) f[i] = -1;
    for (int i = 1; i <= n; i++) cout << f[i] << " ";
    cout << '\n';
}
 
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
