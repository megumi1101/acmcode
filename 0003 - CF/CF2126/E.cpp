#include <bits/stdc++.h>
 
using namespace std;
 
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    auto p = a;
    int d = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] % a[i + 1]) {
            cout << "NO\n";
            return;
        }
    }
    for (int i = n; i > 1; i--) {
        if (b[i] % b[i - 1]) {
            cout << "NO\n";
            return;
        }
    }
    vector<int> ve;
    ve.push_back(a[n]);
    ve.push_back(b[1]);
    for (int i = 1; i < n; i++) {
        ve.push_back(__gcd(a[i], b[i + 1]));
    }
    for (auto x : ve) {
        if (x != b[1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
