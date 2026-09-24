#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
	#define int long long
	const int mod = 1ll << 31;
	const int N = 1e5 + 10;
	int mu[N], sd[N];
	int pe[N], c[N], pr[N], pos = 1;
	bool vis[N];
	int cnt = 0;

	struct node {
		int n, m, a, ans, id;
		friend bool operator < (const node &a, const node &b) {
			return a.a < b.a;
		}
	}b[N];

	int lb(int x) {
		return x & (-x);
	}

	void add(int p, int x) {
		while(p <= N - 10) {
			(c[p] += x) %= mod;
			p += lb(p);
		}
	}
	
	int cx(int p) {
		int res = 0;
		while(p) {
			(res += c[p]) %= mod;
			p -= lb(p);
		}
		return res;
	}

	int fap(int a, int b) {
		int res = 1;
		while (b) {
			if (b & 1) res = res * a % mod;
			b /= 2; a = a * a % mod; 
		}
		return res;
	}

	void init(int n) {
		mu[1] = 1; 
		for (int i = 2; i <= n; i++) {
			if (!vis[i]) {
				pr[++cnt] = i;
				mu[i] = -1;
			}
			for (int j = 1; i * pr[j] <= n; j++) {
				int m = i * pr[j];
				vis[m] = 1;
				if (i % pr[j] == 0) {
					mu[m] = 0;
					break;
				} else {
					mu[m] = -mu[i];
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j += i) {
				sd[j] += i;
				sd[j] %= mod;
			}
		}
		for (int i = 1; i <= n; i++) pe[i] = i;
		sort(pe + 1, pe + 1 + n, [&](int i , int j) {return sd[i] < sd[j]; });
	}
	void update(int x) {
		while (pos <= 1e5) {
			int i = pe[pos];
			if (sd[i] > x) break;
			for (int j = i; j <= 1e5; j += i) {
				add(j, (sd[i] * mu[j / i] + mod) % mod);
			}
			pos++;
		}
	}
	int sol(int n, int m, int a) {
		if (n > m) swap(n, m);
		update(a);
		int ans = 0;
		for (int l = 1, r; l <= n; l = r + 1) {
			r = min (n / (n / l), m / (m / l));
			ans += ((cx(r) - cx(l - 1)) % mod + mod) * (n / l) % mod * (m / l) % mod;
            ans %= mod;
		}
		return ans;
	}
	void main() {
		ios::sync_with_stdio(false), cin.tie(nullptr);
		init(100000);
		int T;
		cin >> T;
		for (int i = 1; i <= T; i++) {
            b[i].id = i;
			cin >> b[i].n >> b[i].m >> b[i].a;
		}
		sort(b + 1, b + 1 + T);
		for (int i = 1; i <= T; i++) {
			b[i].ans = sol(b[i].n, b[i].m, b[i].a);
		}
        sort(b + 1, b + 1 + T, [&](const node &a, const node &b) {return a.id < b.id;});
        for (int i = 1; i <= T; i++) {
			cout << b[i].ans << "\n";
		}
	}

	#undef int
}

int main() {
	return Xbbbz::main(), 0;
}