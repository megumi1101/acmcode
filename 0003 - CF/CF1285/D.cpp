#include <bits/stdc++.h>
 
using namespace std;
 
namespace Std {
    #define int long long
	const int N = 1e5 + 10;
	const int inf = 1e18;
	const int mod = 998244353;
	int ch[N * 35][2];
	int n, cnt = 0;
	int a[N];
	bool vis[N * 35];
	queue<int> q;
	int ans = 0;
	void add (int x) {
		int u = 0;
		for (int i = 29; i >= 0; i--) {
			int v = (x >> i) & 1; 
			if (!ch[u][v]) ch[u][v] = ++cnt;
			u = ch[u][v];
		}
	}
	void bfs() {
		q.push(0);
		for (int k = 29; k >= 0; k--) {
			queue<int> q2;
			bool fg = 0;
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				q2.push(u);
				if (!ch[u][0] || !ch[u][1]) {
					fg = 1;
				}
			}
			if (fg) {
				while (!q2.empty()) {
					int u = q2.front();
					q2.pop();
					if (ch[u][0] && ch[u][1]) continue;
					if (ch[u][0]) q.push(ch[u][0]);
					if (ch[u][1]) q.push(ch[u][1]);
				}
			} else {
				ans ^= (1 << k); 
				while (!q2.empty()) {
					int u = q2.front();
					q2.pop();
					if (ch[u][0]) q.push(ch[u][0]);
					if (ch[u][1]) q.push(ch[u][1]);
				}
			}
		}
	}
	void sol() {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			add(a[i]);
		}
		bfs();
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
