#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
	#define int long long
 
	const int mod = 1e9 + 7;
	int fap(int a, int b) {
		int res = 1;
		while (b) {
			if (b & 1) res = res * a % mod;
			a = a * a % mod; b /= 2; 
		}
		return res;
	}
	void sol() {
		int n, m, tx, ty, sx, sy, p;
		cin >> n >> m >> sx >> sy >> tx >> ty >> p; 
		int inv100 = fap((int)100, mod - 2);
		p = (mod + 1 - inv100 * p % mod) % mod;
		int dx = 1, dy = 1;
		vector<int> a;
		int res = 1;
		for (int i = 1; i <= 4 * (n - 1) * (m - 1); i++) {
			if (dx == 1 && sx == n) dx = -dx;
			if (dx == -1 && sx == 1) dx = -dx;
			if (dy == 1 && sy == m) dy = -dy;
			if (dy == -1 && sy == 1) dy = -dy;
			res *= ((sx == tx) || (sy == ty)) ? p : 1;
			res %= mod;
			sx += dx; sy += dy;
			a.push_back(res); 
		}
		int ans = 0;
		for (auto &i : a) {
			(ans += i) %= mod;
		}
		res = (mod + 1 - res) % mod;
		res = fap(res, mod - 2);
		ans = ans * res % mod;
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
