#include <bits/stdc++.h>

using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<string> gs(n), ws(n);
    vector<string> alls;
    vector<int> g(n), w(n);
    for (int i = 0; i < n; i++) {
        cin >> gs[i] >> ws[i];
        alls.push_back(gs[i]);
        alls.push_back(ws[i]);
    }
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    for (int i = 0; i < n; i++) g[i] = lower_bound(alls.begin(), alls.end(), gs[i]) - alls.begin();
    for (int i = 0; i < n; i++) w[i] = lower_bound(alls.begin(), alls.end(), ws[i]) - alls.begin();

    int all = (1 << n);
    vector<int> f(all);
    for (int i = 0; i < all; i++) {
        for (int bit = 0; bit < n; bit++) {
            if ((i >> bit) & 1) continue;
            if (i == 0) f[1 << bit] |= 1 << bit;
            else {
                for (int t = 0; t < n; t++) if ((f[i] >> t) & 1) {
                    if (g[t] == g[bit] || w[t] == w[bit]) {
                        f[i | 1 << bit] |= (1 << bit);
                        break;
                    }
                }
            } 
        }
    }

    int ans = 0;
    for (int i = 0; i < all; i++) {
        if (f[i]) {
            ans = max(ans, popcount((unsigned int)i));
        }
    }
    cout << n - ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        sol();
    }
}