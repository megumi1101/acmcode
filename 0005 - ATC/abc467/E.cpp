#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(n);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) cin >> b[i];

    auto norm = [&](int &k) -> void {
        k %= m;
        if (k < 0) k += m;
    };

    vector<pair<int, int>> p;
    int res = 0;
    p.push_back({m - 1, 1});
    for (int i = 2; i <= n; i++) {
        int k = b[i - 1] - (a[i] + a[i - 1]);
        // cerr << " k == "<<  k << " ";
        norm(k);
        if (i & 1) {
            p.push_back({m - 1 - k, 1});
        } else {
            p.push_back({k, 0});
        }
        
        a[i] += k;
        res += k;
        norm(a[i]);
    }

    int ans = res;
    // cerr << "ans = " << ans << "\n";
    sort(p.begin(), p.end());
    
    int coef = n & 1;
    int l = 0;
    while (l < n) {
        int r = l;
        if (p[l].first == m - 1) break;
        while (r + 1 < n && p[r + 1].first == p[l].first) r++;
        int t = p[l].first * coef + coef;
        for (int i = l; i <= r; i++) {
            if (p[i].second == 1) {
                res -= m;
            } else {
                res += m;
            }
        }
        ans = min(ans, t + res);
        l = r + 1;
    }
    cout << ans << "\n";
}