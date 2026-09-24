#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int inf = 1e9;
    int getans(int x) {
        int y = x / 2 + x / 3 + x / 5 + x / 7 - x / 6 - x / 10 - x / 14 - x / 15 - x / 21 - x / 35 + x / 30 + x / 42 + x / 70 + x /105 - x / 210;
        return x - y;
    }
    void sol() { 
        int l, r;
        cin >> l >> r;
        cout << getans(r) - getans(l - 1) << "\n";
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
