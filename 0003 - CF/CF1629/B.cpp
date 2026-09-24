#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int mod = 998244353;
 
    void sol() {
        int l,  r, k;
        cin >> l >> r >> k;
        if (l == r) {
            if (l == 1) {
                if (k == 0) cout << "NO\n";
                else cout << "YES\n";
            }
            else cout << "YES\n";
        }
        else {
            int x = r - l + 1;
            if (!(l & 1)) {
                x = x / 2;
            }
            else x = (x + 1) / 2;
            if (x <= k) cout << "YES\n";
            else cout << "NO\n";
        }
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
