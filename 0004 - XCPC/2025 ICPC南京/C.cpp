#include <bits/stdc++.h>

using namespace std;

#define int long long

void sol() {
    int n;
    cin >> n;
    if (n & 1) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
        cout << n / 2 << " " << n / 2 << "\n";
    }
}
signed main() {
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
}