#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    void sol() {
        int n, k;
        cin >> n >> k;
        int a[n + 5];
        int sum[n + 5];
        memset(sum, 0, sizeof(sum));
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n, [&](int x, int b) {return x > b;});
        int ans = 0;
        int pos = 0;
        for (int i = 1; i < n; i++) {
            sum[i] = sum[i - 1] + a[i];
            if (sum[i] >= 0) {
                pos = i;
            }
            if (sum[i] >= 0) ans += sum[i];
        }
        // if (k == 0) {
        //     for (int i = 1; i < n; i++) {
        //         if (sum[i] < 0) ans += sum[i];
        //     }
        //     cout << ans;
        //     return;
        // }
        int tmp = n - 1 - pos;
        if (tmp <= k) {
            cout << ans;
        } else {
            tmp -= k;
            a[pos + 1] = sum[pos + 1];
            k++;
            int x = tmp / k;
            int y = tmp % k;
            int res = 0;
            while(y--) {
                pos++;
                res += a[pos];
            }
            ans += (x + 1) * res;
            while(x) {
                res = 0;
                for (int i = 1; i <= k; i++) {
                    pos++;
                    res += a[pos];
                }
                ans += x * res;
                x--;
            }
            cout << ans;
        }
 
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        // cin >> T;
        while(T--) sol();
    }
    #undef int
} 
 
int main() {
    return Xbbbz :: main(), 0;
}
