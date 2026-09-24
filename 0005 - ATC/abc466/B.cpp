#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> c(n + 1), s(n + 1);
    
    
    vector<int> mx(m + 1, -1);
    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> s[i];
        mx[c[i]] = max(mx[c[i]], s[i]);
    }
    for (int i = 1; i <= m; i++) {
        cout << mx[i] << " ";
    }
}