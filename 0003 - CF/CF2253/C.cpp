#include <bits/stdc++.h>

using namespace std;

#define int long long

void sol() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<int> a(x), b(y);
    vector<int> vis(n + m + 1);
    for (auto &i : a) {
        cin >> i;
        if (vis[i] == 0) vis[i] += 1;
    }

    for (auto &i : b) {
        cin >> i;
        if (vis[i] <= 1) vis[i] += 2;
    }
    // sort(a.rbegin(), a.rend());
    // sort(b.rbegin(), b.rend());
    vector<int> all;
    for (auto &i : a) all.push_back(i);
    for (auto &i : b) all.push_back(i);
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    sort(all.rbegin(), all.rend());

    vector<int> cnt(4);
    int ans = 0;
    for (int i = 0; i < all.size(); i++) {
        int t = vis[all[i]];
        if (t == 1) {
            if (cnt[1] + 1 > n) {
                continue;
            }
        } else if (t == 2) {
            if (cnt[2] + 1 > m) {
                continue;
            }
        }
        cnt[t]++;
        ans += all[i];
        if (cnt[1] + cnt[2] + cnt[3] == n + m - 1) {
            break;
        }
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) sol();
}