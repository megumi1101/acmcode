#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    if (w * 100 * 100 >= 25 * h * h ) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}