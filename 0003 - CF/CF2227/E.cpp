#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
void sol() {
    int n;
    cin >> n;
    
    vector<int> a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
 
    auto b = a;
    for (int i = n - 1; i >= 1; i--) {
        b[i] = min(b[i], b[i + 1]);
    }
 
    vector<int> cnt(n + 1);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        sum -= b[i];
        cnt[b[i]]++;
        mx = max(mx, cnt[b[i]]);
    }
 
    cout << sum + mx - 1 << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
 
/*
6
0 0
3 0
6 0
6 3
6 6
1 1
*/
