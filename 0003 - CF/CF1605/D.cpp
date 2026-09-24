#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
	#define int long long
    const int N = 2e5 + 10;
    vector <int> ed[N], v[2];
	void dfs(int u, int f, int op) {
        v[op].push_back(u);
        for (int v : ed[u]) {
            if (v == f) continue;
            dfs(v , u, op ^ 1);
        }
    }
    void sol() {
        int n;
        cin >> n;
        v[0].clear();
        v[1].clear();
        for (int i = 1; i <= n; i++) {
            ed[i].clear();
        }
        for (int i = 1; i < n; i++) {
            int x, y;
            cin >> x >> y;
            ed[x].push_back(y);
            ed[y].push_back(x);
        }
        dfs(1, 0 ,0);
        if (v[0].size() > v[1].size()) {
            swap(v[0], v[1]);
        }
        int res = 0;
        int xx = 0;
        for (int i = 0; i <= 20; i++) {
            res += pow(2, i);
            if (res * 2 + 1 >= n) {
                xx = i;
                break;
            }
        }
        int a[n + 5];
        int vis[n + 5];
        memset(a, 0 ,sizeof(a));
        memset(vis, 0 ,sizeof(vis));
        int pos = 0;
        int sz = v[0].size();
        for (int i = 0; i <= xx; i++) {
            if ((sz >> i) & 1) {
                for (int j = (1 << i); j < (1 << (i + 1)); j++) {
                    a[v[0][pos++]] = j;
                    vis[j] = 1;
                }
            }
        }
        pos = 0;
        for (int j = 1; j <=n ; j++) {
            if (vis[j]) continue;
            a[v[1][pos++]] = j;
        }
        for (int i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
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
