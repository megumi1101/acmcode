#include <bits/stdc++.h>
 
using namespace std;
 
void sol() {
    int n;
    cin >> n;
    vector<int> a(n);
    int l = -1, r = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (l != -1 && a[i] == n - l && r == -1) {
            r = i;
        }
        if (a[i] != n - i && l == -1) {
            l = i;
        }
    }
    reverse(a.begin() + l, a.begin() + r + 1);
    for (auto x : a) cout << x << " ";
    cout << "\n";
}
 
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
