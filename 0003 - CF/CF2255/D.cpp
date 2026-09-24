#include <bits/stdc++.h>

using namespace std;

#define int long long

void sol() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int tim = n; tim <= n + 35; tim++) {
        priority_queue<int> q;
        for (auto x : a) {
            q.push(x);
        }
        for (int k = tim - 1; k >= 0; k--) {
            int u = q.top();
            q.pop();
            if (k < 30) {
                u -= (1LL << k);
                if (u > 0) q.push(u);
            }
            if (q.empty()) {
                cout << tim << "\n";
                return;
            }
        }
    }
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
