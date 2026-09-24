#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int mod = 998244353;
void sol() {
    int n, k;
    cin >> n >> k;
    int m = k - n;
    if (m < 0 || m > n - 1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    if (m == 0) {
        for (int i = 1; i <= n; i++) {
            cout << i << " " << i << " ";
        }
        cout << "\n";
        return;
    }
    int p = m + 1;
    vector<int> a;
    a.reserve(2 * n);
    a.push_back(1);
    a.push_back(2);
    for (int i = 3; i <= p; i++) {
        a.push_back(i - 2);
        a.push_back(i);
    }
    a.push_back(p - 1);
    a.push_back(p);
 
    for (int i = p + 1; i <= n; i++) {
        a.push_back(i);
        a.push_back(i);
    }
    for (int i = 0; i < 2 * n; i++) {
        cout << a[i] <<  " ";
    }
    cout << "\n";
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
