#include <bits/stdc++.h>

using namespace std;


signed main() {
    int n;
    cin >> n;
    vector<double> l(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++) cin >> l[i];
    for (int i = 1; i <= n; i++) cin >> r[i];

    double e = 0;
    double e2 = 0;
    for (int i = 1; i <= n; i++) {
        double mxl = max(l[i], l[i - 1]);
        double mnr = min(r[i], r[i - 1]);

        double mul = (r[i] - l[i] + 1) * (r[i - 1] - l[i - 1] + 1);
        double p =  1 - max(mnr - mxl + 1, (double)0) / mul;

        // cout << p << "\n";
        e2 += p * (2 * e + 1);
        e += p;
    }
    cout << e2 << "\n";
    
}

/*
4
-
+ 1
+ 2
-
*/