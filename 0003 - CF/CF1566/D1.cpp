#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
 
    
 
    void sol() {
        int n, m;
        cin >> n >> m;
        int a[m + 1];
        int ans = 0;
        for (int i = 1; i <= m; i++) cin >> a[i];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j < i; j++) {
                if (a[j] < a[i]) ans++;
            }
        }
        cout << ans << "\n";
    }
   
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T;
        cin >> T;
        while (T--) {
            sol();
        }
    }
 
    #undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
