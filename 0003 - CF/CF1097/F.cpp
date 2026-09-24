#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;

    int res = 0;
    for (int i = 1; i <= n; i++) {
        res += (n / i);
    }
    cout << res;
}