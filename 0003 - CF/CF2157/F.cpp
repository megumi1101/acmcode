#include <bits/stdc++.h>
 
using namespace std;
namespace Xbbbz {
#define int long long
const int inf = 1e9;
    void sol() {
        const int k = 64;
        int n;
        cin >> n;
        vector<pair<int, int>> ops;
        int step = 1;
        for (int it = 0; it < 3; it++) {
            for (int r = 1; r < k; r++) {
                for (int i = n / step; i >= 1; i--) {
                    if (i % k == r) {
                    ops.emplace_back(i * step, step);
                    }
                }
            }
            step *= k;
        }
        cout << ops.size() << "\n";
        for (auto[x, y] : ops) cout << x << " " << y << "\n";
        cout << "\n";
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
}
#undef int
int main() {
    return Xbbbz::main(),0;
}
