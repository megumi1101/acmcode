#include <bits/stdc++.h>
 
using namespace std;
 
namespace xbbbz{
    #define int long long
    const int inf = 1e18;
    const int N = 2e5 + 10;
    int fa[N << 1];
    int n, m;
    int cnt[N << 1];
    bool vis[N << 1];
    int find(int x) {
        if (fa[x] == x) return x;
        return fa[x] = find(fa[x]);
    }
    void hb (int x, int y) {
        fa[find(x)] = find(y);
    }
    void sol () {
        cin >> n >> m;
        for (int i = 1; i <= 2 * n; i++) {
            fa[i] = i;
            cnt[i] = 0;
            vis[i] = 0;
        }
        while (m--) {
            int x, y;
            string s;
            cin >> x >> y >> s;
            if (s[0] == 'i') {
                hb(x, y + n);
                hb(y, x + n);
            }
            else {
                hb(x, y);
                hb(x + n, y + n);
            }
        }
        for (int i = 1; i <= n; i++) {
            if (find(i) == find(i + n)) {
                cout << "-1\n";
                return;
            }
        }
        for (int i = 1; i <= n; i++) {
            cnt[find(i)]++;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (vis[find(i)]) continue;
            vis[find(i)] = 1;
            vis[find(i + n)] = 1;
            ans += max(cnt[find(i)], cnt[find(i + n)]);
        }
        cout << ans << "\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
 
    #undef int
}
 
int main() {
    return xbbbz::main(), 0;
}
