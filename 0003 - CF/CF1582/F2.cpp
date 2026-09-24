#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    // #define int long long
    // const int inf = 1e18;
    const int N = 1e6 + 5, M = 8192;
    int a[N], n, mn[M], vis[N];
    vector<int> ed[M];
 
    void sol() {
        cin >> n;
        vis[0] = 1;
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            ed[a[i]].push_back(i);
            vis[a[i]] =  1;
        } 
        memset(mn, 0x3f, sizeof(mn));
        mn[0] = 0;
        for (int i = 1; i <= 5000; i++) {
            if (ed[i].empty()) continue;
            for (int j = 0; j < M; j++) {
                int place = mn[j ^ i];
                if (place <= n) {
                    auto it = upper_bound(ed[i].begin(), ed[i].end(), place);
                    if (it != ed[i].end()) {
                        mn[j] = min(mn[j], *it);
                        vis[j] = 1;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < M; i++) {
            if (vis[i]) ans++;
        }
        cout << ans << "\n";
        for (int i = 0; i < M; i++) {
            if (vis[i]) cout << i << " ";
        }
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        // cin >> T;
        while (T--) {
            sol();
        }
    }
    // #undef int
}
//
int main() {
    return Xbbbz ::main(), 0;
}
