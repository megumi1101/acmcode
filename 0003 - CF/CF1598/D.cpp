#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    void sol() {
        int n; 
        cin >> n;
        int a[n + 5];
        int b[n + 5];
        int ca[n + 5];
        int cb[n + 5];
        memset(ca, 0, sizeof(ca));
        memset(cb, 0, sizeof(cb));
        vector<int> ed[n + 5];
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            cin >> b[i];
            ca[a[i]]++;
            ed[a[i]].push_back(b[i]);
            cb[b[i]]++;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (ca[i] >= 2) {
                for (int u : ed[i]) {
                    ans += (ca[i] - 1) * (cb[u] - 1);
                }
            }
        }
        ans = n * (n - 1) / 2 * (n - 2) / 3 - ans;
        cout << ans << "\n";
    }
    void main () {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T;
        cin >> T;
        while(T--) sol();
    }
    #undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
