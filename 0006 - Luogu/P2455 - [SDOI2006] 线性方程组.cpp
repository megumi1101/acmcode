#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
    #define int long long
    const long double eps = 1e-10;
    long double a[105][105];
    int gsyd(int n) {
        int nw = 1;
        for (int j = 1; j <= n; j++) {
            int mxi = nw;
            for (int i = nw + 1; i <= n; i++) {
                if (fabs(a[i][j]) > fabs(a[mxi][j])) mxi = i;    
            }
            if (fabs(a[mxi][j]) < eps) continue;
            swap(a[nw], a[mxi]);
            for (int i = 1; i <= n; i++) {
                if (i == nw) continue;
                double x = a[i][j] / a[nw][j];
                for (int k = j; k <= n + 1; k++) {
                    a[i][k] -= x * a[nw][k];
                }
            }
            nw++;
        }
        if (nw == n + 1) return 1;
        else {
            for (int i = nw; i <= n; i++) if (fabs(a[i][n + 1]) > eps) return -1;
            return 0;
        }
    }
    void sol() {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n + 1; j++) {
                cin >> a[i][j];
            }
        }
        int x = gsyd(n);
        if (x != 1) {
            cout << x;
        }
        else {
            for (int i = 1; i <= n; i++) {
                cout << "x" << i << "=" << fixed << setprecision(2) << a[i][n + 1] / a[i][i] << "\n"; 
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