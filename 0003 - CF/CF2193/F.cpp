#include <bits/stdc++.h>
 
using namespace std;
#define int long long
const int inf = 1e18;
void sol() {
    int n , Ax, Ay, Bx, By;
    cin >> n >> Ax >> Ay >> Bx >> By;
    int ans = Bx - Ax;
    vector<pair<int, int>> pts(n);
    for (int i = 0; i < n; i++) cin >> pts[i].first;
    for (int i = 0; i < n; i++) cin >> pts[i].second;
    pts.push_back({Bx, By});
    sort(pts.begin(), pts.end());
    int lst = -1;
    vector<vector<int>> ptx;
    for (auto[x, y] : pts) {
        if (x != lst) {
            ptx.emplace_back();
        }
        ptx[(int)ptx.size() - 1].push_back(y);
        lst = x;
    }
    for (auto &v : ptx) sort(v.begin(), v.end());
    int siz = ptx.size();
    vector f(siz + 1, vector(2, inf));
    int up = Ay, dn = Ay;
    f[0][0] = f[0][1] = 0;
    for (int i = 1; i <= siz; i++) {
        int toup = ptx[i - 1].back(), todn = ptx[i - 1][0];
        int dis = abs(toup - todn);
        f[i][0] = min(f[i][0], dis + abs(dn - todn) + f[i - 1][1]);
        f[i][0] = min(f[i][0], dis + abs(up - todn) + f[i - 1][0]);
        f[i][1] = min(f[i][1], dis + abs(dn - toup) + f[i - 1][1]);
        f[i][1] = min(f[i][1], dis + abs(up - toup) + f[i - 1][0]);
        up = toup, dn = todn;
    }
    cout << ans + f[siz][0] << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
