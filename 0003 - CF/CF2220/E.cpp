#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    {
        string s;
        cin >> s;
        for (int i = 0; i < n; i++) {
            a[i + 1] = s[i] - '0';
        }
    }
    vector ed (n + 1, vector<int>{});
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ed[x].push_back(y);
        ed[y].push_back(x);
    }
 
    vector<array<double, 2>> dp(n + 1);
    [&](this auto &&self, int u, int fat) -> void {
        double res = 0.0;
        double deg = (double)ed[u].size();
        vector<double> diff;
        for (auto v : ed[u]) {
            if (v == fat) continue;
            self(v, u);
            res += dp[v][1];
            diff.push_back(dp[v][0] - dp[v][1]);
        }
        sort(diff.begin(), diff.end());
        if (a[u]) {
            dp[u] = {res, res};
        } else {
            for (int k = 0; k < 2; k++) {
                double tmp = 1e100;
                double sum = res;
                if (k) {
                    tmp = sum + deg; 
                }
                for (int i = 0; i < diff.size(); i++) {
                    sum += diff[i];
                    tmp = min(tmp, sum + deg / (k + i + 1));
                }
                dp[u][k] = tmp;
            }
        }
    } (1, 0);
    cout << fixed << setprecision(9) << dp[1][0] << '\n';
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
/*
1
3
101
1 2
2 3
*/
