#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
const int inf = 1e9;
const int mod = 998244353;
using i16 = short;
using i32 = int;
void add(auto &x, auto y) {
    x += y;
    if (x >= mod) x -= mod;
}
    void sol() {
        int n;
        cin >> n;
        vector<vector<short>> cnt(n, vector<short>(26));
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (auto c : s) {
                cnt[i][c - 'a']++;
            }
        }
 
        vector<vector<short>> mncnt((1 << n), vector<short>(26, SHRT_MAX));
 
        vector<vector<long long>> f(2, vector<long long> (1 << n));
        for (int i = 1; i < (1 << n); i++) {
            int j = i & -i;
            int t = __builtin_ctz(j);
            long long res = 1;
            for (int k = 0; k < 26; k++) {
                mncnt[i][k] = min(cnt[t][k], mncnt[i ^ j][k]);
                res *= (mncnt[i][k] + 1);
                res %= mod;
            }
            int tt = __builtin_popcount(i);
            f[tt & 1][i] = res;
            // cerr << res << "\n";
        }
        
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < (1 << n); i++) {
                if ((i >> j) & 1) {
                    add(f[0][i], f[0][i ^ (1 << j)]);
                    add(f[1][i], f[1][i ^ (1 << j)]);
                }
            }
        }
        
        long long ans = 0;
        for (int i = 1; i < (1 << n); i++) {
            int tt = __builtin_popcount(i);
            long long res = 0;
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) res += j + 1;
            }
            res *= tt;
            int ttt = f[1][i] - f[0][i] + mod;
            if (ttt >= mod) ttt -= mod;
            res *= ttt;
            ans ^= res;
        }
        cout << ans << "\n";
    }
    
    void main() {
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
#undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
