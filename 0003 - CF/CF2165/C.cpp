#include <bits/stdc++.h>
 
using namespace std;
namespace Xbbbz {
#define int long long
const int inf = 1e9;
    void sol() {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        set<pair<int, int>, greater<>> tr;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            tr.insert({a[i], i});
        }
        while (k--) {
            int c;
            cin >> c;
            int ans = 0;
            bool fg = 0;
            vector<pair<int, int>> ins, era;
            for (int bit = 29; bit >= 0; bit--) {
                if ((c >> bit) & 1) {
                    if (tr.begin()->first >= c) {
                        cout << ans << "\n";
                        fg = 1;
                        break;
                    }
                    int now = (1 << bit);
                    auto[x, y] = *tr.begin();
                    if (x >= now) {
                        tr.insert({x - now, y});
                        ins.emplace_back(x - now, y);
                    } else {
                        ans += now - x;
                        tr.insert({0, y});
                        ins.emplace_back(0, y);
                    }
                    era.emplace_back(x, y);
                    tr.erase(tr.begin()); 
                    c -= now;
                }
            }
 
            if (fg == 0) cout << ans << "\n";
            for (auto p : era) tr.insert(p);
            for (auto p : ins) tr.erase(p);
        }
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
    return Xbbbz::main(),0;
}
