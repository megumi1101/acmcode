#include <bits/stdc++.h>
 
using namespace std;
#define int long long
 
void sol() {
    int n, m;
    int C;
    cin >> n >> m >> C;
    bool swapped = (n > m);
    vector a(n + 1, vector<int> (m + 1, 0));
    auto sum = a;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            sum[i][j] = a[i][j] + sum[i][j - 1];
        }
    }
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sum[i][j] += sum[i - 1][j];
        }
    }
    
    auto getsum = [&](int x, int y, int x_, int y_) -> int {
        return sum[x_][y_] - sum[x - 1][y_] - sum[x_][y - 1] + sum[x - 1][y - 1];
    };
    
 
    int ans = 0;
    for (int upline = 2; upline <= n + m; upline++) {
        int dnline = upline + ((C - 4) / 2);
        if (dnline > n + m) break;
        [&](this auto &&self, int L, int R, int l, int r) -> void {
            if (L > R) return;
            int mid = L + (R - L) / 2;
            int best = -1, best_sum = -1;
            for (int xdn = max(l, mid); xdn <= r; xdn++) {
                int ydn = dnline - xdn;
                int tmp = getsum(mid, upline - mid, xdn, ydn);
                if (tmp > best_sum) {
                    best = xdn;
                    best_sum = tmp;
                }
            }
            ans = max(ans, best_sum);
            if (best != -1) {
                self(L, mid - 1, l, best);
                self(mid + 1, R, best, r);
            } else {
                self(L, mid - 1, l, r);
                self(mid + 1, R, l, r);
            }
        } (max(1ll, upline - m), min(n, upline - 1), max(1ll, dnline - m), min(n, dnline - 1));
    }
    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
 
/*
2
2 2 4
5 2
4 7
3 3 8
1 4 3
5 1 5
3 4 1
*/
