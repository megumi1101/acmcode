#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
    #define int long long
    double ans;
    double a[10];
    void sol() {
        int n = 7;
        double res = 1.0;
        double sum = 0.0;
        for (int i = 1; i <= n; i++) cin >> a[i], res *= a[i], sum += a[i];
        double tmp = 1.0;
        for (int i = 0; i < 7; i++) {
            tmp *= sum - 1.0 * (double)i;
        }
        if (tmp) ans = res / tmp * 5040.0 * (sum - 6.0);
        else ans = 0.0;
        cout << fixed << setprecision(3) << ans;
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
/*
1 3
5 4 3
*/