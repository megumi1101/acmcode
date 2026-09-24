#include <bits/stdc++.h>
 
using namespace std;
 
void sol() {
    int x, y;
    cin >> x >> y;
    int swapped = 0;
    if (x < y) swap(x, y), swapped = 1;
    int ans = 0;
    for (int i = 1; i <= x - y; i++) {
        if ((x - y) % i == 0) ans++;
    }
    if (x == y) ans++;
    cout << ans << "\n";
    if (!swapped) {
        for (int i = 1; i <= y; i++) {
            cout << "-1 ";
        }
        for (int i = 1; i <= x; i++) {
            cout << "1 ";
        }
    } else {
        for (int i = 1; i <= y; i++) {
            cout << "1 ";
        }
        for (int i = 1; i <= x; i++) {
            cout << "-1 ";
        }
    }
    cout << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
