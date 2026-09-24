#include <bits/stdc++.h>
using namespace std;
 
namespace Xbbbz {
    #define int long long
    const int N = 5e3 + 10, inf = 1e18;
    vector<int> ed[N];
    // int f[2][N];
    priority_queue<int, vector<int>, greater<int>> q;
    void sol() { 
        int n, m, k;
        cin >> n >> m >> k;
        int a[n + 5], b[n + 5], c[n + 5], d[n + 5], sum[n + 5];
        for (int i = 1; i <= n; i++) d[i] = i;
        for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            d[v] = max(d[v], u);
        }
        for (int i = 1; i <= n; i++) {
            ed[d[i]].push_back(i);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            while (k < a[i]) {
                if (q.empty()) {cout << "-1"; return;}
                k++;
                ans -= q.top();
                q.pop();
            }
            k += b[i];
            for (int v : ed[i]) q.push(c[v]), k--, ans += c[v];
        }
        while (k < 0) {
            if (q.empty()) {cout << "-1"; return;}
            k++;
            ans -= q.top();
            q.pop();
        }
        cout << ans;
        // sum[1] = k;
        // for (int i = 2; i <= n; i++) sum[i] = sum[i - 1] + b[i];
        // for (int i = 0; i <= n; i++) f[0][i] = f[1][i] = -inf;
        // int op = 0;
        // for (int i = 1; i <= n; i++) {
        //     op ^= 1;
        //     f[op][0] = 0;
        //     for (int j = 1; j <= n; j++) f[op][j] = -inf;
        //     for (int v : ed[i]) {
        //         for (int j = n; j >= 1; j--) {
        //             f[op][j] = max(f[op][j - 1])
        //         }
        //     }
            
        // }
    }
    void main() {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
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
