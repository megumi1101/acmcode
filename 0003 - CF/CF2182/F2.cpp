#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
const int mod = 998244353;
const int N = 6e5;
vector<array<int, 61>> sum(N + 5);
vector<int> fac, facn, inv, p2;
 
int C (int i, int j) {
    if (i < 0 || j < 0 || i < j) return 0;
    return fac[i] * facn[j] % mod * facn[i - j] % mod;
}
 
void init(int n) {
    fac.assign(n + 1, 0);
    facn.assign(n + 1, 0);
    inv.assign(n + 1, 0);
    p2.assign(n + 1, 0);
    fac[0] = fac[1] = facn[0] = facn[1] = inv[1] = 1;
    p2[0] = 1, p2[1] = 1;
    for (int i = 2; i <= n; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
        facn[i] = facn[i - 1] * inv[i] % mod;
        p2[i] = (p2[i - 1] + p2[i - 1]) % mod;
    }
 
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 61; j++) {
            sum[i][j] = C(i, j);
            if (j) sum[i][j] = (sum[i][j] + sum[i][j - 1]) % mod;
        }
    }
}
 
 
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);    
    init(6e5);
    int n, m;
    cin >> n >> m;
    vector<int> cnt(61);
    vector<int> p2(1e6 + 1, 1);
    for (int i = 1; i <= 1e6; i++) {
        p2[i] = (p2[i - 1] + p2[i - 1]) % mod;
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
 
    vector<int> sumcnt(65);
    while (m--) {
        int op;
        int x;
        cin >> op >> x;
        if (op == 1) {
            cnt[x]++;
            n++;
        } else if (op == 2) {
            cnt[x]--;
            n--;
        } else {
            int cur = 0;
            int pre = 1;
            int ans = 0;
            sumcnt[1] = cnt[0];
            for (int i = 2; i <= 61; i++) sumcnt[i] = sumcnt[i - 1] + cnt[i - 1];
            for (int i = 60; i >= 0; i--) {
                int now = 0;
                for (int j = 1; j <= cnt[i]; j++) {
                    if (((1LL << i) >> cur) < x && ((1LL << i) >> cur) > (x >> 1)) {
                        x -= ((1LL << i) >> cur);
                        now++;
                        cur++;
                    } else {
                        break;
                    }
                }
                int tmp = 0;
                if (((1LL << i) >> cur) >= x) 
                    tmp = pre * (p2[cnt[i]] - sum[cnt[i]][now] + mod) % mod * p2[sumcnt[i]] % mod;
                ans += tmp;
                ans %= mod;
                
                pre = pre * C(cnt[i], now) % mod;
            }
            cout << ans << "\n";
            
        }
    }
}
