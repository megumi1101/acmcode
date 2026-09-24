#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
const int inf = 1e18;
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        if (i & 1) a[n + 1 - i] = n + 1 - (i + 1) / 2;
        else a[n + 1 - i] = i / 2;
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int T;
    cin >> T;
    while (T--) sol();
}
