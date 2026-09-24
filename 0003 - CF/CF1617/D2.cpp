#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int inf = 1e9;
    void sol() {
        int n;
        cin >> n;
        vector<int> pd(n + 5, -1);
        vector<int> a(n + 5, -1);
        int pos0, pos1;
        int a0, a1;
        for (int i = 1; i <= n; i += 3) {
            cout << "? " << i << " " << i + 1 << " " << i + 2 << endl;
            cin >> pd[i];
            if (pd[i] == 1) {
                pos1 = i;
            } else {
                pos0 = i;
            }
        }
 
        auto get = [&](int p, int op) -> void {
            if (op == 1) {
                int x, y;
                cout << "? " << a0 << " " << p << " " << p + 1 << endl;
                cin >> x;
                cout << "? " << a0 << " " << p << " " << p + 2 << endl;
                cin >> y;
                if (x && y) {
                    a[p] = a[p + 1] = a[p + 2] = 1;
                } else if (x && !y) {
                    a[p] = a[p + 1] = 1;
                    a[p + 2] = 0;
                } else if (!x && y) {
                    a[p] = a[p + 2] = 1;
                    a[p + 1] = 0;
                } else {
                    a[p + 1] = a[p + 2] = 1;
                    a[p] = 0;
                }
            } else {
                int x, y;
                cout << "? " << a1 << " " << p << " " << p + 1 << endl;
                cin >> x;
                cout << "? " << a1 << " " << p << " " << p + 2 << endl;
                cin >> y;
                if (!x && !y) {
                    a[p] = a[p + 1] = a[p + 2] = 0;
                } else if (!x && y) {
                    a[p] = a[p + 1] = 0;
                    a[p + 2] = 1;
                } else if (x && !y) {
                    a[p] = a[p + 2] = 0;
                    a[p + 1] = 1;
                } else {
                    a[p + 1] = a[p + 2] = 0;
                    a[p] = 1;
                }
            }
        };
 
        int t1, t2, t3, t4;
        cout << "? " << pos0 << " " << pos0 + 1 << " " << pos1 << endl;
        cin >> t1;
        cout << "? " << pos0 << " " << pos0 + 1 << " " << pos1 + 1 << endl;
        cin >> t2;
        t1 |= t2;
        cout << "? " << pos0 << " " << pos0 + 2 << " " << pos1 << endl;
        cin >> t3;
        cout << "? " << pos0 << " " << pos0 + 2 << " " << pos1 + 1 << endl;
        cin >> t4;
        t3 |= t4;
 
        if (!t1 && !t3) {
            a[pos0] = a[pos0 + 1] = a[pos0 + 2] = 0;
        } else if (!t1 && t3) {
            a[pos0] = a[pos0 + 1] = 0;
            a[pos0 + 2] = 1;
        } else if (t1 && !t3) {
            a[pos0] = a[pos0 + 2] = 0;
            a[pos0 + 1] = 1;
        } else {
            a[pos0 + 1] = a[pos0 + 2] = 0;
            a[pos0] = 1;
        }
        if (a[pos0] == 0) a0 = pos0;
        if (a[pos0 + 1] == 0) a0 = pos0 + 1;
 
        get(pos1, 1);
        if (a[pos1] == 1) a1 = pos1;
        if (a[pos1 + 1] == 1) a1 = pos1 + 1;
 
        for (int i = 1; i <= n; i += 3) {
            if (i == pos0 || i == pos1) continue;
            get(i, pd[i]);
        }
 
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 0) cnt++;
        }
        cout << "! " << cnt << " ";
        for (int i = 1; i <= n; i++) if (!a[i]) cout << i << " ";
        cout << endl;
    }
    
    void main() {
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
#undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
