#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    int a[505];
    int n;
    struct node {
        int x, y;
        friend bool operator < (node c, node b) {
            return a[c.x] - a[c.y] < a[b.x] - a[b.y];
        }
    };
    priority_queue<node> q;
    void sol() {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (a[i] < a[j]) q.push((node){j, i});
                else q.push((node){i, j});
            }
        }
        while (!q.empty()) {
            node u = q.top();
            q.pop();
            int x = u.x;
            int y = u.y;
            cout << "? " << x << " " << y << endl;
            string s;
            cin >> s;
            if (s[0] == 'Y') {
                cout << "! " << x << " " << y << endl;
                return;
            } 
        }
        cout << "! 0 0" << endl;
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        // cin >> T;
        while(T--) sol();
    }
    #undef int
} 
 
int main() {
    return Xbbbz :: main(), 0;
}
