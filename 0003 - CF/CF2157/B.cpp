#include <bits/stdc++.h>
 
using namespace std;
namespace Xbbbz {
#define int long long
const int inf = 1e9;
    void sol() {
        int n, x, y;
        cin >> n >> x >> y;
        string s;
        cin >> s;
        int cnt = 0;
        for (auto c : s) {
            if (c == '4') cnt++;
        }
        x = abs(x);
        y = abs(y);
        if (x < y) swap(x, y);
        if (x <= n) {
            if (x + y <= 2 * n - cnt) {
                cout << "YES\n";
                return;
            }
        }
        cout << "NO\n";
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
