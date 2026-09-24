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

    int lst = 1;
    for (int i = 1; i <= n; i++) {
        auto get = [&] (int x) -> int {
            if (x > i || x < 1) return inf;
            return a[i] - a[x - 1] + 2 * (a[i] - a[x]) + max(0ll, T - 2 * (a[i] - a[x])) + f[x - 1];
        };

        int t = lst;
        for (int l = lst; l <= i; l++) {
            int res = get(l);
            if (get(l) < f[i]) {
                t = l;
                f[i] = res;
            }
        }
        lst = t;
    }

    cout << f[n] + E - a[n] << "\n";
}