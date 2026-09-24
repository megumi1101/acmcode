#include <bits/stdc++.h>

using namespace std;

#define int long long

void sol() {
    int n;
    cin >> n;

    multiset<int> s;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
        sum += x;
    }

    if (sum <= 0) {
        cout << "-1\n";
        return;
    }

    int cur = 0;
    while (!s.empty()) {
        auto it = s.upper_bound(-cur);
        cur += *it;
        cout << cur << " ";
        s.erase(it);
    }

    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) sol();
}