#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
    #define int long long
    const int N = 5e6 + 10;
    int cnt, vis[N], pr[N], mu[N], phi[N], s[N];
    int inv2, inv6;
    int mod;
    map<int, int> mp;
    int fap(int a, int b) {
        int res = 1;
        while (b) {
            if (b & 1) res = res * a % mod;
            b /= 2; a = a * a % mod;
        }
        return res;
    }
    int sum_p3(int n) {
        n %= mod;
        return n * (n + 1) % mod * inv2 % mod * n % mod * (n + 1) % mod * inv2 % mod;
    }
    int sum_p2(int n) {
        n %= mod;
        return n * (n + 1) % mod * (2 * n + 1) % mod * inv6 % mod;
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
            s[i] = phi[i] * i % mod * i % mod;
        }
        for (int i = 1; i <= n; i++) {
            s[i] += s[i - 1];
            s[i] %= mod;
        }
    }
    
    int get_s(int n) {
        if (n <= N - 10) return s[n];
        if (mp.find(n) != mp.end()) return mp[n];
        int ans = sum_p3(n);
        for (int l = 2, r; l <= n; l = r + 1) {
            r = n / (n / l);
            int tmp = ((sum_p2(r) - sum_p2(l - 1)) % mod + mod) % mod * get_s(n / l) % mod;
            ans = ((ans - tmp) % mod + mod) % mod;
        }
        return mp[n] = ans;
    }
    
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int n;
        cin >> mod >> n;
        inv2 = fap(2, mod - 2);
        inv6 = fap(6, mod - 2);
        init(N - 10);
        int ans = 0;
        for (int l = 1, r; l <= n; l = r + 1) {
            r = n / (n / l);
            ans += ((get_s(r) - get_s(l - 1)) % mod + mod) % mod * sum_p3(n / l) % mod; 
            ans %= mod;
        }
        cout << ans << "\n";
    }
    
    #undef int
}
int main() {
    return Xbbbz::main(), 0;
}