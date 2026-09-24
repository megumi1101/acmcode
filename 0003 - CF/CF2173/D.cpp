#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int mod = 998244353;
const int inf = 1e18;
    void sol() {
        int n, K;
        cin >> n >> K;
        if (K == 0) {
            cout << "0\n";
            return;
        }
        while (n % 2 == 0) n /= 2;
 
        vector<int> a;
        a.push_back(0);
        while (n) {
            a.push_back(n % 2);
            n /= 2;
        }
        a.push_back(0);
        int siz = a.size();
        n = siz - 1;
        vector<int> ones(n + 1, 0), zeros(n + 1, 0);
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            mx +=  (a[i] == 0);
        }
        vector f(n + 5, vector(n + 5, vector(2, (int)-1)));
        f[0][0][0] = 0;
        
        
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= mx; j++) {
                for (int bit = 0; bit < 2; bit++) {
                    if (f[i][j][bit] == -1) continue;
                    if (bit == 0 && a[i] == 0) {
                        f[i + 1][j][bit] = max(f[i + 1][j][bit], f[i][j][bit]);
                    } 
                    
                    if (bit == 0 && a[i] == 1) {
                        f[i + 1][j][bit] = max(f[i + 1][j][bit], f[i][j][bit]);
                        f[i + 1][j + 1][1] = max(f[i + 1][j + 1][1], f[i][j][bit] + 1);
                    } 
 
                    if (bit == 1 && a[i] == 1) {
                        f[i + 1][j][bit] = max(f[i + 1][j][bit], f[i][j][bit] + 1);
                    }
 
                    if (bit == 1 && a[i] == 0) {
                        f[i + 1][j][0] = max(f[i + 1][j][0], f[i][j][bit]);
                        f[i + 1][j + 1][1] = max(f[i + 1][j + 1][1], f[i][j][bit] + 1);
                    }
                }
            }
        }
        
        
        if (K <= mx) {
             cout << max(f[n][K][0], f[n][K][1]) << "\n";
        } else {
             cout << max(f[n][mx][0], f[n][mx][1]) + K - mx << "\n";
        }
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        cin >> T;
        while (T--) sol();
    }
}
#undef int
 
int main() {
    return Xbbbz::main(), 0;
}
