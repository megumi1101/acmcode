#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
	#define int long long
 
	void sol() {
		int n, m, a, b, c, d;
		cin >> n >> m >> a >> b >> c >> d;
		int x, y;
		if (c >= a) {
			x = c - a;
		}
		else {
			x = n - a + n - c;
		}
		if (d >= b) {
			y = d - b;
		}
		else {
			y = m - b + m - d;
		}
		cout << min(x, y) << "\n";
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
