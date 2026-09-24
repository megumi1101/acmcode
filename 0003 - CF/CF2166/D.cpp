#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int mod = 998244353;
    void sol() {
        int n;
        cin >> n;
        vector<int> a(n), vis(n + 1), b;
        for (auto &x : a) cin >> x, vis[x]++;
        for (auto x : vis) if (x) b.push_back(x);
        sort(b.begin(), b.end());
        vector<int> f(n + 1, 0);
        vector<int> nf(n + 1, 0);
        f[0] = 1;
        int mx = b.back();
        b.pop_back();
 
        int ans = mx;
        for (auto x : b) {
            nf = f;
            (ans *= (x + 1)) %= mod;
            for (int i = 0; i + x <= n; i++) {
                (f[i + x] += nf[i] * x) %= mod;
            }
        }
        
        for (int i = mx; i <= n; i++) (ans += f[i]) %= mod;
        cout << ans << "\n";
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
}
#undef int
 
int main() {
    return Xbbbz::main(), 0;
}
