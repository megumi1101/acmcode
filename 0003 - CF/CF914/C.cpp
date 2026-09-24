#include <bits/stdc++.h>
 
using namespace std;
 
namespace Std {
    #define int long long
    const int N = 2e5 + 10;
    const int mod = 1e9 + 7;
    int f[1005][1005][2][2];
	int a[1005];
	int cnt[1005];
	int g[1005];
	int sum, k;
	int num(int x) {
		int res = 0;
		while(x) {
			if(x % 2 == 1) res++;
			x /= 2;
		}
		return res;
	}
	void init() {
		g[1] = 0;
		for (int i = 2; i <= 1000; i++) {
			g[i] = g[num(i)] + 1;
		}
	}
	// int dfs(int len, int lim, int cnt) {
	// 	if (!lim && f[len][cnt] != -1) return f[len][cnt];
	// 	if (len == 0) {
	// 		if (cnt == sum) return 1;
	// 		else return 0;
	// 	}
	// 	int up = 1;
	// 	int res = 0;
	// 	if (lim) up = a[len];
	// 	for (int i = 0; i <= up; i++) {
	// 		res += dfs(len - 1, lim && up == i, cnt + i);
	// 		res %= mod;
	// 	}
	// 	if (!lim) f[len][cnt] = res;
	// 	return res; 
	// }
    void sol() {
		init();
		string s;
		cin >> s >> k;
		int n = s.size();
		for (int i = 1; i <= s.size(); i++) {
			a[i] = s[i - 1] - '0';
		}
		f[0][0][1][0] = 1;
		for (int i = 1; i <= n; i++) {
			f[i][0][0][0] = 1;
			for (int j = 1; j <= i; j++) {
				f[i][j][0][1] = (f[i - 1][j - 1][0][0] + f[i - 1][j - 1][0][1]) %mod;
				f[i][j][0][0] = (f[i - 1][j][0][0] + f[i - 1][j][0][1]) %mod;
				if (a[i] == 1) 
					f[i][j][1][1] = (f[i - 1][j - 1][1][0] + f[i - 1][j - 1][1][1]) %mod,
					(f[i][j][0][0] += (f[i - 1][j][1][0] + f[i - 1][j][1][1])) %= mod;
				else 
					f[i][j][1][0] = (f[i - 1][j][1][0] + f[i - 1][j][1][1]) %mod;
			}
		}
		for (int j = 1; j <= n; j++) {
			(cnt[j] = f[n][j][0][1] + f[n][j][0][0] + f[n][j][1][0] + f[n][j][1][1]) % mod;
		}
		int ans = 0;
		cnt[1]--;
		for (int i = 1; i <= n; i++) {
			if (g[i] == k - 1)
				(ans += cnt[i]) %= mod;
		}
		cout << ans + (k == 0);
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
