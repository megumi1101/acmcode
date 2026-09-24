#include <bits/stdc++.h>
 
using namespace std;
 
namespace Std {
    #define int long long
    const int N = 2e5 + 10;
    int f[55][55];
	int a[55];
	int sum[55];
	int n, m;
	bool pd(int x) {
		memset(f, 0, sizeof(f));
		f[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= min(i, m); j++) {
				for (int k = 0; k < i; k++) {
					f[i][j] |= f[k][j - 1] & (((sum[i] - sum[k]) & x) == x); 
				}
			}
		}
		return f[n][m];
	}
    void sol() {
		cin >> n >> m;
		
		memset(sum, 0, sizeof(sum));
		memset(f, 0, sizeof(f));
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			sum[i] = sum[i - 1] + a[i];
		}
		int ans = 0;
		for (int i = 62; i >= 0; i--) {
			ans ^= (1LL << i);
			if (!pd(ans)) {
				ans ^= (1LL << i);
			}
		}
		cout << ans;
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
