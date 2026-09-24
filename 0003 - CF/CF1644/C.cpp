#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
// #define int long long
const int inf = 2e9;
    void sol() {
        int n, x;
        cin >> n >> x;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        vector<vector<int>> f(n + 5, vector<int>(n + 5, -inf));
        f[1][0] = a[1]; f[1][1] = a[1] + x;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                f[i][j] = max({f[i][j], f[i - 1][j] + a[i], a[i], 0});
                if (j) f[i][j] = max({f[i][j], f[i - 1][j - 1] + a[i] + x, a[i] + x , 0});
            }
        }
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                ans = max(ans, f[j][i]);
            }
            cout << ans << " ";
        }
        cout << '\n';
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
    return Xbbbz::main(),0;
}
