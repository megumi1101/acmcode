#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
    constexpr int N = 1e6 + 10;
    struct node {
        int x, y;
        node (int x, int y) : x(x), y(y) {}
    };
    void sol() {
        int n, m;
        cin >> n >> m;
        int r, c;
        cin >> r >> c;
        vector<string> a(n);
        r--; c--;
        for (int i = 0; i < n; i++) cin >> a[i];
        int ans = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 'B') ans = 2;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == r || j == c) {
                    if (a[i][j] == 'B') ans = 1;
                }
            }
        }
        if (a[r][c] == 'B') ans = 0;
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
/*
3 3
010
101
010
*/
