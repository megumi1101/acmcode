#include <bits/stdc++.h>
using namespace std;

namespace Xbbbz {
#define int long long
const double eps = 1e-9;
int gsyd(int n, vector<vector<double>> &a) {
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
        vector<double> a(n + 1);
        vector<vector<double>> mat(n + 5, vector<double>(n + 5, 0));
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) {
            double res = 0.0;
            for (int j = 1; j <= n; j++) {
                double x;
                cin >> x;
                mat[i][j] = x - a[j];
                res += (x - a[j]) * (x + a[j]) / 2.0;
            }
            mat[i][n + 1] = res;
        }
        gsyd(n, mat);
        for (int i = 1; i <= n; i++) {
            cout << fixed << setprecision(3) << mat[i][n + 1] / mat[i][i] << " ";
        }
    }

    void main() {
        ios::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
        int T = 1;
        // cin >> T;
        while (T--) sol();
    }
#undef int
}

int main() {
    return Xbbbz::main(), 0;
}
