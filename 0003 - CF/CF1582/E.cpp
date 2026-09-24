#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    const int inf = 1e18;
    int f[100010][555];
    int n;
    void sol() {
        cin >> n;
        int m = sqrt(2 * n)  + 5;
        int a[n + 5];
        int sum[n + 5];
        memset(sum, 0, sizeof(sum));
        for (int i = 1; i <= n; i++) cin >> a[i], sum[i] = sum[i - 1] + a[i];
        for (int i = 1; i <= n + 1; i++) {
            for (int j = 1; j <= m + 1; j++) {
                f[i][j] = 0;
            }
        }
        for (int i = n; i >= 1; i--) {
            f[i][1] = max(f[i + 1][1], a[i]);
            for (int j = 2; j <= m; j++) {
                f[i][j] = f[i + 1][j];
                if (i + j <= n && (sum[i + j - 1] - sum[i - 1] < f[i + j][j - 1])) {
                    f[i][j] = max(f[i][j], sum[i + j - 1] - sum[i - 1]);
                }
            }
        }
        int ans = 1;
        for (int i = 1; i <= m; i++) {
            if (f[1][i]) ans = i;
            else break;
        }
        cout << ans << "\n";
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        cin >> T;
        while (T--) {
            sol();
        }
    }
    #undef int
}
 
int main() {
    return Xbbbz ::main(), 0;
}
