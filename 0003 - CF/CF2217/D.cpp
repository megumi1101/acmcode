#include <bits/stdc++.h>
 
using namespace std;
 
void sol() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 2), p(k + 2);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= k; i++) cin >> p[i];
    p[0] = 0; p[k + 1] = n + 1;
    int x = a[p[1]];
    if (x == 1) {
        for (int i = 1; i <= n; i++) a[i] ^= 1;
    }
    vector<int> d(n + 2);
    for (int i = 1; i <= n + 1; i++) {
        d[i] = a[i] ^ a[i - 1];
    }
    
    int mx = -1;
    int sum = 0;
    for (int t = 1; t <= k + 1; t++) {
        int res = 0;
        for (int i = p[t - 1] + 1; i <= p[t]; i++) {
            if (d[i]) res++;
        }
        mx = max(res, mx);
        sum += res;
    }
    cout << max(sum / 2, mx) << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) sol();
}
