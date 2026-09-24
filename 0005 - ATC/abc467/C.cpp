#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(n);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) cin >> b[i];

    auto c = b;
    for (int i = 1; i < n; i++) {
        c[i] = a[i] ^ a[i + 1];
    }
    auto d = c;
    
    int ans = 0;
    {
        int res = 0;
        for (int i = 1; i + 1 < n; i++) {
            if (c[i] != b[i]) {
                c[i] ^= 1;
                c[i + 1] ^= 1;
                res++;
            }
        }
        if (c[n - 1] != b[n - 1]) res++;
        ans = res;
    }
    
    {
        int res = 1;
        c = d;
        c[1] ^= 1;
        for (int i = 1; i + 1 < n; i++) {
            if (c[i] != b[i]) {
                c[i] ^= 1;
                c[i + 1] ^= 1;
                res++;
            }
        }
        if (c[n - 1] != b[n - 1]) res++;
        ans = min(ans, res);
    }
    cout << ans << "\n";
}