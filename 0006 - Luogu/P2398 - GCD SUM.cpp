#include <bits/stdc++.h>

using namespace std;

namespace xbbbz {
    #define int long long
    const int N = 1e5+10;

    int pr[N], vis[N], phi[N], cnt = 0, sumphi[N];

    void init() {
        phi[1] = 1;
        int n = N - 10;
        for (int i = 2; i <= n; i++) {
            if (!vis[i]) {
                pr[++cnt] = i;
                phi[i] = i - 1;
            }
            for (int j = 1; j <= cnt && i * pr[j] <= n; j++) {
                int m = i * pr[j];
                vis[m] = 1;
                if (i % pr[j] == 0) {
                    phi[m] = phi[i] * pr[j];
                    break;
                }
                else {
                    phi[m] = phi[i] * (pr[j] - 1);
                }
            }
        }
        for (int i = 1; i <= n ;i++) {
            sumphi[i] = sumphi[i-1] + phi[i];
        }
    }
    
    int get_phi(int x) {
        int res = x;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                res = res * (i - 1) / i;
                while (x % i == 0) x /= i;
            }
        }
        if (x != 1) res = res * (x - 1) / x;
        return res;
    }

    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        init();
        int n;
        cin >> n;
        int ans = 0;
        for (int d = 1; d <= n; d++) {
            ans += d * (2 * sumphi[n / d] - 1);
        }
        cout << ans;
    }

    #undef int
}

int main() {
    return xbbbz::main(), 0;
}