#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
void sol() {
    int n, q;
    cin >> n >> q;
    int mxV = sqrt(n);
 
 
    vector<char> issqr(n + 1);
    for (int x = 1; x <= mxV; x++) {
        issqr[x * x] = 1;
    }
 
    vector<char> vis(n + 1);
    for (int x = 1; x <= mxV; x++) {
        for (int y = 1; y <= mxV; y++) {
            if (x * x + y * y <= n) {
                vis[x * x + y * y] = 1;
            }
        }
    }
 
    vector vis2(mxV + 1, vector<char>(n + 1));
    for (int x = 1; x <= mxV; x++) {
        for (int y = 1; y < x; y++) {
            vis2[x][x * x - y * y] = 1;
        }
        for (int i = 1; i <= n; i++) {
            vis2[x][i] |= vis2[x - 1][i];
        }
    }
 
    auto check2 = [&](int a, int b) -> bool {
        if (a > b) swap(a, b);
        int x = b - a;
        int dis = sqrt(max(n - a, b - 1));
        if (vis[x] || vis2[dis][x]) return 1;
        return 0;
    };
 
    while (q--) {
        int a, b;
        cin >> a >> b;
        int x = b - a;
 
        if (issqr[x]) {
            cout << "1\n";
            continue;
        }
 
        if (check2(a, b)) {
            cout << "2\n";
            continue;
        }
 
        {
            bool fg = 0;
            for (int i = 1; i <= mxV; i++) {
                if (a - i * i >= 1) {
                    if (check2(a - i * i, b)) {
                        fg = 1;
                        break;
                    }
                }
                if (a + i * i <= n) {
                    if (check2(a + i * i, b)) {
                        fg = 1;
                        break;
                    }
                }
            }
            if (fg) {
                cout << "3\n";
                continue;
            }
        }
 
        cout << "4\n";
    }
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
