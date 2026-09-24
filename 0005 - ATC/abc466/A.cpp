#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    for (auto i : a) {
        if (i >= 0) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}