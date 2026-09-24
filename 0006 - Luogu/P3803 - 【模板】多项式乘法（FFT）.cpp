#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
#define int long long
    const int mod = 998244353;
    const int N = 1e6 + 10;
    const double PI = acos(-1.0);
    int fap(int a, int b) {
        int res = 1;
        while (b) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod; b /= 2;
        }
        return res;
    }
    int gg = 3, gn = fap(3, mod - 2);
    vector<int> R(N << 2);

    void ntt(vector<int> &a, int n, int op) {
        for(int i = 0; i < n; ++i)
            R[i] = R[i / 2] / 2 + ((i & 1) ? n / 2 : 0);
        
        for(int i = 0; i < n; ++i)
            if(i < R[i]) swap(a[i], a[R[i]]);
        
        for(int m = 2; m <= n; m <<= 1) {        
            int w1 = fap(op == 1 ? gg : gn, (mod - 1) / m);
            for(int i = 0; i < n; i += m) {       
                int wk = 1;
                for(int j = 0; j < m / 2; ++j) { 
                    int x = a[i + j], y = a[i + j + m / 2] * wk % mod;
                    a[i + j] = (x + y) % mod; 
                    a[i + j + m / 2] = (x - y + mod) % mod; 
                    wk = wk * w1 % mod;
                }
            }
        }
    }

    
    void sol() {
        int n, m;
        cin >> n >> m;
        int tmp = 1;
        for (; tmp <= n + m; tmp <<= 1);
        vector<int> a(tmp + 5), b(tmp + 5);
        for (int i = 0; i <= n; i++) cin >> a[i];
        for (int i = 0; i <= m; i++) cin >> b[i];
        ntt(a, tmp, 1);
        ntt(b, tmp, 1);
        for (int i = 0; i < tmp; i++) a[i] = a[i] * b[i];
        ntt(a, tmp, -1);
        int inv = fap(tmp, mod - 2);
        for (int i = 0; i <= n + m; i++) {
            cout << a[i] * inv % mod << " ";
        }
    }

    
    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T = 1;
        // cin >> T;
        // init();
        while (T--) {
            sol();
        }
    }
#undef int
}

int main() {
    return Xbbbz::main(), 0;
}