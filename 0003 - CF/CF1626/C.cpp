#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
    void sol() {
        int n;
        cin >> n;
        vector<int> a(n + 5), t(n + 5), h(n + 5), f(n + 5);
        for (int i = 1; i <= n; i++) {
            cin >> t[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> h[i];
        }
        f[1] = h[1];
        for (int i = 2; i <= n; i++) {
            int st = lower_bound(t.begin() + 1, t.begin() + n + 1, t[i] - h[i] + 1) - t.begin();
            f[st] = max(f[st], h[i] - (t[i] - t[st]));
            for (int j = st + 1; j <= i; j++) {
                f[j] = max(f[j], f[st] + t[j] - t[st]);
            }
        }
        for (int i = 2; i <= n; i++) {
            if (f[i] - f[i - 1] == t[i] - t[i - 1]) f[i - 1] = 0;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += f[i] * (f[i] + 1) / 2;
        }
        cout << ans << "\n";
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
}
#undef int
int main() {
    return Xbbbz::main(), 0;
}
