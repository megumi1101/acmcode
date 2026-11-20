#include <bits/stdc++.h>

using namespace std;

#define int long long

void sol() {
    int n;
    cin >> n;
    n = (1 << n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    auto sol = [&](auto &&self, int l, int r)  -> array<int, 3> {
        if (l == r) {
            return {0, a[l], a[l]};
        }
        int mid = (l + r) >> 1;
        auto [t0, l0, r0] = self(self, l, mid);
        auto [t1, l1, r1] = self(self, mid + 1, r);
        
        int L = max({l0 - t1, l1 - t0, 0LL});
        int R = min(r0, r1);
        if (L <= R) {
            return {t0 + t1, L, R};
        } else return {t0 + t1 + L - R, R, R};
    };

    auto [x, y, _] = sol(sol, 0, n - 1);
    cout << x + y << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        sol();
    }
}

/*
5
0
100000
1
114 514
2
1 1 1 1
3
0 13 0 0 0 7 2 1
4
1 2 2 1 3 3 3 3 1 0 0 0 0 0 0 0
*/