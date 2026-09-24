#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
	#define int long long
    const int N = 2e5 + 10;
    int d[N * 5];
	void main() {
		ios::sync_with_stdio(false), cin.tie(nullptr);
		int n;
        cin >> n;
        int a[n + 5];
        int b[n + 5];
        int f[n + 5], g[n + 5];
        memset(f, 0 ,sizeof(f));
        memset(g, 0 ,sizeof(g));
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
		for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
 
        f[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                if (i % j == 0) {
                    f[i] -= f[j];
                    if ((j * j == i) || (j == 1)) continue;
                    f[i] -= f[i / j];
                }
            }
        }
        // cout << f[2] << "df\n";
        b[1] = 0;
        int ans = 0;
        g[1] = b[1] - a[1];
        ans += abs(g[1]);
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                if (i % j == 0) {
                    g[i] -= g[j];
                    if ((j * j == i) || (j == 1)) continue;
                    g[i] -= g[i / j] ;
                }
            }
            g[i] += b[i] - a[i];
            ans += abs(g[i]);
        }
        // cout << ans << "\n";
        // cout << g[1] << " " << g[2] << "\n";
        // cout << f[1] << " " << f[2] << "\n";
        for (int i = 1; i <= n; i++) {
            if (f[i] * g[i] >= 0) {
                d[1] += abs(f[i]);
            } else {
                if (f[i] < 0) {
                    f[i] = -f[i];
                    g[i] = -g[i];
                }
                d[1] -= f[i];
                int x = abs(g[i]);
                int y = x  / f[i];
                x %= f[i];
                int z = f[i] - x - x;
                if (y <= (int)1e6) d[y + 1] += z + f[i];
                if (y <= 1e6) d[y + 2] += f[i] - z;
            }
        }
        d[0] = ans;
        // cout << d[1] << " " << d[2] << " " << d[3] << " " << d[4] << "\n";
        for (int i = 2; i <= (N - 10) * 5; i++) {
            d[i] += d[i - 1];
        }
        // cout << d[1] << " " << d[2] << " " << d[3] << " " << d[4] << "\n";
        // cout << d[0] << "\n";
        for (int i = 1; i <= (N - 10) * 5; i++) {
            // cout << i << " " << d[i] << " " <<  d[i - 1] << "\n";
            d[i] += d[i - 1];
        }
        // cout << d[1] << " " << d[2] << " " << d[3] << " " << d[4] << "\n";
        int q;
        cin >> q;
        while (q--) {
            int x;
            cin >> x;
            cout << d[x] << "\n";
        }
	}
 
	#undef int
}
 
int main() {
	return Xbbbz::main(), 0;
}
