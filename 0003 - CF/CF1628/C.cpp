#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int mod = 998244353;
 
    void sol() {
        int n;
        cin >> n;
        vector<vector<int>> a(n + 1, vector<int> (n + 1)), b(n + 1, vector<int> (n + 1));
        auto get = [&] (int x, int y) -> int {
            if (x <= 0 || x > n || y <= 0 || y > n) {
                return 0;
            }
            else return a[x][y];
        };
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                a[i][j] = 1 ^ get(i - 1, j - 1) ^ get(i - 1, j + 1) ^ get(i - 2, j);
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= n; j++)
                {cin >> b[i][j]; b[i][j] *= a[i][j]; ans ^= b[i][j];}
 
 
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
