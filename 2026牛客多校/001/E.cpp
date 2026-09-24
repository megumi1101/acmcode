#include<bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 998244353;


signed main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int sum = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += (i - 1) * a[i] - sum;
        sum += a[i];
    }
    cout << ans << "\n";
}