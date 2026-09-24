#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
    #define int long long
    constexpr int mod = 998244353;
    struct node {
        int u, v, w;
    };
    void sol() {
        int n, m;
        cin >> n >> m;
        vector<node> a(m + 5);
        vector<int> f(n + 5), g(n + 5);
        for (int i = 1; i <= m; i++) {
            cin >> a[i].u >> a[i].v >> a[i].w;
        }
        sort(a.begin() + 1, a.begin() + m + 1, [&](const node &b, const node &c) {
            return  b.w < c.w;
        });
        for (int i = 1, j; i <= m; i = j + 1) {
            j = i;
            while (a[j + 1].w == a[i].w) j++;
            for (int k = i; k <= j; k++) {
                g[a[k].u] = f[a[k].u];
            }
            for (int k = i; k <= j; k++) {
                f[a[k].v] = max(f[a[k].v], g[a[k].u] + 1);
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) ans = max(ans, f[i]);
        cout << ans << "\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        // init();
        int T = 1;
        // cin >> T;
        while (T--) sol(); 
    }
#undef int
}

int main() {
    return Xbbbz ::main(), 0;
}
