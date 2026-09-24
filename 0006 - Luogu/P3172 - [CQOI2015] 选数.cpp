#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
    #define int long long
    const int N = 1e6 + 10;
    const int mod = 1e9 + 7;
    int cnt, vis[N], pr[N], mu[N], phi[N], smu[N];
    map<int, int> mpsmu;
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
        phi[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (!vis[i]) {
                pr[++cnt] = i;
                mu[i] = -1;
                phi[i] = i - 1;
            }
            for (int j = 1; j <= cnt && i * pr[j] <= n; j++) {
                int m = i * pr[j];
                vis[m] = 1;
                if (i % pr[j] == 0) {
                    phi[m] = phi[i] * pr[j];
                    break;
                }
                mu[m] = -mu[i];
                phi[m] = phi[i] * (pr[j] - 1);
            }
        }
        for (int i = 1; i <= n; i++) {
            smu[i] = smu[i - 1] + mu[i];
        }
    }
    int get_smu(int n) {
        if (n <= N - 10) return smu[n];
        if (mpsmu.find(n) != mpsmu.end()) return mpsmu[n];
        int ans = 1;
        for (int l = 2, r; l <= n; l = r + 1) {
            r = n / (n / l);
            ans -= (r - l + 1) * get_smu(n / l);
        }
        return mpsmu[n] = ans;
    }
    
    int Qm(int x) {
        return (x % mod + mod) % mod;
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        init(N - 10);
        int n, k, L, R;
        cin >> n >> k >> L >> R;
        L = ceil((double)L / k); R = R / k;
        L--;
        int ans = 0;
        for (int l = 1, r; l <= R; l = r + 1) {
            if (l <= L) {
                r = min(L / (L / l), R / (R / l));
            } else {
                r =  R / (R / l);
            }
            ans += Qm(get_smu(r) - get_smu(l - 1)) * fap(Qm(R / l - L / l), n) % mod;
            ans %= mod;
        }
        cout << ans;
    }
    
    #undef int
}
int main() {
    return Xbbbz::main(), 0;
}