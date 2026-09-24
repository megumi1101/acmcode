#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    struct Point {
        int x = -1, y = -1;
    };
    void sol() {
        int n, m, k;
        cin >> n >> m >> k;
        int x[n + 5], y[m + 5];
        Point p1[k + 5], p2[k + 5];
        set<int> visx, visy;
        for (int i = 1; i <= n; i++) {
            cin >> x[i];
            visx.insert(x[i]);
        }
        for (int i = 1; i <= m; i++) {
            cin >> y[i];
            visy.insert(y[i]);
        }
 
        int cnt1 = 0;
        int cnt2 = 0;
        for (int i = 1; i <= k; i++) {
            int xx, yy;
            cin >> xx >> yy;
            if (visx.find(xx) != visx.end() && visy.find(yy) != visy.end()) continue;
            if (visx.find(xx) != visx.end()) {
                p1[++cnt1] = (Point){xx, *visy.lower_bound(yy)};
            }
            else {
                p2[++cnt2] = (Point){yy, *visx.lower_bound(xx)};
            }
        }
 
        sort(p1 + 1, p1 + 1 + cnt1, [&](Point a, Point b) {
            if (a.y == b.y) return a.x < b.x;
            return a.y < b.y;
        });
        int ans = 0;
        int res = 1;
        int sum = 0;
        for (int i = 1; i <= cnt1; i++) {
            if (p1[i].y == p1[i + 1].y) {
                if (p1[i].x == p1[i + 1].x) {
                    res++;
                }
                else {
                    ans += sum * res;
                    sum += res;
                    res = 1;
                }
            }
            else {
                ans += sum * res;
                sum = 0;
                res = 1;
            }
        }
 
        sort(p2 + 1, p2 + 1 + cnt2, [&](Point a, Point b) {
            if (a.y == b.y) return a.x < b.x;
            return a.y < b.y;
        });
 
        for (int i = 1; i <= cnt2 + 1; i++) {
            if (p2[i].y == p2[i + 1].y) {
                if (p2[i].x == p2[i + 1].x) {
                    res++;
                }
                else {
                    ans += sum * res;
                    sum += res;
                    res = 1;
                }
            }
            else {
                ans += sum * res;
                sum = 0;
                res = 1;
            }
        }
 
        cout << ans << "\n";
    }
   
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T;
        cin >> T;
        while (T--) {
            sol();
        }
    }
 
    #undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
