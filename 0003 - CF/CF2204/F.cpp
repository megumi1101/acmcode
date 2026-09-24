#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int mod = 998244353, inf = 1e9;
 
int fap (int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod; b >>= 1;
    }
    return res;
}
 
signed main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), L(n + 1), R(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    int ans0 = 0;
    for (int i = 1; i <= n; i++) {
        int ct = (i - 1 + 1) * (n - i + 1) % mod;
        ans0 += ct * fap(a[i], mod - 2) % mod;
        ans0 %= mod;
    }
 
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
    
 
    auto b = a; // b 是 分母
    b.push_back(0);
    b.push_back(inf);
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    int siz = b.size() - 2; // except 0 and inf
    vector<int> cnt(siz + 2), c(siz + 2);
    for (int i = 1; i <= siz; i++) {
        c[i] = fap(b[i], mod - 2);
    }
 
    auto dfs = [&](auto &&dfs, int u, int l, int r) -> void {
        int ct = (u - l + 1) * (r - u + 1) % mod;
        int pos = lower_bound(b.begin(), b.end(), a[u]) - b.begin();
        cnt[pos] += ct;
        cnt[pos] %= mod;
        if (L[u]) dfs(dfs, L[u], l, u - 1);
        if (R[u]) dfs(dfs, R[u], u + 1, r);
    };
    dfs(dfs, stk[0], 1, n);
 
    auto suf = c; // 分数 乘 个数的后缀和
    for (int i = siz; i >= 0; i--) {
        suf[i] = suf[i] * cnt[i] % mod;
        suf[i] += suf[i + 1];
        suf[i] %= mod;
    }
    auto pre = c; // 分数变成1增量 的前缀和
    for (int i = 1; i <= siz + 1; i++) {
        pre[i] = ((int)1 - pre[i] + mod) * cnt[i] % mod;
        pre[i] += pre[i - 1];
        pre[i] %= mod;
    }
    auto sum = b; // 分母个数 乘 分母的前缀和
    for (int i = 1; i <= siz + 1; i++) {
        sum[i] = sum[i] * cnt[i] % mod;
        sum[i] += sum[i - 1];
        sum[i] %= mod;
    }
 
    auto sumcnt = cnt;
    for (int i = 1; i <= siz + 1; i++) {
        sumcnt[i] += sumcnt[i - 1];
        sumcnt[i] %= mod;
    }
 
    while (m--) {
        int k;
        cin >> k;
        if (k == 0) {
            cout << ans0 << "\n";
            continue;
        }
        k++;
 
        int pos = (--upper_bound(b.begin(), b.end(), k)) - b.begin();
        int res = k * sumcnt[pos] % mod - sum[pos] + mod;
        res += pre[pos];
        res %= mod;
        k--;
        if (pos + 1 <= siz) {
            res += suf[pos + 1] * k % mod;
            res %= mod;
        }
        cout << (ans0 + res) % mod << "\n";
    }
}
