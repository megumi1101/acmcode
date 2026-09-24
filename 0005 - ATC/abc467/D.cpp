#include <bits/stdc++.h>

using namespace std;

#define int long long

void sol() {
    int Px, Py, Qx, Qy;
    int Rx, Ry, Sx, Sy;
    cin >> Px >> Py >> Qx >> Qy;
    cin >> Rx >> Ry >> Sx >> Sy;

    int vx1 = Qx - Px;
    int vy1 = Qy - Py;
    int vx2 = Sx - Rx;
    int vy2 = Sy - Ry;
    int cross = vx1 * vy2 - vy1 * vx2;
    if (cross != 0) {
        cout << "Yes\n";
        return;
    }
    int dx = (Rx + Sx) - (Px + Qx);
    int dy = (Ry + Sy) - (Py + Qy);
    int dot = dx * vx1 + dy * vy1;
    cout << (dot == 0 ? "Yes" : "No") << "\n";
}
signed main() {
    ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
}