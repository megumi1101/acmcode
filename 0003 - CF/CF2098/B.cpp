#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
	#define int long long
	
	void sol() {
		map<int, int> mp;
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			mp[x]++;
		}
		mp[(int)1e9] = 0;
		int lst = 0;
		int sum = 0;
		int ans = 0;
		for (auto [x, y] : mp) {
			int rt = n - y - sum;
			if (x - 1 > lst) {
				if (abs(sum - rt - y) <= k ) ans += x - 1 - lst;
			}
			if (abs(sum - rt) <= y + k) {
				ans ++;
			}
			lst = x;
			sum += y;
		}
		cout << ans << "\n";
	}
	void main() {
		ios::sync_with_stdio(false), cin.tie(nullptr);
		int T = 1;
		cin >> T;
		while (T--) sol();
	}
 
	#undef int
}
 
int main() {
	return Xbbbz::main(), 0;
}
