#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
    #define int long long
    const int N = 2e6 + 10;
    int cnt, vis[N], pr[N], mu[N], phi[N], smu[N], sphi[N];
    map<int, int> mpsmu, mpsphi;
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
            sphi[i] = sphi[i - 1] + phi[i];
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
    int get_sphi(int n) {
        if (n <= N - 10) return sphi[n];
        if (mpsphi.find(n) != mpsphi.end()) return mpsphi[n];
        int ans = n * (n + 1) / 2;
        for (int l = 2, r; l <= n; l = r + 1) {
            r = n / (n / l);
            ans -= (r - l + 1) * get_sphi(n / l);
        }
        return mpsphi[n] = ans;
    }
    void sol() {
        int n;
        cin >> n;
        cout << get_sphi(n) << " " << get_smu(n) << "\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        cin >> T;
        init(N - 10);
        // cout << sphi[2] << " " << smu[1] << "\n";
        while (T--) sol();
    }
    
    #undef int
}
int main() {
    return Xbbbz::main(), 0;
}