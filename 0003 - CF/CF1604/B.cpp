#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    const int N = 1e6 + 10;
    void sol() {
        int n;
        cin >> n;
        int a[n + 5];
        bool fg = 1;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        if (n & 1) {
            fg = 0;
            
            for (int i = 1; i < n; i++) {
                if (a[i] >= a[i + 1]) {
                    fg = 1;
                }
            }
        }
        if (fg) cout << "YES\n";
        else cout << "NO\n";
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
