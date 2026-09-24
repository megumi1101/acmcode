#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
	#define int long long
 
	void sol() {
		int n;
		cin >> n;
		string s;
		cin >> s;
		s = " " + s;
		vector<int> a(n + 5);
		vector<vector<int>> f(n + 5, vector<int>(5, 1e18));
		for (int i = 1; i <= n; i++) cin >> a[i];
		f[0][1] = f[0][2] = f[0][3] = f[0][4] = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= 4; j++) {
				if ("0hard"[j] == s[i]) {
					f[i][j] = min (f[i - 1][j - 1], f[i - 1][j] + a[i]);
				}
				else f[i][j] = f[i - 1][j];
				if (j > 1) f[i][j] = min (f[i][j], f[i][j - 1]);
			}
		cout << f[n][4] << "\n";
	}
	void main() {
		ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		int T = 1;
		// cin >> T;
		while (T--) sol();
	}
 
	#undef int
}
 
int main() {
	return Xbbbz::main(), 0;
}
