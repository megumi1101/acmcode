#include <bits/stdc++.h>

using namespace std;

void sol() {
    int n;
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        if (i == 0) {
            cout << "4 ";
        } else if (i == 2 * n - 1) {
            cout << -n << "\n";
        } else if (i & 1) {
            cout << "-1 ";
        } else {
            cout << "2 ";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        sol();
    }
}