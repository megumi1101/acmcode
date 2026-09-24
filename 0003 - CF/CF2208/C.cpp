#include <bits/stdc++.h>
 
using namespace std;
 
 
void sol() {
    int n;
    cin >> n;
    vector<int> ci(n + 1), pi(n + 1);
    for (int i = 1; i <= n; i++) cin >> ci[i] >> pi[i];
 
    vector<double> c(n + 1), p(n + 1);
    for (int i = 1; i <= n; i++) c[i] =(double)ci[i], p[i] = (double)pi[i];
 
    vector<double> f(n + 1);
    f[n] = c[n];
    for (int i = n - 1; i >= 1; i--) {
        f[i] = max(f[i + 1], f[i + 1] * (1.0 - p[i] / 100.0) + c[i]);
    }
    cout << fixed << setprecision(8) << f[1] << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) sol();
}
