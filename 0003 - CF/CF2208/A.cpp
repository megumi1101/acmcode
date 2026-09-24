#include <bits/stdc++.h>
 
using namespace std;
 
 
void sol() {
    int n;
    cin >> n;
    vector<int> a(n * n + 1);
    for (int i = 1; i <= n * n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    for (auto x : a) if (x > n * n - n) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) sol();
}
