#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int inf = 1e18;
    void sol() {
        int n;
        cin >> n;
        vector<int> a(n + 1), b(n + 1), sab(n + 1);
        vector<vector<int>> f(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];
        for (int i = 1; i <= n; i++) sab[i] = sab[i - 1] + a[i] + b[i];
        f[0].push_back(0);
        for (int i = 1; i <= n; i++) {
            f[i].assign(100 * i + 5, inf);
            for (int j = 0; j < f[i - 1].size(); j++) {
                f[i][j + a[i]] = min(f[i][j + a[i]], f[i - 1][j] + a[i] * j + b[i] * (sab[i - 1] - j));
                f[i][j + b[i]] = min(f[i][j + b[i]], f[i - 1][j] + b[i] * j + a[i] * (sab[i - 1] - j));
            }
        }
        int ans = inf;
        for (auto x : f[n]) ans = min(ans, x);
        ans <<= 1;
        for (int i = 1; i <= n; i++) {
            ans += (n - 1) * a[i] * a[i];
            ans += (n - 1) * b[i] * b[i];
        }
        cout << ans << "\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
#undef int 
}
 
int main() {
    return Xbbbz::main(), 0;
}
