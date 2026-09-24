#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    const double eps = 1e-5;  

    while (n--) {
        double x;
        cin >> x;

        double L = 0.0, R = (x > 1.0 ? x : 1.0);
        int cnt = 0;  

        while (1) {
            double mid = (L + R) / 2.0;
            ++cnt;
            if (fabs(mid * mid - x) < eps) break;
            if (mid * mid > x) R = mid;
            else L = mid;
        }

        double ans = (L + R) / 2.0;
        cout << cnt << ' ' << fixed << setprecision(3) << ans << '\n';
    }

    return 0;
}
