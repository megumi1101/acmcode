#include <bits/stdc++.h>

using namespace std;

#define int long long

void sol() {
    int n;
    cin >> n;
    
    vector<int> a(n + 1);
    vector<int> vis(1005, 0);

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        vis[a[i]]++;
        sum += a[i];
    }

    int mxi = -1;
    for (int i = 1; i <= 1000; i++) {
        if (vis[i]) {
            if (mxi == -1) {
                mxi = i;
            } else {
                if (vis[i] > vis[mxi]) {
                    mxi = i;
                }
            }
        }
    }
    int ct = (n - vis[mxi]) + 2;
    ct = min(ct, vis[mxi]);
    int d = vis[mxi] - ct;
    sum -= d * mxi;
    cout << sum << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) sol();
} 