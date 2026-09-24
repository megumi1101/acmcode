#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
    void sol() {
        int k, x;
        cin >> k >> x;
        if (x == (1ll << k)) {
            cout << "0\n\n";
            return;
        }
        bool fg = 0;
        if (x > (1ll << k)) x = (1ll << (k + 1)) - x, fg = 1;
        vector<int> ans;
        for (int i = 1; i <= 120; i++) {
            if (x & (1ll << k)) x = 2 * x - (1ll << (k + 1)), ans.push_back(2);
            else ans.push_back(1), x *= 2;
            if (x == (1ll << k)) break;
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for (auto tt : ans) {
            if (fg) {
                if (tt == 2)cout << 1 <<" ";
                if (tt == 1) cout << 2 << " ";
            }
            else cout << tt << " ";
        }
        cout << "\n";
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
