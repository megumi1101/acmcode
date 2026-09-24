#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    void sol() {
        int n, m;
        cin >> n >> m;
        vector<int> cnt(m + 5, 0);
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            for (int j = 0; j < m; j++) {
                cnt[j] += 1 & (x >> j);
            }
        }
        int ans = 0;
        // cout << cnt [1] << "\n";
        for (int j = 0; j < m; j++) {
            if (cnt[j] > n / 2) ans |= 1 << j;
        }
        cout << ans << "\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
    #undef int
}
 
int main() {
    return Xbbbz ::main(), 0;
}
