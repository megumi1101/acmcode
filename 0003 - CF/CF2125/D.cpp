#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int inf = 1e9;
const int mod = 998244353;
    int fp(int a, int b) {
        int res = 1;
        while (b) {
            if (b & 1) res *= a, res %= mod;
            a *= a; a %= mod; b >>= 1;
        }
        return res;
    }
    int mod_inv(int x) {
        return fp(x, mod - 2);
    }
    void sol() { 
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> seg(n); 
        vector<int> aqp(n), aq(n), ap(n), pro(n), dp(m + 1), a0(n), a1(n); 
 
        for (int i = 0; i < n; i++) {
            int l, r, p, q;
            cin >> l >> r >> p >> q;
            seg[i] = {l, r};
            aqp[i] = (q - p) % mod;
            aq[i] = q % mod;
            ap[i] = p % mod;
            a1[i] = ap[i] * mod_inv(aq[i]) % mod;
            a0[i] = aqp[i] * mod_inv(aq[i]) % mod;
        }
        int totqp = 1, totq = 1;
        for (int x : aqp) {
            totqp = (totqp * x) % mod;
        }
        for (int x : aq) {
            totq = (totq * x) % mod;
        }
        vector<pair<int, int>> rs; 
        for (int i = 0; i < n; i++) {
            rs.emplace_back(seg[i].second, i);
        }
        sort(rs.begin(), rs.end());
        vector<int> r_list;
        for (auto& p : rs) {
            r_list.push_back(p.first);
        }
        vector<int> preqp(n + 1, 1), preq(n + 1, 1);
        vector<pair<int, int>> ls; 
        for (int i = 0; i < n; i++) {
            ls.emplace_back(seg[i].first, i);
        }
        sort(ls.begin(), ls.end());
        vector<int> l_list;
        for (auto& p : ls) {
            l_list.push_back(p.first);
        }
        vector<int> sufqp(n + 1, 1), sufq(n + 1, 1);
        for (int i = n - 1; i >= 0; i--) {
            int idx = ls[i].second;
            sufqp[i] = (sufqp[i + 1] * aqp[idx]) % mod;
            sufq[i] = (sufq[i + 1] * aq[idx]) % mod;
        }
        for (int i = 1; i <= n; i++) {
            int idx = ls[i - 1].second;
            preqp[i] = (preqp[i - 1] * aqp[idx]) % mod;
            preq[i] = (preq[i - 1] * aq[idx]) % mod;
        }
        for (int i = 0; i < n; i++) {
            int l = seg[i].first;
            int r = seg[i].second;
            int k1 = lower_bound(l_list.begin(), l_list.end(), l) - l_list.begin();
            int xx1 = preqp[k1];
            int xx2 = preq[k1];
            int k2 = upper_bound(l_list.begin(), l_list.end(), r) - l_list.begin();
            int xx3 = sufqp[k2];
            int xx4 = sufq[k2];
            // cerr << k1 << " " << k2 << "\n";
            // cerr << xx1 << " " << xx2 << " " << xx3 << " " << xx4 << "\n";
            int inv1 = mod_inv((totq * mod_inv(xx2 * xx4 % mod * aq[i] % mod)) % mod);
            pro[i] = totqp * inv1 % mod * mod_inv(xx1 * xx3 % mod * aqp[i] % mod) % mod ;
        }
        dp[0] = 1;
        // for (int i = 0; i < n; i++) cerr << pro[i] << " ";
        for (int i = 0; i < rs.size(); i++) {
            int x = rs[i].second;
            int l = seg[x].first;
            int r = seg[x].second;
            // cerr << x << "\n";
            // cerr << l << " " << r << "\n";
            dp[r] += dp[l - 1] * pro[x] % mod * a1[x] % mod;
            dp[r] %= mod;
        }
        cout << dp[m] << "\n";
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
#undef int
}
 
 
int main() {
    return Xbbbz::main(), 0;
}
