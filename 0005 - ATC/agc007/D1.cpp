#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e18;
signed main() {
    int n, E, T;
    cin >> n >> E >> T;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> f(n + 1, inf);
    f[0] = 0;

    
    for (int i = 1; i <= n; i++) {
        for (int l = 1; l <= i; l++) {
            f[i] = min(f[i], a[i] - a[l - 1] + 2 * (a[i] - a[l]) + max(0ll, T - 2 * (a[i] - a[l])) + f[l - 1]);
        }
    }

    cout << f[n] + E - a[n] << "\n";
}