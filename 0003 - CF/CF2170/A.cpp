#include <bits/stdc++.h>
 
using namespace std;
namespace Xbbbz {
#define int long long
const int inf = 1e9;
    void sol() {
        int n;
        cin >> n;
        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy = {0, -1, 0, 1};
        vector a(n, vector<int>(n, 0));
        int cnt = 0;
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) {
                a[i][j] = ++cnt;
            }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int res = a[i][j];
                for (int t = 0; t < 4; t++) {
                    int tx = i + dx[t];
                    int ty = j + dy[t];
                    if (tx >= 0 && tx < n && ty >= 0 && ty < n) {
                        res += a[tx][ty];
                    }
                }
                ans = max(ans, res);
            }
        }
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
    return Xbbbz::main(),0;
}
