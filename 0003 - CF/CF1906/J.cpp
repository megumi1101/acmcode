#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
const int mod = 998244353;
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector f(n + 2, vector(n + 2, (int)0));
    f[1][1] = 1;
    vector<int> l(n + 1);
    for (int i = 1; i <= n; i++) {
        int j = i;
        l[i] = i;
        while (j != n && a[j + 1] > a[j]) {
            j++;
            l[j] = i;
        }
        i = j;
    }
    
    vector<int> p2(n + 1, 1);
    for (int i = 1; i <= n; i++) p2[i] = p2[i - 1] * 2 % mod;
    for (int i = 1; i <= n; i++) {
        vector<int> sumf(n + 1);
        for (int j = i; j <= n; j++) {
            sumf[j] = sumf[j - 1] + f[i][j] * p2[j - i] % mod;
            sumf[j] %= mod;
        }
        for (int j = i; j <= n; j++) {
            f[i + 1][j] = sumf[j] - sumf[max(l[j] - 2, (int)0)] + mod;
            f[i + 1][j] %= mod;
        }
    }
    
    cout << f[n + 1][n] << "\n";
}
