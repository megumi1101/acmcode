#include <bits/stdc++.h>
 
using namespace std;
 
void sol() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if (gcd(n, a) == 1 && gcd(m, b) == 1 && (gcd(n, m) <= 2)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
