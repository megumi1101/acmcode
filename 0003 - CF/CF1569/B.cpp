#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
 
    void sol() {
        int n;
        string s;
        cin >> n >> s;
        s = ' ' + s;
        int res = 0;
        int lst = 0;
        int fst = n;
        int a[n + 1][n + 1];
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; i++) {
            if (s[i] == '2') {
                fst = min (fst, i);
                res++;
                if (lst) a[lst][i] = 1, a[i][lst] = -1;
                lst = i;
            }
        }
        a[fst][lst] = -1, a[lst][fst] = 1;
        if (res == 0 || res > 2) {
            cout << "YES\n";
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (i == j) {cout << "X"; continue;}
                    if (a[i][j] == 1) cout << "+";
                    if (a[i][j] == -1) cout << "-";
                    if (a[i][j] == 0) cout << "=";
                }
                cout << "\n";
            }
        }
        else cout << "NO\n";
    }
   
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T;
        cin >> T;
        while (T--) {
            sol();
        }
    }
 
}
 
int main() {
    return Xbbbz::main(), 0;
}
