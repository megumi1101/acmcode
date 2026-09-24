#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int mod = 20100403;
    void sol() {
        set<pair<int, int>> s;
        int n, k;
        cin >> n >> k;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            s.insert(make_pair(x, i));
        }
        while (!s.empty()) {
            auto it = s.begin();
            auto [x, y] = *it;
            int tx = x * k;
            auto it2 = s.lower_bound(make_pair(tx, 0));
            if (it2 == s.end()) {
                ans++;
                s.erase(it);
                continue;
            }
            auto [sx, sy] = *it2;
            if (sx == tx) {
                s.erase(it);
                s.erase(it2);
            }
            else {
                ans++;
                s.erase(it);
            }
        }
        cout << ans << "\n";
    }
 
    void main() {
        ios::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
#undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
