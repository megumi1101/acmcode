#include <bits/stdc++.h>
 
using namespace std;
 
void sol() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
    if (sum & 1 || (n * k + 1) & 1) {
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
