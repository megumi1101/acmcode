#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
	#define int long long
	const int mod = 1ll << 31;
	const int N = 1e5 + 10;
    void sol() {
        int n, a, b;
		cin >> n >> a >> b;
		int ans[n + 5];
		int vis[n + 5];
		ans[1] = a;
		ans[n] = b;
		memset(vis, 0 ,sizeof (vis));
		int r = n, l = 1;
		vis[a] = 1;
		vis[b] = 1;
		for (int i = 2; i <= n / 2; i++) {
			while (r == a || r == b || vis[r]) {
				r--;
				// cout << r << "\n";
			}
			ans[i] = r--;
			vis[ans[i]] == 1;
		}
		for (int i = n / 2 + 1; i < n; i++) {
			while (l == a || l == b || vis[l]) {
				l++;
			}
			ans[i] = l++;
			vis[ans[i]] == 1;
		}
		int mn = n + 1, mx = -1;
		for (int i = 1; i <= n / 2; i++) {
			mn = min(mn, ans[i]);
		}
		for (int i = n / 2 + 1; i <= n; i++) {
			mx = max(mx, ans[i]);
		}
		// for (int i = 1; i <= n; i++) cout << ans[i] << " ";
		if (mn == a && mx == b) {
			for (int i = 1; i <= n; i++) cout << ans[i] << " ";
			cout << "\n";
		}
		else cout << "-1\n";
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
