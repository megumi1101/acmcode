#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<array<int, 3>> v;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y, i});
    }
    sort(v.begin(), v.end());
    cout << 2 * n - 1 << "\n";
    for (int i = 0; i < n; i++) cout << v[i][2] << " ";
    for (int i = n - 2; i >= 0; i--) cout << v[i][2] << " ";
    
}