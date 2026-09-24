#include <bits/stdc++.h>
 
using namespace std;
 
namespace Std {
    #define int long long
	const int N = 3e5 + 10;
	const int inf = 1e18;
	const int mod = 998244353;
	int f[1005][2005][2][2];
    void sol() {
		int n, k;
		cin >> n >> k;
		f[1][2][0][0] = 1;
		f[1][3][0][1] = 1;
		f[1][3][1][0] = 1;
		f[1][2][1][1] = 1;
		for (int i = 2; i <= n; i++) {
			for (int j = 2; j <= k + 1; j++) {
				f[i][j][0][0] = (f[i - 1][j][0][0] + f[i - 1][j][0][1] + f[i - 1][j][1][0] + f[i - 1][j - 1][1][1]) % mod;
				f[i][j][1][1] = (f[i - 1][j - 1][0][0] + f[i - 1][j][0][1] + f[i - 1][j][1][0] + f[i - 1][j][1][1]) % mod;
				f[i][j][0][1] = (f[i - 1][j - 1][0][0] + f[i - 1][j][0][1] + f[i - 1][j - 2][1][0] + f[i - 1][j - 1][1][1]) % mod;
				f[i][j][1][0] = (f[i - 1][j - 1][0][0] + f[i - 1][j - 2][0][1] + f[i - 1][j][1][0] + f[i - 1][j - 1][1][1]) % mod;
			}
		}
		cout << (f[n][k + 1][0][0] + f[n][k + 1][0][1] + f[n][k + 1][1][0] + f[n][k + 1][1][1]) % mod;
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        // cin >> T;
        while(T--) sol();
    }
    #undef int
}
 
int main() {
    return Std::main(), 0;
}
