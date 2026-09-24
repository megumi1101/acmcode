#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
	#define int long long
	const int mod = 1ll << 31;
	const int N = 2e5 + 10;
	double b[N], k[N];
	int m[N];
	bool vis[N];
	vector<int> ve[22];
	int mxi = 0 ;
	double mx = 0.0;
	void sol() {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> m[i] >> k[i];
		}
		for (int t = 1; t <= 20; t++) {
			double res = 0;
			memset(vis, 0, sizeof (vis));
			
			for (int i = 1; i < N; i++) {
				b[i] = 0.0;
			}
			for (int i = 1; i <= n; i++) {
				if (!vis[m[i]]) {
					vis[m[i]] = 1;
					ve[t].push_back(m[i]);
				}
				if (k[i] >= t) {
					b[m[i]] += 1.0; 
				}
				else {
					b[m[i]] += k[i] / (double)t;
				}
			}
			sort(ve[t].begin(), ve[t].end(), [&] (int i, int j) {return b[i] > b[j];});
			if (t > ve[t].size()) continue;
			for (int i = 0; i < t; i++) {
				res += b[ve[t][i]];
			}
			if (res > mx) mx = res, mxi = t;
		}
		cout << mxi << "\n";
		for (int i = 0; i < mxi; i++) {
			cout << ve[mxi][i] << " ";
		}
	}
	void main() {
		ios::sync_with_stdio(false), cin.tie(nullptr);
		int T = 1;
		// cin >> T;
		while (T--) sol();
	}
 
	#undef int
}
 
int main() {
	return Xbbbz::main(), 0;
}
