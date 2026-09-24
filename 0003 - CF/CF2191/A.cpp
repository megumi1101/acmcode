#include <bits/stdc++.h>
 
using namespace std;
 
void sol() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &[i, _] : a) cin >> i;
    for (int i = 0; i < n; i++) a[i].second = (i & 1);
    sort(a.begin(), a.end());
    for (int i = 1; i < n; i++) {
        if (a[i].second == a[i - 1].second) {cout << "NO\n"; return;}
    }
    cout << "YES\n";
}
 
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
 
    int T;
    cin >> T;
    while (T--) sol();
}
