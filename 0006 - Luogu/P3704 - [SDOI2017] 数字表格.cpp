#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
	#define int long long
	const int mod = 1e9 + 7;
	const int N = 1e6 + 10;
	int mu[N], mul[N];
	int pr[N];
	int fib[N];
	bool vis[N];
	int cnt = 0;
	int fap(int a, int b) {
		int res = 1;
		while (b) {
			if (b & 1) res = res * a % mod;
			b /= 2; a = a * a % mod; 
		}
		return res;
	}
	void init(int n) {
		for (int i = 0; i <= n; i++) mul[i] = 1;
		mu[1] = 1;
		fib[1] = 1;
		for (int i = 2; i <= n; i++) fib[i] = (fib[i - 1] + fib[i - 2]) % mod;  
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
				if (mu[j / i] == 1) {
					(mul[j] *= fib[i]) %= mod;
				}
				else if (mu[j / i] == -1) {
					(mul[j] *= fap(fib[i], mod - 2)) %= mod;
				}
				 
			}
		}
		for (int i = 2; i <= n; i++) {
			(mul[i] *= mul[i - 1]) %= mod;
		}
	}

	void sol() {
		int n, m;
		cin >> n >> m;
		if (n > m) swap(n, m);
		int ans = 1;
		for (int l = 1, r; l <= n; l = r + 1) {
			r = min (n / (n / l), m / (m / l));
			(ans *= fap(mul[r] * fap(mul[l - 1], mod - 2) % mod, (n / l) * (m / l) % (mod - 1))) %= mod;
		}
		cout << (ans % mod + mod) % mod << "\n";
	}
	void main() {
		ios::sync_with_stdio(false), cin.tie(nullptr);
		int T = 1;
		cin >> T;
		init(1000000);
		while(T--) {
			sol();
		}
	}

	#undef int
}

int main() {
	return Xbbbz::main(), 0;
}