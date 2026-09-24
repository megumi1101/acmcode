#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    // #define int long long
    const int N = 3e5 + 10;
    // const int inf = 1e18;
    vector<vector<int>> a(N, vector<int>(9, 0));
    int id[300], xx;
    int ans1, ans2;
    int n, m;
    bool pd(int x) {
        memset(id, 0, sizeof(id));
        for (int i = 1; i <= n; i++) {
            int res = 0;
            for (int j = 1; j <= m; j++) {
                res |= (a[i][j] >= x) << (j - 1);
            }
            id[res] = i;
        }
        for (int i = 0; i <= xx; i++) {
            if (!id[i]) continue;
            for (int j = i; j <= xx; j++) {
                if (!id[j]) continue;
                if (((i ^ xx) & j) == (i ^ xx)) {
                    ans1 = id[i];
                    ans2 = id[j];
                    return 1;
                }
            }
        }
        return 0;
    }
    void sol () {
        cin >> n >> m;
        xx = (1 << m) - 1;
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= m; j++) 
                cin >> a[i][j];
        int l = 0, r = 1e9;
        int ans = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (pd(mid)) ans = mid, l = mid + 1;
            else r = mid - 1;
        }
        pd(ans);
        cout << min(ans1, ans2) << " " << max(ans1, ans2) << "\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
    // #undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
