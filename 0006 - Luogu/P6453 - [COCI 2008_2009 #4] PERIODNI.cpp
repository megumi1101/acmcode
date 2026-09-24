#include <bits/stdc++.h>

using namespace std;

#define int long long
const int mod = 1e9 + 7;

vector<int> fac, facn, inv;
void init(int n) {
    fac.assign(n + 1, 0);
    facn.assign(n + 1, 0);
    inv.assign(n + 1, 0);
    fac[0] = fac[1] = facn[0] = facn[1] = inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
        facn[i] = facn[i - 1] * inv[i] % mod;
    }
}

int C (int i, int j) {
    return fac[i] * facn[j] % mod * facn[i - j] % mod;
}

void sol() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), L(n + 1), R(n + 1), hei(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector dp(n + 1, vector(k + 1, (int)0));
    dp[0][0] = 1;

    vector<int> stk;
    for (int i = 1; i <= n; i++) {
        int lst = 0;
        while (!stk.empty() && a[stk.back()] > a[i]) {
            lst = stk.back();
            stk.pop_back();
        }
        if (!stk.empty()) {
            R[stk.back()] = i; 
        }
        L[i] = lst;   
        stk.push_back(i);
    }

    int rt = stk[0];
    auto dfs = [&](auto &&dfs, int u, int fat, int l, int r) -> void {
        if (L[u]) dfs(dfs, L[u], u, l, u - 1);
        if (R[u]) dfs(dfs, R[u], u, u + 1, r);


        int wid = r - l + 1;
        int hei = a[u] - a[fat];
        

        vector<int> tmp(k + 1);
        for (int li = 0; li <= k; li++) {
            if (!dp[L[u]][li]) break;
            for (int ri = 0; li + ri <= k; ri++) {
                if (!dp[R[u]][ri]) break;
                tmp[li + ri] = (tmp[li + ri] + dp[L[u]][li] * dp[R[u]][ri] % mod) % mod;
            }
        }

        for (int i = 0; i <= k; i++) {
            if (!tmp[i]) break;
            int nw = wid - i;
            int nh = hei;
            for (int j = 0; i + j <= k && j <= min(nw, nh); j++) {
                dp[u][i + j] = (dp[u][i + j] + C(nw, j) * C(nh, j) % mod * fac[j] % mod * tmp[i] %mod) % mod;
            }
        }
    };

    dfs(dfs, rt, 0, 1, n);
    cout << dp[rt][k] << "\n";
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    init(1e6);
    int t = 1;
    // cin >> t;
    while (t--) sol();
}