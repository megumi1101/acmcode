#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e18;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> a(2);
    a[0].resize(n);
    a[1].resize(m);
    for (int i = 0; i < n; i++) {
        cin >> a[0][i].first;
        a[0][i].second = i + 1;
    }
    for (int i = 0; i < m; i++) {
        cin >> a[1][i].first;
        a[1][i].second = i + 1;
    }

    for (auto &v : a) sort(v.begin(), v.end());

    int l = (n + m) * k, r = inf, ans = inf;
    vector<array<int, 3>> qrs, tans;

    auto check = [&](int mid, int op) -> bool {
        qrs.clear();
        vector<int> pos = {n - 1, m - 1};
        int t = mid - k;
        while (pos[0] != -1 || pos[1] != -1) {
            if (pos[op] != -1) {
                if (a[op][pos[op]].first > t) {
                    return 0;
                } else {
                    qrs.push_back({t, op, a[op][pos[op]].second});
                    pos[op]--;
                }
            } 

            op ^= 1;
            t -= k;
        }

        tans = qrs;
        return 1;
    };

    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid, 0) || check(mid, 1)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    reverse(tans.begin(), tans.end());
    cout << ans << "\n";
    for (auto[i, j, k] : tans) cout << i << " " << j << " " << k << "\n";
}

/*
5 5 2
2 1 13 19 11
12 18 19 7 8
*/