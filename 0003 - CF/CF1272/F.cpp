#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    // #define int long long
    const int N = 2e5 + 10;
    const int inf = 1e18;
    int vis[205][205][405];
    struct node {
        int x, y, z;
    };
    node lst[205][205][405];
    string s, t;
    int n, m;
    queue<node> q;
    void bfs() {
        q.push((node){0, 0, 0});
        while (!q.empty()) {
 
            node u = q.front(); q.pop();
            int x = u.x;
            int y = u.y;
            int z = u.z;
            if (vis[x][y][z]) continue;
            vis[x][y][z] = 1;
 
            x += (s[x + 1] == '(');
            y += (t[y + 1] == '(');
            z++;
            if (z >= 0 && z <= 200 && x <= n && y <= m && !vis[x][y][z]) {
                q.push((node){x, y, z});
                lst[x][y][z] = u;
            }
 
            x = u.x;
            y = u.y;
            z = u.z;
            x += (s[x + 1] == ')');
            y += (t[y + 1] == ')');
            z--;
            if (z >= 0 && z <= 200 && x <= n && y <= m && !vis[x][y][z]) {
                q.push((node){x, y, z});
                lst[x][y][z] = u;
            }
        }
    }
    void sol() {
        cin >> s;
        cin >> t;
        n= s.size();
        m= t.size();
        s = " " + s;
        t = " " + t;
        bfs();
        node u = lst[n][m][0];
        int tmp = 0;
        string ans = "";
        while (1) {
            int x = u.x;
            int y = u.y;
            int z = u.z;
            if (z > tmp) ans = ")" + ans, tmp = z;
            else ans = "(" + ans, tmp = z;
            if (x == 0 && y == 0 && z == 0) {
                break;
            }
            u = lst[x][y][z];
            // cout << "1";
        }
        cout << ans;
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
    // #undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
