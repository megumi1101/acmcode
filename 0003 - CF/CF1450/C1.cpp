#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    void sol() {
        int n;
        cin >> n;
        vector<string> a(n);
        vector<tuple<int, int, int>> ans;
        for (auto &x : a) cin >> x;
        vector cnt(3, vector(2, 0));
        int tk = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 'X') cnt[(i + j) % 3][0]++, tk++;
                if (a[i][j] == 'O') cnt[(i + j) % 3][1]++, tk++;
            }
        }
 
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j) continue;
                if (cnt[i][0] + cnt[j][1] <= tk / 3) {
                    for (int x = 0; x < n; x++) {
                        for (int y = 0; y < n; y++) {
                            if ((x + y) % 3 == i && a[x][y] == 'X') a[x][y] = 'O';
                            if ((x + y) % 3 == j && a[x][y] == 'O') a[x][y] = 'X';
                        }
                    }
                    for (auto x : a) cout << x << "\n";
                    return;
                }
            }
        }
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
}
 
int main() {
    return Xbbbz::main(), 0;
}
