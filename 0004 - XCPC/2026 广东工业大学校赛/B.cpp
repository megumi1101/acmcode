#include <bits/stdc++.h>
 
using namespace std;
 
struct Point {
    int x, y, id;
    bool operator<(const Point& o) const {
        if (x != o.x) return x < o.x;
        return y < o.y;
    }
};
 
void sol() {
    int n;
    if (!(cin >> n)) return;
    
    vector<Point> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
        p[i].id = i + 1;
    }
    
    sort(p.begin(), p.end());
    cout << 3 << " " << n - 3 << "\n";    
    cout << p[0].id << " " << p[1].id << " " << p[2].id << "\n";
    for (int i = 3; i < n; i++) {
        cout << p[i].id << " ";
    }
    cout << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) sol();
}
 
/*
6
0 0
3 0
6 0
6 3
6 6
1 1
*/
