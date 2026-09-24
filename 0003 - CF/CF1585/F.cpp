#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    const int mod = 998244353;
    void main() {
        int n;
        cin >> n;
        vector<int> a(n + 5), st;
        vector<vector<int>> f(n + 5, vector<int>(2)), sum(n + 5, vector<int>(2));
        for (int i = 1; i <= n; i++) cin >> a[i];
        f[0][0] = 1;
        sum[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            int res = 0;
            while (!st.empty() && a[st.back()] >= a[i]) st.pop_back();
            if (!st.empty()) res = st.back();
            st.push_back(i);
            for (int j = 0; j < 2; j++) {
                if (res) (f[i][j] += f[res][j]) %= mod;
                (f[i][j] += a[i] * sum[i - 1][j ^ 1] % mod) %= mod;
                if (res) f[i][j] -= a[i] * sum[res - 1][j ^ 1];
                (((f[i][j] %= mod) += mod) %= mod);
                sum[i][j] = (sum[i - 1][j] + f[i][j]) % mod;
            }
        }
        int ans = f[n][0] - f[n][1];
        if (n & 1) ans = -ans;
        (((ans %= mod) += mod) %= mod);
        cout << ans;
    }
    #undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
