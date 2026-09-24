#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
    void sol() {
        int n;
        cin >> n;
        vector<vector<int>> a(n + 1, vector<int>(3)), bh(n + 1, vector<int>(3));
        vector<int> d(n + 1);
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            cin >> d[i];
            for (int j = 0; j < d[i]; j++) {
                cin >> a[i][j];
                bh[i][j] = ++cnt;
            }
        }
        vector<int> ls(cnt + 1), vis(cnt + 1);
        vector<int> nex(cnt + 1); 
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < d[i]; j++) {
                int v = a[i][j];
                for (int k = 0; k < d[v]; k++) {
                    if (a[v][k] == i) {
                        ls[bh[i][j]] = bh[v][k];
                        nex[bh[i][j]] = (bh[v][(k + 1) % d[v]]);
                    }
                }
            }
        }
        vector<int> ans(cnt + 1);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < d[i]; j++) {
                int x = bh[i][j];
                if (vis[x]) continue;
                vector<int> p;
                int res = 0;
                while (!vis[x]) {
                    p.push_back(x);
                    if (vis[ls[x]] && !ans[ls[x]]);
                    else res++;
                    vis[x] = 1;
                    x = nex[x];
                }
                for (int x : p) ans[x] = res;
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << ans[bh[i][0]] << "\n";
        }
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
    return Xbbbz ::main(), 0;
}