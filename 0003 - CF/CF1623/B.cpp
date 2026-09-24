#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
	#define int long long
	struct node {
		int l, r, ans;
	};
	void sol() {
		int n;
		cin >> n;
		vector<node> a(n + 5);
		vector<bool>vis(n + 5);
		for (int i = 1; i <= n; i++) cin >> a[i].l >> a[i].r;
		sort(a.begin() + 1, a.begin() + 1 + n, [&] (const node &xx, const node &yy) {return (xx.r - xx.l) < (yy.r - yy.l);});
		for (int i = 1; i <= n; i++) {
			for (int j = a[i].l; j <= a[i].r; j++) {
				if (!vis[j]) {
					vis[j] = 1;
					a[i].ans = j;
					break;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			cout << a[i].l << " " << a[i].r << " " << a[i].ans << "\n";
		}
		cout << "\n";
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
