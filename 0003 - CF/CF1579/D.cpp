#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    struct P {
        int x, id;
        friend bool operator < (P a, P b) {
            return a.x < b.x;
        }
        P (int x, int id) : x(x), id(id) {}
        P () : x(0), id(0) {}
    };
    void sol() {
        int n;
        priority_queue<P> q;
        cin >> n;
        int a[n + 10];
        int sum = 0, cnt = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if(a[i]) q.push(P(a[i], i));
            sum += a[i];
        }
        int b[sum + 10][2];
        while (q.size() > 1) {
            P p1 = q.top(); q.pop();
            P p2 = q.top(); q.pop();
            p1.x--;
            if (p1.x) q.push(p1);
            p2.x--;
            if (p2.x) q.push(p2);
            b[++cnt][0] = p1.id;
            b[cnt][1] = p2.id;
        }
        cout << cnt << "\n";
        for (int i = 1; i <= cnt; i++) {
            cout << b[i][0] << " " << b[i][1] << "\n";
        }
    }
 
    void main() {
        int T;
        cin>>T;
        while(T--) sol();
    }
}
 
int main() {
    return Xbbbz::main(), 0;
}
