#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
	#define int long long
	const int mod = 1ll << 31;
	const int N = 1e5 + 10;
    void sol() {
        int x, y;
		cin >> x >> y;
		if ((abs(x) + abs(y)) &  1) {
			cout << "-1 -1\n";
		}
		else {
			int rx = 1, ry = 1;
			if (x < 0) rx = -1;
			if (y < 0) ry = -1;
			x = abs(x);
			y = abs(y);
			if (x == 0) {
				cout << rx * (x / 2) << " " << ry * (y / 2) << "\n";
			}
			else if (y == 0){
				cout << rx * (x / 2) << " " << ry * (y / 2) << "\n";
			}
			else cout << rx * ((x - 1) / 2 + 1) << " " << ry * (y / 2) << "\n";
		}
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
