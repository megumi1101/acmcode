#include <bits/stdc++.h>
 
using namespace std;
 
namespace xbbbz{
    #define int long long
    const int inf = 1e18;
    const int N = 1e3 + 10;
    int n, cnt = 0, mx;
    vector<int>ed[N];
    int a[N], df[N];
    void dfs(int u, int f) {
        df[++cnt] = u;
        for (int v : ed[u]) {
            if (v == f) continue;
            dfs(v, u);
            df[++cnt] = u;
        }
    }
    bool pd(int l, int r) {
        set<int> S;
        for (int i = l; i <= r; i++) {
            S.insert(df[i]);
        }
        cout << "? " << S.size() << " ";
        for (int u : S) cout << u << " ";
        cout << endl;
        int x; cin >> x;
        if (x == mx) {
            return 1;
        }
        return 0;
    }
    void sol () {
        cin >> n;
        for (int i = 1; i < n; i++) {
            int x, y;
            cin >> x >> y;
            ed[x].push_back(y);
            ed[y].push_back(x);
        }
        cout << "? " << n << " ";
        for (int i = 1; i <= n; i++) cout << i << " ";
        cout << endl;
        cin >> mx;
        dfs(1, 0);
        int l = 1, r = cnt;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (pd(l, mid)) r = mid;
            else l = mid;
        }
        cout << "! " << df[l] << " " << df[r] << endl; 
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
 
    #undef int
}
 
int main() {
    return xbbbz::main(),0;
}
/*
6
1 2
2 3
2 4
1 5
5 6
10
10
10
10
10
10
*/
