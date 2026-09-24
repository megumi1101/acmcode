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

    multiset<int> sl, sr;
    sl.insert(inf), sr.insert(inf);
    int lst = 1;
    for (int i = 1; i <= n; i++) {
        sr.insert(T - a[i - 1] + f[i - 1]);
        while (lst <= i) {
            if (T - (2 * a[i] - 2 * a[lst]) <= 0) {
                sr.extract(T -  a[lst - 1] + f[lst - 1]);
                sl.insert(-a[lst - 1] -2 * a[lst] + f[lst - 1]);
                lst++;
            } else {
                break;
            }
        }

        f[i] = min(f[i], 3 * a[i] + *sl.begin());
        f[i] = min(f[i], a[i] + *sr.begin());
    }

    cout << f[n] + E - a[n] << "\n";
}