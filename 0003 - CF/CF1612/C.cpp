#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
	#define int long long
	const int mod = 1ll << 31;
	const int N = 1e5 + 10;
    bool pd(int n, int x, int mid) {
		int res = 0;
		if (mid <= n) {
			res += (mid + 1) * mid / 2;
		}
		else {
			res += (n + 1) * n / 2;
			mid -= n;
			res += (n - 1 + n - mid) * mid / 2;
		}
		return res < x;
	}
	void sol() {
		int n, x;
		cin >> n >> x;
        int l = 1, r = 2 * n - 1;
		int ans = 0;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (pd (n, x, mid)) l = mid + 1, ans = mid;
			else r = mid - 1;
		}
		cout << min(ans + 1, 2 * n - 1) << "\n";
	}
	void main() {
		ios::sync_with_stdio(false), cin.tie(nullptr);
		int T;
		cin >> T;
		while (T--) sol();
	}
 
	#undef int
}
 
int main() {
	return Xbbbz::main(), 0;
}
