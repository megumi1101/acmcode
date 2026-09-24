#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
	#define int long long
	
	void sol() {
		map<int, int> mp, cnt;
		int n;
		cin >> n ;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			mp[x]++;
		}
		bool fg = 0;
		for (auto [x, y] : mp) {
			if (y >= 4) {
				fg = 1;
				break;
			}
			if (cnt[x + 1]) {
				if (y >= 2) {
					fg = 1;
					break;
				}
				else {
					cnt[x + 2] = 1;
				}
			}
			else {
				if (y >= 2) cnt[x + 2] = 1;
			}
		}
		if (fg) cout << "Yes\n";
		else cout << "No\n";
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
