#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
	#define int long long
	const int mod = 1ll << 31;
	const int N = 1e5 + 10;
	void sol() {
		int a, b, x;
		cin >> a >> b >> x;
		int d = gcd (a, b);
		if (x % d != 0) {
			cout << "NO\n";
			return;
		}
		x /= d;
		a /= d;
		b /= d;
		if (a < b) swap(a, b);
		while (a >= x) {
			if (a == x || b == x) {
				cout << "YES\n";
				return;
			}
			if (b == 0) {
				cout << "NO\n";
				return;
			}
			if ((a - x) % b == 0) {
				cout << "YES\n";
				return;
			}
			a = a % b + b;
			b = a - b;
		}
		cout << "NO\n";
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
