#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
    #define int long long
    const int inf = 1e18;
    int n;
    void sol() {
        cin >> n;
        int f[512];
        for (int i = 1; i < 512; i++) f[i] = inf;
        f[0] = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            for (int j = 0; j < 512; j++) {
                if (x > f[j]) {
                    f[j ^ x] = min (f[j ^ x],  x);
                }
            }
        }
        int res = 0;
        for (int i = 0; i < 512; i++) {
            if (f[i] != inf) {
                res++;
            }
        }
        cout << res << "\n";
        for (int i = 0; i < 512; i++) {
            if (f[i] != inf) {
                cout << i << " ";
            }
        }
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        // cin >> T;
        while (T--) {
            sol();
        }
    }
    #undef int
}
 
int main() {
    return Xbbbz ::main(), 0;
}
