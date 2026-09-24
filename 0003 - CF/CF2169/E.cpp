#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int mod = 998244353;
const int inf = 1e18;
 
struct Point {
    int x, y, c;
};
 
struct cmp1 {
    bool operator() (const Point &a, const Point &b) const {
        return a.x < b.x;
    }
};
 
struct cmp2 {
    bool operator() (const Point &a, const Point &b) const {
        return a.y < b.y;
    }
};
    void sol() {
        int n;
        cin >> n;
        vector<Point> pts(n);
        int sum = 0;
        int ans = -inf;
 
        for (auto &p: pts) cin >> p.x;
        for (auto &p : pts) cin >> p.y;
        for (auto &p : pts) {cin >> p.c; sum += p.c; ans = max(ans, -p.c);}
        
        
        int now = 0;
        
        sort(pts.begin(), pts.end(), cmp1());
        int mn = inf;
        int res = -inf;
        for (auto [x, _, c] : pts) {
            res = max(res, x * 2 - c - mn);
            mn = min(x * 2 + c, mn);
        }
        now += res;
        
        sort(pts.begin(), pts.end(), cmp2());
        mn = inf;
        res = -inf;
        for (auto [_, x, c] : pts) {
            res = max(res, x * 2 - c - mn);
            mn = min(x * 2 + c, mn);
        }
        now += res;
        ans = max(ans, now);
 
        auto get = [&] (vector<Point> &a) -> void {
            sort(a.begin(), a.end(), cmp1());
            
            int mn = inf;
            for (auto[x, y, c] : a) {
                ans = max(ans, (x + y) * 2 - c - mn);
                mn = min((x + y) * 2 + c, mn);
            }
 
            int mnx = inf;
            int mny = inf;
            for (auto[x, y, c] : a) {
                ans = max(ans, (x + y) * 2 - c - mnx - mny);
                mnx = min(x * 2 + c, mnx);
                mny = min(y * 2 + c, mny);
            }
        };
 
        get(pts);
        for (int i = 0; i < 3; i++) {
            for (auto &[x, y, c] : pts) {
                int nx = y;
                int ny = -x;
                x = nx;
                y = ny;
            }
            get(pts);
        }
        
        cout << ans + sum << "\n";
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
    return Xbbbz::main(), 0;
}
