#include <bits/stdc++.h>

using namespace std;

#define int long long

void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> pos(2 * n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int aj = 1; aj * a[i] <= 2 * n; aj++) {
            int j = pos[aj];
            if (j > i && aj * a[i] == i + j) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
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