#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
const int mod = 20101009;
    vector<int> pr, vis(1e7 + 1), mu(1e7 + 1), inv(1e7 + 1), g(1e7 + 1), h(1e7 + 1);
    void init() {
        int n = 1e7;
        inv[1] = mu[1] = 1;
        for (int i = 2; i <= n; i++) {
            inv[i] = inv[mod % i] * (mod - mod / i) % mod;
            if (!vis[i]) pr.push_back(i), mu[i] = -1;
            for (auto j : pr) {
                if (i * j > n) break;
                int m = i * j;
                vis[m] = 1;
                if (i % j == 0) {
                    mu[m] = 0;
                    break;
                }
                else {
                    mu[m] = -mu[i];
                }
            }
        }
        for (int i = 1; i <= n; i++) g[i] = inv[i];
        for (auto i : pr)
            for (int j = n / i; j >= 1; j--)
                g[j * i] = ((g[j * i] - g[j]) % mod + mod) % mod;
        for (int i = 1; i <= n; i++) {
            g[i] = g[i] * i % mod * i % mod;
            g[i] = (g[i] + g[i - 1]) % mod;
            h[i] = (h[i - 1] + i) % mod; 
        }
    }
    
    int get(int x, int y) {
        return h[x] * h[y] % mod; 
    }

    void sol() {
        int n, m;
		cin >> n >> m;
		if (n > m) swap(n, m);
		int ans = 0;

		for (int l = 1, r; l <= n; l = r + 1) {
			r = min (n / (n / l), m / (m / l));
			ans += (g[r] - g[l - 1] + mod) * get(n / l, m / l) %mod;
			((ans %= mod) += mod) %= mod;
		}
		cout << ans << "\n";
    }

    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        init();
        while (T--) sol();
    }
#undef int
}

int main() {
    return Xbbbz::main(), 0;
}