#include <bits/stdc++.h>
 
using namespace std;
 
const int inf = 1e9;
 
int ask (int x, int y, int x_, int y_) {
    cout << "? " << x << " " << y << " " << x_ << " " << y_ << endl;
    int op;
    cin >> op;
    return op; 
}
 
void sol() {
    int n;
    cin >> n;
    
    int min_add = inf, max_add = -inf;
    int min_sub = inf, max_sub = -inf;
 
    int x = 1, y = n;
    while (x <= n && y >= 1) {
        if (ask(1, 1, x, y) == 1) {
            min_add = min(min_add, x + y);
            y--; 
        } else {
            x++; 
        }
    }
 
    x = n; y = 1;
    while (x >= 1 && y <= n) {
        if (ask(x, y, n, n) == 1) {
            max_add = max(max_add, x + y);
            y++; 
        } else {
            x--; 
        }
    }
 
    x = 1; y = 1;
    while (x <= n && y <= n) {
        if (ask(1, y, x, n) == 1) {
            min_sub = min(min_sub, x - y);
            y++; 
        } else {
            x++; 
        }
    }
 
    x = n; y = n;
    while (x >= 1 && y >= 1) {
        if (ask(x, 1, n, y) == 1) {
            max_sub = max(max_sub, x - y);
            y--; 
        } else {
            x--; 
        }
    }
 
    int ans = max(max_add - min_add, max_sub - min_sub);
    cout << "! " << ans << endl;
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) sol();
}
 
/*
2
2 2 4
5 2
4 7
3 3 8
1 4 3
5 1 5
3 4 1
*/
