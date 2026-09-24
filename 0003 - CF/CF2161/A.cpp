#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
const int inf = 1e9 + 10000;
    void sol() {
        int r, x, d, n;
        cin >> r >> x >> d >> n;
        string s;
        cin >> s;
        int ans = 0;
        for (auto c : s) {
            if (c == '2') {
                if (r >= x) continue;
                else ans++;
                r = max(r - d, 0);
            } else {
                ans++;
                r = max(r - d, 0);
            }
        }
        cout << ans << "\n";
    }
    
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
}
 
int main() {
    return Xbbbz::main(), 0;
}
