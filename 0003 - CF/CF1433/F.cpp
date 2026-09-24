#include <bits/stdc++.h>
 
using namespace std;
 
namespace Xbbbz {
#define int long long
const int inf = 1e18;
    void sol() {
        int n, m, k;
        cin >> n >> m >> k;
        
        vector g(k, -inf);
        vector ng(k, -inf);
        g[0] = ng[0] = 0;
        vector a(n, vector(m, (int)0));
        for (auto &v : a) for (auto &i : v) cin >> i;
        for (int i = 0; i < n; i++) {
            int mx = m / 2;
            vector f(m + 1, vector(k, -inf));
            vector nf(m + 1, vector(k, -inf));
            f[0][0] = nf[0][0] = 0;
            
 
            for (int j = 0; j < m; j++) {
                int x = a[i][j];
                int xk = x % k;
                f = nf;
                for (int ct = 0; ct < m; ct++) {
                    for (int l = 0; l < k; l++) {
                        f[ct + 1][(l + xk) % k] = max(f[ct + 1][(l + xk) % k], nf[ct][l] + x);
                    }
                }
                
                swap(nf, f);
            }
            
 
            vector b(k, -inf);
            for (int ct = 0; ct <= m / 2; ct++) {
                for (int l = 0; l < k; l++) {
                    b[l] = max(b[l], nf[ct][l]);
                }
            }
            
            for (int l = 0; l < k; l++) {
                for (int t = 0; t < k; t++) {
                    g[(l + t) % k] = max(g[(l + t) % k], ng[l] + b[t]);
                }
            }
            
            swap(g, ng);
        }
 
        cout << ng[0] << "\n";
    }
 
    void main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
}
 
#undef int
int main() {
    return Xbbbz::main(), 0;
}
