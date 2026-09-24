#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    void sol() {
        int n; 
        cin >> n;
        int a[n + 5][10];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 5; j++) {
                cin >> a[i][j];
            }
        }
        bool fg = 0;
        for (int i = 1; i <= 5; i++) {
            for (int j = i + 1; j <= 5; j++) {
                int res1 = 0, res2= 0, res3 = 0;
                for (int k = 1; k <= n; k++) {
                    if (a[k][i] && a[k][j]) res3++;
                    else if (a[k][i]) res1++;
                    else if (a[k][j]) res2++;
                    else break;
                }
                if (res1 + res2 + res3 == n && (res1 <= n / 2 && res2 <= n / 2 )) {
                    cout << "YES\n";
                    return;
                }
            }
        }
        cout << "NO\n";
    }
    void main () {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T;
        cin >> T;
        while(T--) sol();
    }
    #undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
