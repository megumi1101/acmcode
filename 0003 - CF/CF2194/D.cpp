#include <bits/stdc++.h>
 
using namespace std;
#define int long long
void sol() {
    int n, m;
    cin >> n >> m;
    vector a(n + 1, vector(m + 1, 0));
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x;
            cin >> x;
            a[i][j] = x;
            if (x == 1) cnt++;
        }
    }
    cout << (cnt / 2) * (cnt - cnt / 2) << "\n";
    cnt /= 2;
    int res = 0;
    if (cnt == 0) {
        for (int i = 1; i <= n; i++) cout << 'D';
        for (int i = 1; i <= m; i++) cout << 'R';
        cout << "\n";
        return;
    }
    int x, y;
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            if (a[i][j] == 1) {
                res++;
                if (res == cnt) {
                    x = i;
                    y = j;
                }
            }
        }
    }
 
    for (int i = 1; i <= x - 1; i++) cout << 'D';
    for (int i = 1; i <= y - 1; i++) cout << 'R';
    cout << 'D';
    for (int i = 1; i <= m - y + 1; i++) cout << 'R';
    for (int i = 1; i <= n - x; i++) cout << 'D';
    cout << "\n";
 
}
 
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
