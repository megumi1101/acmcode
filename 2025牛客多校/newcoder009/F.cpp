#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
const int inf = 1e18;
    void sol() {
        int sx1, sy1, sx2, sy2, tx1, ty1, tx2, ty2;
        int ans = inf;
        cin >> sx1 >> sy1 >> sx2 >> sy2 >> tx1 >> ty1 >> tx2 >> ty2;
        if (sx1 > sx2) swap(sx1, sx2);
        if (sy1 > sy2) swap(sy1, sy2);
        if (tx1 > tx2) swap(tx1, tx2);
        if (ty1 > ty2) swap(ty1, ty2);
        if ((sx1 == sx2 && tx1 == tx2) || (sy1 == sy2 && ty1 == ty2)) {
            int x = abs(sx1 - tx1);
            int y = abs(sy1 - ty1);
            ans = 2 * max(x, y);
        }
        else {
            if (sy1 == sy2) {
                swap(sx1, tx1);
                swap(sx2, tx2);
                swap(sy1, ty1);
                swap(sy2, ty2);
            }

            int x = abs(sx1 - 1 - tx1);
            int y = abs(sy1 - ty1);
            ans = 2 * max(x, y);
            
            x = abs(sx1 - tx1);
            y = abs(sy1 - ty1);
            ans = min (ans , 2 * max(x, y));

            x = abs(sx1 - 1 - tx1);
            y = abs(sy1 + 1 - ty1);
            ans = min (ans , 2 * max(x, y));

            x = abs(sx1 - tx1);
            y = abs(sy1 + 1 - ty1);
            ans = min (ans , 2 * max(x, y));
            
            ans++;
        } 
        cout << ans << "\n";   
    }

    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
#undef int
}

int main() {
    return Xbbbz::main(), 0;
}