#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    const int N = 1e5 + 10;
    const int mod = 998244353;
    vector<int> tmp[2];
    int vis[N][2];
    void sol() {
        int n;
        cin >> n;
        int a[n + 5], b[n + 5];
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];
        sort(a + 1, a + 1 + n);
        sort(b + 1, b + 1 + n);
        bool fg = 0;
        for (int i = 1; i <= n; i++) {
            if (b[i] - a[i] == 0 || b[i] - a[i] == 1) {
                ;
            }
            else {
                fg = 1;
            }
        }
        if (fg) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T;
        cin >> T;
        while (T--) sol();
    }   
    
    #undef int
}
int main() {
    return Xbbbz::main(), 0;
}
/*
1 3
5 4 3
*/
