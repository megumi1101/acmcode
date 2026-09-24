#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
int lg(int x) {
    return 64 - __builtin_clzll(x - 1);
}
    void sol() {
        int a, b;
        cin >> a >> b;
        int ta = a;
        int tb = b;
        int ca = 0, cb = 0;
        while ((ta | tb) != tb) {
            ta++;
            ca++;
        }
        if (ta != tb) ca++;
 
        ta = a;
        tb = b;
        while ((ta | tb) != tb) {
            tb++;
            cb++;
        }
        if (ta != tb) cb++;
 
        cout << min(ca, cb) << '\n';
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
}
 
int main() {
    return Xbbbz :: main(), 0;
}
