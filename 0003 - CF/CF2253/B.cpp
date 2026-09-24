#include <bits/stdc++.h>

using namespace std;

#define int long long

void sol() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    vector<pair<int, int>> p;
    int lst = -1;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == lst) {
            cnt++;
        } else {
            if (lst != -1) p.push_back({lst, cnt});
            lst = a[i];
            cnt = 1;
        }
    }
    if (cnt) {
        p.push_back({lst, cnt});
    }

    int ans = p.size();
    int tt = 0;

    for (int i = 0; i + 1 < p.size(); i++) {
        if (p[i].second >= 2 && p[i + 1].second >= 2) tt = max(tt, 2LL);
        if (p[i].second >= 2) {
            if (i + 2 >= p.size() || p[i].first != p[i + 2].first) {
                tt = max(tt, 1LL);
            }
        }
    }

    for (int i = 1; i < p.size(); i++) {
        if (p[i].second >= 2) {
            if (i - 2 < 0 || p[i].first != p[i - 2].first) {
                tt = max(tt, 1LL);
            }
        }
        
    }

    cout << ans + tt << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) sol();
}