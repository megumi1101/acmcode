#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
    void sol() {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        int mx = -1;
        for (int i = 3; i <= n; i++) {
            cout << "? 1 2 " << i << endl;
            cin >> a[i];
            mx = max(a[i], mx);
        }
        int cnt = 0, cnt1 = 0;
        int pos = -1;
        for (int i = 3; i <= n; i++) {
            if (a[i] == mx) pos = i, cnt++;
        }
        fill(a.begin(), a.end(), 0);
        int pos2 = -1;
        int mx2 = -1;
        int t = 3;
        if (pos == 3) t++;
        
        for (int i = 1; i <= n; i++) {
            if (i == pos || i == t) continue;
            cout << "? " << t  << " " << pos << " " << i << endl;
            cin >> a[i];
            if (a[i] > mx2) {
                mx2 = a[i];
                pos2 = i;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (a[i] == mx2) cnt1++;
        }
        if (mx > mx2) pos = 1, pos2 = 2;
        if (mx == mx2) {
            if (cnt == n - 2) pos = 1, pos2 = 2;
            if (cnt1 == n - 2) pos2 = t;
        }
        if (mx2 > mx) {
            if (cnt1 == n - 2) pos2 = t;
        }
        // cerr << " cnt1 = " <<cnt1 << endl;
        cout <<"! " << pos << " " << pos2 << endl;
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
 
    }
#undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
