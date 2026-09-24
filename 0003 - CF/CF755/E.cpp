#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    #define ull unsigned long long
    constexpr int mod = 998244353;
    constexpr int Bas = 257;
 
    void sol() {
        int n, k;
        cin >> n >> k;
        if (k == 1 || k > 3 || n <= 3) {
            cout << "-1\n";
            return;
        }
        if (k == 2) {
            if (n == 4) {
                cout << "-1\n";
                return;
            }
            cout << n - 1 << "\n";
            for (int i = 1; i < n; i++)
                cout << i << " " << i + 1 << "\n";
        }
        else
        {
            cout << n - 1 << "\n";
            cout << 2 << " " << n << "\n";
            for (int i = 2; i < n; i++) {
                cout << 1 << " " << i << "\n";
            }
        }
    }
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        // init();
        int T = 1;
        // cin >> T;
        while (T--) sol();
        
    }
#undef int
}
 
int main() {
    return Xbbbz::main(), 0;
}
