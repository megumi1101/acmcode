#include<bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 998244353;
signed main() {
    int n;
    cin >> n;

    auto getf = [](int x){
        vector<int> p;
        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                p.push_back(i);
                if (i * i != x) {
                    p.push_back(x / i);
                }
            }
        }
        return p;
    };
    
    auto getcnt = [](int x) {
        int cnt = 0;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                while (x % i == 0) {
                    x /= i;
                    cnt++;
                }
            }
        }
        if (x > 1) cnt++;
        return cnt;
    };

    int ans = 0;
    auto p = getf(n);
    int K = getcnt(n) + 5;
    ranges::sort(p);

    int D = p.size();

    unordered_map<int, int> id;
    id.reserve(D * 2);
    for (int i = 0; i < D; i++) {
        id[p[i]] = i;
    }

    vector dp(D, vector<int>(K + 1, 0));
    vector sum(D, vector<int>(K + 1, 0));

    dp[id[1]][0] = 1;

    for (auto x : p) {
        for (int k = K - 1; k >= 0; k--) {
            for (int i = 0; i < D; i++) {
                if (dp[i][k] == 0) continue;

                int cur = p[i];
                if (cur > n / x) continue;
                int np = cur * x;
                if (n % np != 0) continue;

                int j = id[np];
                dp[j][k + 1] += dp[i][k];
                dp[j][k + 1] %= mod;
                sum[j][k + 1] += sum[i][k] + dp[i][k] * (x % mod) % mod;
                sum[j][k + 1] %= mod;
            }
        }
    }

    vector<int> fac(K + 1, 1);
    for (int i = 1; i <= K; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }
    for (int k = 1; k <= K; k++) {
        ans += sum[id[n]][k] * fac[k] % mod;
        ans %= mod;
    }

    cout << ans << "\n";
}