#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
    #define int long long
    const int mod = 1e9 + 7;
    int fap(int a, int b) {
        int res = 1;
        while (b) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod; b /= 2;
        }
        return res;
    }
    int a[405][805];
    int gsyd(int n) {
        for (int j = 1; j <= n; j++) {
            int mxi = j;
            for (int i = j + 1; i <= n; i++) {
                if (abs(a[i][j]) > abs(a[mxi][j])) mxi = i;    
            }
            if (abs(a[mxi][j]) == 0) return 0;
            swap(a[j], a[mxi]);
            for (int i = 1; i <= n; i++) {
                if (i == j) continue;
                int x = a[i][j] * fap(a[j][j], mod - 2) % mod;
                for (int k = j; k <= 2 * n; k++) {
                    a[i][k] -= x * a[j][k] % mod;
                    ((a[i][k] %= mod) += mod) %= mod;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = n + 1; j <= 2 * n; j++) {
                (a[i][j] *= fap(a[i][i], mod - 2)) %= mod;
            }
        }
        return 1;        
    }
    void sol() {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = 1; i <= n; i++) {
            a[i][i + n] = 1;
        }
        int x = gsyd(n);
        if (x != 1) {
            cout << "No Solution";
        }
        else {
            for (int i = 1; i <= n; i++) {
                for (int j = n + 1; j <= 2 * n; j++) {
                    cout << a[i][j]  << " ";
                }
                cout << "\n";
            }
        }
    }

    void main() {
        ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
    #undef int
}

int main() {
    return Xbbbz::main(), 0;
}