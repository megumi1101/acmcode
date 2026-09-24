#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    auto b = a, c = a;

    auto me = [&](array<int, 3> arr) -> int {
        vector<int> vis(4);
        for (auto x : arr) {
            if (x >= 0 && x <= 2) {
                vis[x]++;
            }
        }
        for (int i = 0; i < 4; i++) {
            if (!vis[i]) {
                return i;
            }
        }
        return 0;
    };

    for (int i = 0; i < n; i++) {
        b[i] = me({a[i], a[(i + n - 1) % n], a[(i + 1) % n]});
    }

    for (int i = 0; i < n; i++) {
        c[i] = me({b[i], b[(i + n - 1) % n], b[(i + 1) % n]});
    }

    auto d = c, e = c;

    for (int i = 0; i < n; i++) {
        d[i] = me({c[i], c[(i + n - 1) % n], c[(i + 1) % n]});
    }

    for (int i = 0; i < n; i++) {
        e[i] = me({d[i], d[(i + n - 1) % n], d[(i + 1) % n]});
    }

    if (k == 1) {
        for (auto x : b) cout << x << " ";
    } else if (k & 1) {
        for (auto x : d) cout << x << " ";
    } else {
        for (auto x : c) cout << x << " ";
    }
    cout << "\n";
}