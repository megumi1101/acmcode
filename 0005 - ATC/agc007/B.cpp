#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];

    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + n + 1;
        b[n + 1 - i] = a[i];
    }

    for (int i = 1; i <= n; i++) {
        a[p[i]] += i;
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
    for (int i = 1; i <= n; i++) cout << b[i] << " \n"[i == n];
}
