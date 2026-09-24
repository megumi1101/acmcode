#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
void sol() {
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    vector<int> ans(3, 0);
    ans[0] += m / a * 6;
    ans[1] += m / b * 6;
    ans[2] += m / c * 6;
    ans[0] -= m / lcm(a, b) * 3;
    ans[1] -= m / lcm(a, b) * 3;
    ans[0] -= m / lcm(a, c) * 3;
    ans[2] -= m / lcm(a, c) * 3;
    ans[1] -= m / lcm(b, c) * 3;
    ans[2] -= m / lcm(b, c) * 3;
    ans[0] += m / lcm(lcm(b, c), a) * 2;
    ans[1] += m / lcm(lcm(b, c), a) * 2;
    ans[2] += m / lcm(lcm(b, c), a) * 2;
    for (int i = 0; i < 3; i++) cout << ans[i] << " ";
    cout << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) sol();
}
