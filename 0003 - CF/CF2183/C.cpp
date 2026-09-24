#include <bits/stdc++.h>
 
using namespace std;
 
void sol() {
    int n, m, k;
    cin >> n >> m >> k;
    int lf = k - 1, rt = n - k;
    if (lf > rt) swap(lf, rt);
    m++;
 
    int ans = 1;
    for (int i = 0; i <= lf; i++) {
        int t = m - 2 * i;
        if (t <= 0) break;
        if (t <= i) ans = max(ans, i + 1 + t);
        else ans = max(ans, i + 1 + min (rt, (t + i) / 2));
    }
 
    ans = min(ans, n);
    cout << ans << "\n";
}
 
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
 
    int T;
    cin >> T;
    while (T--) sol();
}
