#include <bits/stdc++.h>
 
using namespace std;
 
void sol() {
    int x, y, z;
    cin >> x >> y >> z;
    if ((x & y) == (x & z) && (x & y) == (z & y)) cout << "YES\n";
    else cout << "NO\n";
}
 
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
 
    int T;
    cin >> T;
    while (T--) sol();
}
