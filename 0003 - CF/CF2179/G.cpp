#include <bits/stdc++.h>
 
using namespace std;
 
const int inf = 1e9;
void sol() {
    int n;
    cin >> n;
    vector<int> p(3);
    vector dis (3, vector(n * n + 1, 0));
    vector a(n + 1, vector(n + 1, 0));
    p[0] = 1;
    
    auto ask = [&] (int x, int y) -> int {
        cout << "? " << x << " " << y << endl;
        int t;
        cin >> t;
        return t;
    };
 
    int mxpos = 0;
    for (int i = 1; i <= n * n; i++) {
        dis[0][i] = ask(p[0], i);
        if (dis[0][i] > dis[0][mxpos]) {
            mxpos = i;
            p[1] = i;
        }
    }
 
    mxpos = 0;
 
    if (dis[0][p[1]] == 2 * n - 2) {
        for (int i = 1; i <= n * n; i++) {
            if (dis[0][i] == 1) {
                p[0] = i;
            }
        }
    }
    
    for (int i = 1; i <= n * n; i++) {
        dis[1][i] = ask(p[1], i);
        if (dis[1][i] == n - 1) {
            dis[0][i] = ask(p[0], i);
            if (dis[0][i] > dis[0][mxpos]) {
                mxpos = i;
                p[2] = i;
            }
            
        }
    }
 
    for (int i = 1; i <= n * n; i++) {
        dis[2][i] = ask(p[2], i);
    }
 
    for (int i = 1; i <= n * n; i++) {
        int t1 = dis[1][i] + dis[2][i];
        int t2 = dis[1][i] - dis[2][i];
        int x = (t1 + 1 - n) / 2;
        int y = (t2 + n - 1) / 2;
        a[x + 1][y + 1] = i;
    }
 
    cout << "!" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
 
 
 
/*
0
2
2
3
1
3
4
2
1
 
4
2
2
1
3
1
0
2
3
*/
