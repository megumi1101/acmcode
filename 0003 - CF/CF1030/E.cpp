#include <bits/stdc++.h>
 
using namespace std;
 
namespace Std {
    #define int long long
	const int N = 3e5 + 10;
	const int inf = 1e18;
	int turn(int x) {
		int res = 0;
		while(x) {
			res += x % 2;
			x /= 2;
		}
		return res;
	}
    void sol() {
		int n;
		cin >> n;
		int f[n + 5][2];
		int a[n + 5];
		int sum[n + 5];
		int ans = 0;
		memset(f, 0, sizeof(f));
		memset(sum, 0, sizeof(sum));
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			a[i] = __builtin_popcountll(a[i]);
			sum[i] = sum[i - 1] + a[i];
			f[i][0] = ((a[i] & 1) == 0) + f[i - 1][a[i] & 1];
			f[i][1] = ((a[i] & 1) == 1) + f[i - 1][(a[i] & 1) ^ 1];
			ans += f[i][0];
		}
		// cout << ans << "\n";
		for (int i = 1; i <= n; i++) {
			int res = 0, mx = 0;
			for (int j = i; j <= min(n, i + 70); j++) {
				res += a[j];
				mx = max(a[j], mx);
				if (2 * mx > res && ((sum[j] - sum[i - 1]) & 1) == 0) ans--;
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
