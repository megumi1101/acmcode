#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
    constexpr int N = 1e6 + 10;
    struct node {
        int x, y;
        node (int x, int y) : x(x), y(y) {}
    };
    void sol() {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
        vector<int> dx{1, 0, -1, 0};
        vector<int> dy{0, 1, 0, -1};
        vector<int> ans;
        a[1][m] = n + m - 2;
        a[1][1] = n + m - 2;
        a[n][1] = n + m - 2;
        a[n][m] = n + m - 2;
        queue<node> q;
        q.push({1, m});
        q.push({1, 1});
        q.push({n, 1});
        q.push({n, m});
        while (!q.empty()) {
            node u = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int x = u.x + dx[i];
                int y = u.y + dy[i];
                if (x && x <= n && y && y <= m && !a[x][y]) {
                    a[x][y] = a[u.x][u.y] - 1;
                    q.push({x, y});
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1;j <= m; j++) {
                ans.push_back(a[i][j]);
            }
        }
        sort(ans.begin(), ans.end());
        for (int v : ans) cout << v << " ";
        cout << "\n";
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
#undef int
}
 
int main() {
    return Xbbbz ::main(), 0;
}
/*
3 3
010
101
010
*/
