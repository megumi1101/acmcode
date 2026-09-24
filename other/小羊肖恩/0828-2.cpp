#include <bits/stdc++.h>

using namespace std;

#define int long long

const double eps = 1e-8;

const int mod = 1e9 + 7;
int fap(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void sol() {
    int m;
    cin >> m;

    auto sum = [&] (int l, int r) -> int {
        return (l + r) * (r - l + 1) / 2;
    };

    int l = 1, r = m - 1;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        int coef = m - mid + (m - mid);
        int t = sum(mid + 1, m) - sum(1, mid);
        if (t < mid * coef) {
            r = mid - 1;
        } else if (t >= (mid + 1) * coef) {
            l = mid + 1;
        } else {
            // cout << (double)t / coef << "\n";
            cout << t % mod * fap(coef, mod - 2) % mod << "\n";
            break;
        }
    }
    // double l = 0, r = m;
    // for (int t = 1; t <= 50; t++) {
    //     double mid = (l + r) / 2.0;
    //     double res = 0;
    //     for (int i = 1; i <= m; i++) {
    //         res += fabs(mid - i);
    //     }
    //     res /= m;
    //     l = min(mid, res);
    //     r = max(mid, res);
    // }

    // cout << l << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        sol();
    }
}