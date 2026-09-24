#include <bits/stdc++.h>

using namespace std;

#define int long long

void sol() {
    int n, m;
    cin >> n >> m;
    n = min(n, m + 1);
    cout << n * (n - 1) / 2 - m << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        sol();
    }
}

/*
3
3 2
4 6
5 3
*/