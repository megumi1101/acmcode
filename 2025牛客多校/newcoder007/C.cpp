#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
    void sol() {
        int n;
        cin >> n;
        int ans = 0, tmp = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if (x < tmp) ans = max (ans, tmp - x);
            tmp = max(tmp, x);
        }
        cout << ans << "\n";
    }
    
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T;
        cin >> T;
        while (T--) {
            sol();
        }
    }
}

int main() {
    return Xbbbz::main(), 0;
}