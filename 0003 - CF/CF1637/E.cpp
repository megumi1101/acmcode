 #include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define ll long long
// #define int long long
// const int inf = 1e18;
    void sol() {
        int n, m;
        cin >> n >> m;
        set<ll> s;
        map<int, int> mp;
        vector<int> a(n + 1), vis(n + 1), tun(n + 1), tum(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            mp[a[i]]++;
        }
        for (auto[x, y] : mp) {
            vis[y] = 1;
        }
        int siz = 0;
        for (int i = 1; i <= n; i++) {
            if (vis[i]) tun[siz++] = i, tum[i] = siz - 1;
        }
        vector<vector<int>> p(siz);
        for (auto[x, y] : mp) {
            p[tum[y]].push_back(x);
        }
 
        for (int i = 1; i <= m; i++) {
            ll x, y;
            cin >> x >> y;
            s.insert(x << 31 | y);
            s.insert(y << 31 | x);
        }
        
        ll ans = 0;
        for (int i = 0; i < siz; i++) sort(p[i].rbegin(), p[i].rend());
        for (int i = 0; i < siz; i++) {
            for (int j = i; j < siz; j++) {
                for (auto x : p[i]) {
                    for (auto y : p[j]) {
                        if (x == y ) continue;
                        if ((ll)(tun[i] + tun[j]) * (x + y) < ans) break;
                        if (s.find((ll)x << 31 | y) == s.end())
                            ans = (ll)(tun[i] + tun[j]) * (x + y);
                    }
                }
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
#undef int 
}
 
int main() {
    return Xbbbz::main(), 0;
}
