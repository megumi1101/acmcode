#include <bits/stdc++.h>
using namespace std;

namespace Xbbbz {
#define int long long
#define double long double
const int mod = 20100403;
const double eps = 1e-8;
int gsyd(int n, int m, vector<vector<double>> &a, int &ans) {
    int nw = 1;
    for (int j = 1; j <= m; j++) {
        int mxi = nw;
        for (int i = nw; i <= n; i++) {
            if (fabs(a[i][j]) > eps) {mxi = i; break;}    
        }
        if (fabs(a[mxi][j]) < eps) continue;
        if (nw != mxi) swap(a[nw], a[mxi]);
        for (int i = 1; i <= n; i++) {
            if (i == nw) continue;
            double x = a[i][j] / a[nw][j];
            for (int k = j; k <= m; k++) {
                a[i][k] -= x * a[nw][k];
            }
        }
        ans += a[nw][0];
        nw++;
    }
    return nw - 1;
}
    void sol() {
        int n, m;
        cin >> n >> m;
        int ans = 0;
        vector<vector<double>> a(n + 1, vector<double>(m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = 1; i <= n; i++) cin >> a[i][0];
        sort(a.begin() + 1, a.end(), [&](vector<double> &v1, vector<double> &v2){return v1[0] < v2[0];});
        cout << gsyd(n, m, a, ans) << " ";
        cout << ans << "\n";
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
