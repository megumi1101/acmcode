#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
	#define int long long
	struct node {
		int l, r, ans;
	};
	bool pd(vector<int> a, int n, int mid) {
		vector<int> b(n + 5, 0);
		for (int i = n; i >= 3; i--) {
			if (a[i] + b[i] < mid) {
				return 0;
			}
			int x = min(a[i] + b[i] - mid, a[i]);
			b[i - 1] += x / 3;
			b[i - 2] += x / 3 * 2;
		}
		if (a[1] + b[1] < mid || a[2] + b[2] < mid) return 0;
		return 1;
	}
	void sol() {
		int n;
		cin >> n;
		vector<int> a(n + 5);
		vector<bool>vis(n + 5);
		for (int i = 1; i <= n; i++) cin >> a[i];
		int l = 1, r = 1e9;
		int ans = 0;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (pd(a, n, mid)) ans = mid, l = mid + 1;
			else r = mid - 1;
		}
		cout << ans << "\n";
	}
	void main() {
		ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		int T = 1;
		cin >> T;
		while (T--) sol();
	}
 
	#undef int
}
 
int main() {
	return Xbbbz::main(), 0;
}
