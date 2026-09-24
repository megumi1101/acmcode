#include <bits/stdc++.h>
 
using namespace std;
namespace Xbbbz {
#define int long long
const int inf = 1e9;
    void sol() {
        int n;
        cin >> n;
        vector<int> a(n), vis(n + 5);
        for (auto &i : a) cin >> i, vis[i]++;
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            if (vis[i] != i) {
                if (vis[i] > i) ans += vis[i] - i;
                else ans += vis[i];
            }
        }
        cout << ans << "\n";
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
