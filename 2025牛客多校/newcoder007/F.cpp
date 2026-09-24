#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
const int mod = 998244353;
    void sol() {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            ans += x % 2;
        }
        cout << ans * (n - ans) % mod << "\n";
    }
    
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        // cin >> T;
        while (T--) {
            sol();
        }
    }
#undef int
}

int main() {
    return Xbbbz::main(), 0;
}