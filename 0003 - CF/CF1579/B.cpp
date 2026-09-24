#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    void sol() {
        int n;
        cin >> n;
        vector <int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        int b[n + 1][3];
        int cnt = 0;
        for (int i = 2; i <= n; i++) {
            if (a[i] >= a[i - 1]) continue;
            else {
                int x = lower_bound(a.begin() + 1, a.begin() + i, a[i]) - a.begin();
                b[++cnt][0] = x;
                b[cnt][1] = i;
                b[cnt][2] =  i - x;
                int y = a[i];
                for (int j = i; j > x; j--) {
                    a[j] = a[j - 1];
                }
                a[x] = y;
            }
        }
        cout << cnt << "\n";
        for (int i = 1; i <= cnt; i++) {
            for (int j = 0; j < 3; j++) {
                cout << b[i][j] << " ";
            }
            cout << "\n";
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
