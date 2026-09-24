#include <bits/stdc++.h>
 
using namespace std;
 
namespace Std {
    #define int long long
	const int N = 2e5 + 10;
	const int inf = 1e18;
    int n;
	vector<int> ed[N];
	int dep[N];
	int f[N][3];
	void dfs(int u, int fat) {
		dep[u] = dep[fat] + 1;
		f[u][1] = 1;
		f[u][2] = 0;
		f[u][0] = 0;
		int res = inf;
		for (int v : ed[u]) {
			if (v == fat) continue;
			dfs(v, u);
			res = min(res, f[v][1] - f[v][0]);
			f[u][0] += min(f[v][1], f[v][0]);
			f[u][2] += min(f[v][1], f[v][0]);
			f[u][1] += min(f[v][1], f[v][2]);
		}
		if (res > 0) f[u][0] += res; 
		// if (ed[u].size() != 1) f[u][1] = min(f[u][1], f[u][0]);
	}
    void sol() {
		cin >> n;
		for (int i = 1; i < n; i++) {
			int x, y;
			cin >> x >> y;
			ed[x].push_back(y);
			ed[y].push_back(x);
		}
		memset(f, 0x3f, sizeof(f));
		dfs(1, 0);
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (dep[i] == 3) {
				ans += min(f[i][1], f[i][2]);
			}
		}
		cout << ans;
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        // cin >> T;
        while(T--) sol();
    }
    #undef int
}
 
int main() {
    return Std::main(), 0;
}
