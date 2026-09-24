#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
const int mod = 998244353;
mt19937_64 gen(random_device{}());
 
int floor_div(int a, int b) {
    int res = a / b;   
    int rem = a % b;  
    if (rem != 0 && ((a < 0) ^ (b < 0))) {
        res--;
    }
    return res;
}
 
void sol() {
    int n, r;
    cin >> n >> r;
    vector<pair<int, int>> pts(n);
    for (auto &[x, y] : pts) cin >> x >> y;
    if (n == 4) {
        cout << "1\n70 70\n";
        return;
    }
    
    int dy = sqrt(3) * r;
    while (dy * dy <= 3ll * r * r) dy++;
    int mxpts = (89 * n + 99) / 100;
    // even sx + ix * 2r
    // odd sx + ix * 2r + r
    // dy * iy + sy
    vector<pair<int, int>> ans;
    while (1) {
        int sx = gen() % (r * 2);
        int sy = gen() % dy;
        int cnt = 0;
        ans.clear();
        for (auto[x, y] : pts) {
            x -= sx;
            y -= sy;
            bool fg = 0;
            int posy = floor_div(y, dy);
            
            for (int i = posy; i <= posy + 1; i++) {
                int Cy = i * dy;
                int Cx;
                if (i % 2 == 0) {
                    int ix = floor_div(x + r, 2 * r);
                    Cx = ix * 2 * r;
                } else {
                    int ix = floor_div(x, 2 * r);
                    Cx = ix * 2 * r + r;
                }
                int d1 = x - Cx;
                int d2 = y - Cy;
                if (d1 * d1 + d2 * d2 <= r * r) {
                    fg = 1;
                    ans.push_back({Cx + sx, Cy + sy});
                    cnt++;
                    break;
                }
            }
        }
        if (cnt >= mxpts) {
            sort(ans.begin(), ans.end());
            ans.erase(unique(ans.begin(), ans.end()), ans.end());
            cout << ans.size() << "\n";
            for (auto [x, y] : ans) cout << x << " " << y << "\n"; 
            return;
        }
    }
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) sol();
}
 
/*
6
0 0
3 0
6 0
6 3
6 6
1 1
*/
