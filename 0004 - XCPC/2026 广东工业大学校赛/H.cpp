#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define double long double
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    cout << fixed << setprecision(12);
    vector<double> s(n + 1), b(n + 1);
    vector<double> t(n + 1);
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        s[i] = (double)x;
        b[i] = (double)y;
        if (i > 1) t[i] = t[i - 1] + (s[i] - s[i - 1]) * (60.0 / b[i - 1]);
    }
    int q;
    cin >> q;
    while (q--) {
        string ss;
        double x;
        cin >> ss >> x;
        if (ss[0] == 'B') {
            int pos = --upper_bound(s.begin(), s.end(), x) - s.begin();
            cout << t[pos] + (x - s[pos]) * (60.0 / b[pos]) << "\n";
        } else {
            int pos = --upper_bound(t.begin(), t.end(), x) - t.begin();
            cout << s[pos] + (x - t[pos]) / (60.0 / b[pos]) << "\n";
        }
    }
}
 
/*
1
0 120
4
B 0
B 120
S 60
S 72.5
*/
