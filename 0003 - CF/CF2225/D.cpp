#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
const int mod = 998244353;
void sol() {
    int x, n;
    cin >> n >> x;
    auto get0 = [&](int x) -> int {
        return x / 4 + (x % 4 >= 3) + 1;
    };
    auto get1 = [&](int x) -> int {
        return x / 4 + (x % 4 >= 1);
    };
    int n_0 = get0(n) % mod;
    int x_0 = get0(x - 1) % mod;
    int n_1 = get1(n) % mod;
    int x_1 = get1(x - 1) % mod;
    cout << ((n_0 - x_0 + mod) * x_0 % mod + (n_1 - x_1 + mod) * x_1 % mod) % mod << "\n";
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
