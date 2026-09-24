#include <bits/stdc++.h>
 
using namespace std;
 
const vector<int> primes = {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 
    59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 
    127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 
    191, 193, 197, 199
};
 
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1), v(n + 1), up(n + 1), fixed(n + 1);
    vector<int> b(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) {
        int d1 = 1;
        int d2 = 1;
        if (i != 1) d1 = gcd(a[i], a[i - 1]);
        if (i != n) d2 = gcd(a[i], a[i + 1]);
        int lc = lcm(d1, d2);
        v[i] = a[i] / lc;
        up[i] = b[i] / lc;
        if (v[i] == up[i] && up[i] == 1) fixed[i] = 1;
        else if (up[i] == 0) fixed[i] = 1;
        else if (v[i] != 1) v[i] = 1, fixed[i] = 1, ans++;
        v[i] = v[i] * lc;
    }
 
    vector<array<int, 4>> pr(n + 1);
    for (int i = 1; i <= n; i++) if (!fixed[i]) {
        int vl = 1, vr = 1;
        if (i - 1 >= 1) vl = v[i - 1];
        if (i + 1 <= n) vr = v[i + 1];
        vl /= gcd(vl, v[i]);
        vr /= gcd(vr, v[i]);
        int cnt = 1;
        // cerr << vl << "  " << vr << "\n";
        for (auto x : primes) {
            if (x > up[i]) {
                break;
            }
            if (vl % x != 0 && vr % x != 0) {
                pr[i][cnt] = x;
                cnt++;
                if (cnt == 4) {
                    break;
                }
            }
        }
    }
    int inf = 1e9;
    array<int, 4> dp{0, 0, 0, 0};
    v[0] = 1;
    fixed[0] = 1;
    // cerr << ans << "\n";
    // cerr << fixed[1] << fixed[2] << fixed[3] << "\n";
    // cerr << pr[1][1] << "\n";
    for (int i = 1; i <= n; i++) if (!fixed[i]) {
        array<int, 4> ndp{0, 0, 0, 0};
        ndp[0] = max({dp[0], dp[1], dp[2], dp[3]});
        if (fixed[i - 1]) {
            for (int u = 1; u < 4; u++) {
                if (!pr[i][u]) {
                    ndp[u] = -inf;
                    continue;
                }
                ndp[u] = ndp[0] + 1; 
            }
        } else {
            for (int u = 1; u < 4; u++) {
                if (!pr[i][u]) {
                    ndp[u] = -inf;
                    continue;
                }
                for (int v = 0; v < 4; v++) {
                    if (pr[i][u] != pr[i - 1][v]) {
                        ndp[u] = max(dp[v] + 1, ndp[u]);
                    }
                }
            }
        }
        dp = move(ndp);
    }
    cout << ans + max({dp[0], dp[1], dp[2], dp[3]}) << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
