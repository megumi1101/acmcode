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
        int r = i;
        int l = 1;

        auto get = [&] (int x) -> int {
            if (x > i || x < 1) return inf;
            return a[i] - a[x - 1] + 2 * (a[i] - a[x]) + max(0ll, T - 2 * (a[i] - a[x])) + f[x - 1];
        };

        int ans = 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (get(mid) <= get(mid + 1)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        for (int op = ans - 2; op <= ans + 2; op++) {
            f[i] = min(f[i], get(op));
        }
    }

    cout << f[n] + E - a[n] << "\n";
}