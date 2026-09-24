#include <bits/stdc++.h>
 
using namespace std;
 
void sol() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.rbegin(), a.rend());
    a.erase(unique(a.begin(), a.end()), a.end());
    if (a.size() == n) {
        for (auto x : a) cout << x  << " ";
        cout << "\n";
    } else {
        cout << "-1\n";
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
