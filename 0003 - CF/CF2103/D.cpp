#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
	#define int long long
	const int mod = 1ll << 31;
	const int N = 1e5 + 10;
    void sol() {
        int n;
		cin >> n;
		vector<int> a(n + 5), b, nb,  ans(n + 5);
		for (int i = 1; i <= n; i++) b.push_back(i);
		for (int i = 1; i <= n; i++) cin >> a[i];
		int l = 1, r = n;
		for (int t = 1; t <= 20; t++) {
			// cout << "fd\n";
			int x = 0;
			nb.clear();
			while (a[b[x]] == t && x < b.size()) {
				x++;
			}
			for (int i = 0; i < x; i++) {
				if (a[b[i]] == t) {
					ans[b[i]] = (t & 1) ? r-- : l++;
				}
				else nb.push_back(b[i]);
			}
			for (int i = b.size() - 1; i >= x; i--) {
				if (a[b[i]] == t) {
					ans[b[i]] = (t & 1) ? r-- : l++;
				}
				else nb.push_back(b[i]);
			}
			sort (nb.begin(), nb.end());
			b = nb;
			// cout << "fd\n";
		}
		ans[b[0]] = l;
		for (int i = 1; i <= n; i++) cout << ans[i] << " ";
		cout << "\n";
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
