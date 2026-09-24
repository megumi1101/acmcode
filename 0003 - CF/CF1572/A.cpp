#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
 
    void sol() {
        int n;
        cin >> n;
        vector <int> ed[n + 5];
        int rd[n + 5];
        int dis[n + 5];
        memset(rd, 0, sizeof(rd));
        memset(dis, 0, sizeof(dis));
        for (int i = 1; i <= n; i++) {
            int k;
            cin >> k;
            for (int j = 1; j <= k; j++) {
                int x;
                cin >> x;
                ed[x].push_back(i);
                rd[i]++;
            }
        }
        queue<int> q;
        int res = 0, ans = 0;
        for (int i = 1; i <= n; i++) {
            if (!rd[i]) q.push(i), res++;
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : ed[u]) {
                rd[v]--;
                if (u < v) dis[v] = max(dis[v], dis[u]);
                else dis[v] = max(dis[v], dis[u] + 1);
                if (!rd[v]) q.push(v), res++;
            }
        }
        if (res != n) {
            cout << "-1\n";
        }
        else {
            for (int i = 1; i <= n; i++) ans = max (ans, dis[i]);
            ans++;
            cout << ans << "\n";
        }
    }
   
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T;
        cin >> T;
        while (T--) {
            sol();
        }
    }
 
    #undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
