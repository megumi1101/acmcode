#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> p(n);
    for (int &v : p) cin >> v;
    int d = (x - p[k] + n) % n;
    for (int i = 0; i < n; i++) {
        cout << (p[i] + d) % n << " \n"[i == n - 1];
    }
    return 0;
}