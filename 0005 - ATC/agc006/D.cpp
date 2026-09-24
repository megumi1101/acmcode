#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e9;

signed main() {
    int n;
    cin >> n;
    int m = 2 * n - 1;
    vector<int> a(m + 1);
    for (int i = 1; i <= m; i++) cin >> a[i];

    int l = 1, r = m;
    int ans = -1;
    
    auto check = [&](int x) -> bool {
        vector<int> b(m + 1);
        for (int i = 1; i <= m; i++) {
            if (a[i] >= x) b[i] = 1;
        }
        pair<int, int> t{inf, b[n] ^ (n - 1) & 1};
        for (int i = 0; i + n + 1 <= m; i++) {
            if (b[i + n] == b[i + n + 1]) {
                t = min(t, {i, b[i + n]});
                break;
            }
        }
        
        for (int i = 0; n - i - 1 >= 1; i++) {
            if (b[n - i] == b[n - i - 1]) {
                t = min(t, {i, b[n - i]});
                break;
            }
        }
        return t.second;
    };

    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << "\n";
}