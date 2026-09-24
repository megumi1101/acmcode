#include <bits/stdc++.h>

using namespace std;

namespace Xbbbz {
    #define int long long
    const int N = 1e5 + 10;
    const int mod = 998244353;
    double a[N];
    double b[N];
    double c[N];
    double p[N];
    void sol() {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }
        for (int i = 1; i <= n; i++) {
            a[i] = (a[i - 1] + 1.0) * p[i];
            b[i] = (b[i - 1] + 2.0 * a[i - 1] + 1.0) * p[i];
            c[i] = c[i - 1] + (3 * b[i - 1] + 3 * a[i - 1] + 1.0) * p[i];
        }
        cout << fixed << setprecision(1) << c[n];
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